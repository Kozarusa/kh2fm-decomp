"""Mechanical review of one work package (read-only except for its own report file).

  python -I review_wp.py WP_DIR WP_START_UTC
      WP_DIR        the work package directory, e.g. ...\\recovery-experiments\\orch-shift1\\rec01
      WP_START_UTC  ISO time the WP was spawned, e.g. 2026-10-12T15:00:00Z (from PROGRESS.md)

Checks every queue submission whose source lives in WP_DIR, plus project hygiene and files changed outside the
WP since it started. Writes WP_DIR/review-auto-<n>.json and prints PASS/FAIL/FLAG lines. Exit code 0 only when
no FAIL exists. FLAG items need the reviewer agent's judgement; FAIL items are never integrated.
"""
import hashlib
import json
import re
import sqlite3
import sys
from datetime import datetime
from pathlib import Path

AGENTS = Path('C:/Users/KoZa/Documents/AGENTS')
CODEX = AGENTS / 'Codex'
AREA = CODEX / 'analysis/final-mix'
REFERENCE = AGENTS / 'Public/tools/kh2-reference'
QUEUE_DB = AREA / 'worker-coordination/recovery-queue.sqlite3'
ELF_SHA = 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
ALLOWED_INCLUDES = {'../common/types.h', '../kn/fvector.hpp'}
GHIDRA_NAMES = re.compile(r'\b(?:iVar|uVar|lVar|puVar|piVar|pcVar|bVar|cVar|sVar|fVar|param_)\d+\b|\bDAT_[0-9a-f]+|\bFUN_[0-9a-f]+|\bundefined\d*\b')
DEFINITION = re.compile(r'^\s*(?:[\w:*&]+\s+)+[*&]*func_([0-9a-f]{8})\([^;{}]*\)\s*\{', re.M)
ASM = re.compile(r'\b(?:__asm__|asm)\s*(?:__volatile__|volatile)?\s*\(\s*"((?:\\.|[^"\\])*)"')


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def layout_sizes():
    sizes = {}
    for line in (REFERENCE / 'layout.tsv').read_text().splitlines():
        parts = line.split('\t')
        if len(parts) >= 3 and re.fullmatch('[0-9a-f]{8}', parts[0]):
            sizes[parts[0]] = int(parts[2])
    return sizes


def legacy_assembly_symbols():
    """func_ symbols defined in legacy .s files outside their own .text.func_<address> section.

    Those are linked at temporary addresses, so a C++ call through func_<address> lands in the wrong place in the
    full build even though the isolated probe matches (queueepsilonprime, func_00139768). Wrappers that sit in
    their own .text.func_<address> section (syscall_wrappers.s) are placed natively and are safe.
    """
    found = set()
    for path in (REFERENCE / 'src').rglob('*.s'):
        text = path.read_text(errors='replace')
        for symbol in re.findall(r'\.globl\s+func_([0-9a-f]{8})', text):
            if f'.text.func_{symbol}' not in text:
                found.add(symbol)
    return found


def check_source(address, source, results):
    text = source.read_text(errors='replace')
    definitions = DEFINITION.findall(text)
    if definitions != [address]:
        results.append(('FAIL', address, f'source must define exactly one function, func_{address}; found {definitions}'))
    first = DEFINITION.search(text)
    if first:
        lexical = re.sub(r'"(?:\\.|[^"\\])*"|\x27(?:\\.|[^\x27\\])*\x27|//[^\n]*|/\*.*?\*/',
                         lambda m: ' ' * len(m.group()), text, flags=re.S)
        depth, end = 1, first.end()
        while depth and end < len(lexical):
            depth += (lexical[end] == '{') - (lexical[end] == '}')
            end += 1
        if lexical[end:].strip():
            results.append(('FAIL', address, 'code or declarations after the function body (the curator drops them); move declarations above the function'))
    for include in re.findall(r'#\s*include\s*[<"]([^>"]+)[>"]', text):
        if include not in ALLOWED_INCLUDES:
            results.append(('FAIL', address, f'include not allowed: {include}'))
    names = sorted(set(GHIDRA_NAMES.findall(text)))
    if names:
        results.append(('FAIL', address, f'raw Ghidra names in source: {names[:8]}'))
    for referenced in sorted(set(re.findall(r'\bfunc_([0-9a-f]{8})\b', text)) & LEGACY):
        results.append(('FAIL', address, f'func_{referenced} is defined in legacy assembly; call it through D_{referenced}'))
    emitted = 0
    lines = text.splitlines()
    for match in ASM.finditer(text):
        body = match.group(1)
        if re.fullmatch(r'\$f?\d+', body.strip()):
            continue  # register binding such as asm("$15") or asm("$f0"); not emitted code
        if re.search(r'\.(?:word|half|byte|incbin|dword|quad|space)\b', body):
            results.append(('FAIL', address, 'raw data directive inside asm (pasted encoding is forbidden)'))
        if re.search(r'\$(?!f\d|vf\d|vi\d)[a-z]', body):
            results.append(('FAIL', address, 'symbolic register name in asm; use numeric names such as $15'))
        instructions = [part for part in re.split(r'[;\n]|\\n', body) if part.strip() and not part.strip().startswith('.set')]
        if instructions:
            # VU0 macro-mode operations cannot be produced by the compiler; they are counted separately.
            emitted += sum(not re.match(r'\s*(?:v\w+|lqc2|sqc2|qmtc2|qmfc2|ctc2|cfc2)\b', part) for part in instructions)
            line_number = text.count('\n', 0, match.start())
            window = '\n'.join(lines[max(0, line_number - 2):line_number + 1])
            if 'why:' not in window.lower():
                results.append(('FLAG', address, f'emitted asm without a "why:" comment on the same or previous two lines: "{body[:60]}"'))
    for register in re.findall(r'\basm\s*\(\s*"(\$(?!f\d)[a-z][a-z0-9]*)"\s*\)', text):
        results.append(('FAIL', address, f'symbolic register binding {register}; use numeric names such as $15'))
    if emitted > 3:
        results.append(('FLAG', address, f'{emitted} emitted non-VU asm instructions; reviewer must confirm these are narrow primitives, not a pasted body'))
    if not re.fullmatch(r'orch\d+_[a-z0-9]+_[0-9a-f]{8}_v\d+', source.stem):
        results.append(('FLAG', address, f'source name {source.name} does not follow orch<shift>_<wp>_<address>_v<n>.cpp'))


def outside_changes(wp_dir, start):
    watched = [REFERENCE / 'functions.tsv', REFERENCE / 'layout.tsv', REFERENCE / 'SLPM_666.75']
    watched += list((REFERENCE / 'src').rglob('*'))
    watched += list((AGENTS / 'Public/tools/kh2-audit').glob('*'))
    watched += [p for p in AREA.glob('*') if p.is_file()]
    watched += list((AREA / 'native-build').glob('*'))
    watched += [p for p in (AREA / 'worker-coordination').glob('*') if not p.name.startswith('recovery-queue.sqlite3')]
    watched += list(CODEX.glob('*.md')) + list((CODEX / 'orchestration').glob('*.md')) + list((CODEX / 'orchestration/briefs').glob('*'))
    watched += list((CODEX / 'orchestration/tools').glob('*'))
    changed = []
    for path in watched:
        if path.is_file() and path.stat().st_mtime > start and not path.resolve().is_relative_to(wp_dir):
            changed.append(path.relative_to(AGENTS).as_posix())
    return changed


def main():
    if len(sys.argv) != 3:
        raise SystemExit(__doc__)
    wp_dir = Path(sys.argv[1]).resolve()
    start = datetime.fromisoformat(sys.argv[2].replace('Z', '+00:00')).timestamp()
    assert wp_dir.is_dir() and wp_dir.is_relative_to(AREA / 'recovery-experiments'), 'WP_DIR must be inside recovery-experiments'
    original = (REFERENCE / 'SLPM_666.75').read_bytes()
    assert hashlib.sha256(original).hexdigest() == ELF_SHA
    sizes = layout_sizes()
    db = sqlite3.connect(f'file:{QUEUE_DB.as_posix()}?mode=ro', uri=True)
    try:
        rows = db.execute("SELECT address,owner,metadata,artifacts FROM targets WHERE state='submitted'").fetchall()
    finally:
        db.close()
    results = []
    reviewed = []
    for address, owner, metadata, artifacts in rows:
        art = json.loads(artifacts)
        source, proof = Path(art['source']).resolve(), Path(art['proof']).resolve()
        if not source.is_relative_to(wp_dir):
            continue
        reviewed.append(address)
        if not source.exists() or not proof.exists():
            results.append(('FAIL', address, 'submitted source or proof file is missing'))
            continue
        if digest(source) != art['source_sha256'] or digest(proof) != art['proof_sha256']:
            results.append(('FAIL', address, 'source or proof changed after submission'))
        data = json.loads(proof.read_text())
        if data.get('source_sha256') != digest(source):
            results.append(('FAIL', address, 'proof was not produced from this exact source'))
        proof_rows = data.get('rows', [])
        if len(proof_rows) != 1 or proof_rows[0]['address'] != address:
            results.append(('FAIL', address, 'proof must contain exactly one row, for this address'))
            continue
        row = proof_rows[0]
        size = sizes.get(address, json.loads(metadata)['bytes'])
        offset = int(address, 16) - 0x100000 + 0x1000
        target = original[offset:offset + size]
        compiled = bytes.fromhex(row['compiled_hex'])
        if not (row['exact_match'] and row['compiled_size'] == row['target_size'] == size and compiled == target):
            results.append(('FAIL', address, f'not a complete equal-size match against the original ELF ({row["compiled_size"]}/{size} bytes)'))
        check_source(address, source, results)
        if not any(r[1] == address and r[0] == 'FAIL' for r in results):
            results.append(('PASS', address, f'{size} bytes exact; source {source.name}'))
    blocked = sorted(p.name for p in wp_dir.glob('*-BLOCKED.md'))
    changed = outside_changes(wp_dir, start)
    for path in changed:
        results.append(('FLAG', '-', f'changed outside the WP since it started (check who changed it): {path}'))
    if not reviewed:
        results.append(('FLAG', '-', 'no submitted proposals from this WP are awaiting integration'))
    n = 1
    while (wp_dir / f'review-auto-{n}.json').exists():
        n += 1
    report = {'wp_dir': str(wp_dir), 'start': sys.argv[2], 'reviewed': reviewed, 'blocked_reports': blocked,
              'results': [{'level': a, 'address': b, 'detail': c} for a, b, c in results]}
    (wp_dir / f'review-auto-{n}.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    for level, address, detail in results:
        print(f'{level:<4} {address:<8} {detail}')
    print(f'Blocked reports: {len(blocked)}. Saved: {wp_dir / f"review-auto-{n}.json"}')
    sys.exit(1 if any(level == 'FAIL' for level, _, _ in results) else 0)


LEGACY = legacy_assembly_symbols()

if __name__ == '__main__':
    main()
