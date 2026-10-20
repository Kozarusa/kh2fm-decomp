"""Orchestrator helper (read-only except mark-integrating).

  python -I orch.py next-phase     print the previous accepted phase and the next unused phase name
  python -I orch.py state          print the accepted-state numbers for STATUS.md from the saved build records
  python -I orch.py leases         print queue pause state and live leases (read-only; does not reap)
  python -I orch.py lock acquire|heartbeat|release OWNER   the single-orchestrator lock (OWNER e.g. cld-orch)
  python -I orch.py lock status                            who holds it, heartbeat age, stale flag
  python -I orch.py mark-integrating PHASE
                                   the one write: set compiler-status.json to integrating before O3 step 5
                                   (publish_fm_queue_batch.py sets it back to idle). Writes UTF-8 without BOM,
                                   which the publish script requires.

Phase names for this orchestration are orchaa, orchab, ... orchaz, orchba, ... (lowercase letters only, as the
acceptance scripts require). A name is "used" as soon as any file anywhere in recovery-experiments or kh2-audit
contains it, including failed or abandoned attempts. Used names are never reused.
"""
import itertools
import json
import sqlite3
import string
import sys
import time
from pathlib import Path

AGENTS = Path('C:/Users/KoZa/Documents/AGENTS')
AREA = AGENTS / 'Codex/analysis/final-mix'
AUDIT = AGENTS / 'Public/tools/kh2-audit'
QUEUE_DB = AREA / 'worker-coordination/recovery-queue.sqlite3'


def used(name):
    places = [AREA / 'recovery-experiments', AUDIT, AREA / 'native-build', AREA / 'accepted-snapshots']
    return any(any(place.glob(f'*{name}*')) for place in places if place.exists())


def next_phase():
    compiler = json.loads((AREA / 'worker-coordination/compiler-status.json').read_text(encoding='utf-8-sig'))
    previous = compiler['last_accepted_phase'].removeprefix('primary-')
    for first, second in itertools.product(string.ascii_lowercase, repeat=2):
        name = f'orch{first}{second}'
        if not used(name):
            print(json.dumps({'previous': previous, 'next': name,
                              'compiler_state': compiler.get('state'), 'compiler_phase': compiler.get('phase')}, indent=2))
            return
    raise SystemExit('All orchXX names used; extend the scheme in ORCHESTRATION.md first')


def state():
    compiler = json.loads((AREA / 'worker-coordination/compiler-status.json').read_text(encoding='utf-8-sig'))
    phase = compiler['last_accepted_phase'].removeprefix('primary-')
    checkpoint = sorted(AREA.glob(f'primary-{phase}-checkpoint-*.json'))[-1]
    data = json.loads(checkpoint.read_text())
    build = json.loads((AREA / 'native-build/native-build-verification.json').read_text())
    print(json.dumps({
        'phase': phase,
        'checkpoint': f'analysis/final-mix/{checkpoint.name}',
        'gate': f'python Public/tools/kh2-audit/verify_fm_primary_{phase}_checkpoint.py',
        'exact_matches': data['active_exact_matches'],
        'added_by_this_batch': data['active_exact_matches_added'],
        'cpp_ranges': build['cpp_range_count'],
        'fallback_ranges': build['original_fallback_range_count'],
        'staged_inputs': data['source_inputs_checked'],
        'whole_executable_byte_exact': build['whole_executable_byte_exact'],
    }, indent=2))


def leases():
    db = sqlite3.connect(f'file:{QUEUE_DB.as_posix()}?mode=ro', uri=True)
    try:
        paused = db.execute("SELECT value FROM control WHERE key='paused'").fetchone()[0]
        rows = db.execute("SELECT address,owner,expires FROM targets WHERE state='leased' ORDER BY expires").fetchall()
        submitted = db.execute("SELECT address,owner FROM targets WHERE state='submitted' ORDER BY address").fetchall()
    finally:
        db.close()
    now = time.time()
    slots = sorted(p.name for p in (AGENTS / 'Codex/orchestration/locks').glob('probe-slot-*.lock'))
    print(json.dumps({'paused': paused, 'probe_slots_in_use': slots,
                      'leases': [{'address': a, 'owner': o, 'seconds_left': round(e - now)} for a, o, e in rows],
                      'submitted_awaiting_integration': [{'address': a, 'owner': o} for a, o in submitted]}, indent=2))


LOCK = AGENTS / 'Codex/orchestration/locks/ORCHESTRATOR.lock'
LOCK_STALE_SECONDS = 1800


def lock(action, owner=None):
    """Only one orchestrator may integrate. Heartbeat at every PROGRESS line; stale after 30 minutes."""
    import os
    LOCK.parent.mkdir(parents=True, exist_ok=True)
    current = json.loads(LOCK.read_text()) if LOCK.exists() else None
    age = time.time() - LOCK.stat().st_mtime if current else None
    if action == 'status':
        print(json.dumps({'held': current is not None, 'owner': current and current['owner'],
                          'seconds_since_heartbeat': age and round(age), 'stale': bool(current and age > LOCK_STALE_SECONDS)}, indent=2))
        return
    assert owner, 'owner required'
    if action == 'acquire':
        if current and current['owner'] != owner and age <= LOCK_STALE_SECONDS:
            raise SystemExit(f'Orchestrator lock held by {current["owner"]} (heartbeat {round(age)} s ago). Do not integrate; work as a worker or stop.')
        if current:
            LOCK.unlink()
        descriptor = os.open(LOCK, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
        os.write(descriptor, json.dumps({'owner': owner, 'since': time.time()}).encode())
        os.close(descriptor)
        print(f'acquired by {owner}')
    elif action in ('heartbeat', 'release'):
        if not current or current['owner'] != owner:
            raise SystemExit(f'Lock is not held by {owner}')
        if action == 'heartbeat':
            os.utime(LOCK)
            print('ok')
        else:
            LOCK.unlink()
            print('released')


def mark_integrating(phase):
    assert phase.isalpha() and phase.islower(), 'phase must be lowercase letters'
    path = AREA / 'worker-coordination/compiler-status.json'
    data = json.loads(path.read_text(encoding='utf-8-sig'))
    data.update(owner='primary', state='integrating', status='integrating', phase=f'{phase}-integrating',
                coordination='Exclusive integration in progress; no probes, no claims.')
    path.write_bytes((json.dumps(data, indent=2) + '\n').encode('utf-8'))
    print(json.dumps(data, indent=2))


if __name__ == '__main__':
    commands = {'next-phase': next_phase, 'state': state, 'leases': leases}
    if len(sys.argv) == 3 and sys.argv[1] == 'mark-integrating':
        mark_integrating(sys.argv[2])
    elif len(sys.argv) in (3, 4) and sys.argv[1] == 'lock' and sys.argv[2] in ('acquire', 'heartbeat', 'release', 'status'):
        lock(sys.argv[2], sys.argv[3] if len(sys.argv) == 4 else None)
    elif len(sys.argv) == 2 and sys.argv[1] in commands:
        commands[sys.argv[1]]()
    else:
        raise SystemExit(__doc__)
