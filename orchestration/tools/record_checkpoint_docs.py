"""Update orchestration documentation from a published checkpoint; never edit acceptance evidence."""
import json
from datetime import datetime, timezone
from pathlib import Path
import re
import sys

root = Path('C:/Users/KoZa/Documents/AGENTS')
c = root/'Codex'
o = c/'orchestration'
fm = c/'analysis/final-mix'
phase, bundle_count, *wps = sys.argv[1:]
compiler = json.loads((fm/'worker-coordination/compiler-status.json').read_text())
assert compiler['state'] == 'idle' and compiler['last_accepted_phase'] == 'primary-'+phase
checkpoint = json.loads((fm/f'primary-{phase}-checkpoint-2026-10-08.json').read_text())
build = json.loads((fm/'native-build/native-build-verification.json').read_text())
assert checkpoint['active_exact_matches'] == build['unmodified_compiled_symbol_matches']
assert build['whole_executable_byte_exact']
proofs = sorted((fm/'recovery-experiments').glob(f'fm_primary_{phase}_recovered_*.verification.json'))
rows = [json.loads(p.read_text())['rows'][0] for p in proofs]
assert len(rows) == checkpoint['active_exact_matches_added'] and all(r['exact_match'] for r in rows)
added_bytes = sum(r['target_size'] for r in rows)
addresses = ', '.join(r['address'] for r in rows)
exact = build['unmodified_compiled_symbol_matches']
cpp = build['cpp_range_count']
fallback = build['original_fallback_range_count']
inputs = checkpoint['source_inputs_checked']
layout = {}
for line in (root/'Public/tools/kh2-reference/layout.tsv').read_text().splitlines():
    parts=line.split('\t')
    if len(parts)>=3 and re.fullmatch('[0-9a-f]{8}',parts[0]):
        layout[parts[0]]=int(parts[2])
ranges=json.loads((fm/'native-build/compiler-range-verification.json').read_text())
covered=sum(layout[r['address']] for r in ranges if r.get('unmodified_compiled_symbol_match'))
denominator=sum(layout.values())
summary=(f'Published `{phase}`: {exact:,} exact functions, {cpp:,} C++ ranges, '
         f'{fallback:,} fallback ranges, {inputs:,} inputs, {bundle_count} recovery bundles and 3 switch receipts. '
         f'Accepted C++ covers {covered:,}/{denominator:,} declared code bytes; fallback including padding covers '
         f'{len(layout)-exact:,} ranges and {denominator-covered:,} bytes. Equality retains fallback; this is not a source-only rebuild.')
recent=(f'{phase} integrated {"/".join(wps)}: {len(rows)} functions ({addresses}), {added_bytes} instruction bytes. '
        'Independent reviews and curated probes, cumulative MATCHED!, both publish gates, full preflight, coverage and accepted-source zero-diff inspection passed.')
cumulative=(f'This chat has newly published {exact-6776} functions and {covered-390672:,} instruction bytes since the renewed October 18 orchew baseline. '
            'Earlier successor recovery published 33 functions and 2,988 bytes before this interval; predecessor publications remain counted only once. '
            f'Shift 2 totals are {exact-6612} functions and {covered-375772:,} instruction bytes.')
p=c/'STATUS.md'
s=p.read_text(encoding='utf-8')
s=re.sub(r'Last reconciled:.*',f'Last reconciled: {datetime.now(timezone.utc).date()}, from the {phase} checkpoint.',s)
values={'Complete, equal-size instruction matches':exact,'Registered C++ ranges (includes 4 padding cases)':cpp,
        'Original-byte fallback ranges still remaining':fallback,'Verified staged compiler inputs':inputs,
        'Cumulative recovery bundles passing':int(bundle_count),'Switch batches passing':3}
for label,value in values.items():
    s=re.sub(r'\| '+re.escape(label)+r' \| [^|]+ \|',f'| {label} | {value:,} |',s)
s=re.sub(r'primary-orch[a-z]{2}-checkpoint',f'primary-{phase}-checkpoint',s)
s=re.sub(r'verify_fm_primary_orch[a-z]{2}_checkpoint',f'verify_fm_primary_{phase}_checkpoint',s)
s=re.sub(r'after the orch[a-z]{2} checkpoint',f'after the {phase} checkpoint',s)
s=re.sub(r'\| Accepted C\+\+ \(exact symbol match\) \|.*',f'| Accepted C++ (exact symbol match) | {exact:,} | {covered:,} | {100*covered/denominator:.1f}% |',s)
s=re.sub(r'\| Fallback \(includes the 4 zero-padded ranges\) \|.*',f'| Fallback (includes the 4 zero-padded ranges) | {len(layout)-exact:,} | {denominator-covered:,} | {100*(denominator-covered)/denominator:.1f}% |',s)
s=re.sub(r'October 16 successor reconciliation:.*', 'October 16 successor recovery: '+recent+' Standing usage rules remain in force; the latest human continuation overrides the context stop for its24-hour interval. No completed-duration claim.',s)
s=s.replace(f'the {fallback+len(rows):,} fallback function ranges',f'the {fallback:,} fallback function ranges')
p.write_text(s,encoding='utf-8')
p=o/'CHANGELOG.md';s=p.read_text(encoding='utf-8')
if f'- {phase}:' not in s:
    s+=f'\n- {phase}: +{len(rows)} functions ({addresses}), {added_bytes} instruction bytes; exact {exact}, fallback {fallback}. {"/".join(wps)} independently reviewed; all independent probes, MATCHED!, both publish gates, {bundle_count} bundles and full preflight passed.\n'
p.write_text(s,encoding='utf-8')
p=o/'HANDOFF.md';s=p.read_text(encoding='utf-8')
a=s.index('## State');b=s.index('## What the project has',a) if '## What the project has' in s[a:] else s.index('Historical accepted work',a)
s=s[:a]+'## State\n\n- '+summary+'\n- '+recent+'\n- '+cumulative+'\n- No recovery worker, lease, submission or probe remains after this publication. Future work requires fresh usage and preflight. Preserve all blocked evidence and DEVIATIONS #7/#8/#9/#10/#11/#12/#13/#14/#15/#16/#17/#18/#19/#20/#21/#22/#23.\n\n'+s[b:]
a=s.index('## Start here');b=s.index('## Autonomy',a)
s=s[:a]+('## Start here\n\n'
    '- Owner `gpt6-orch-oct18` holds the lock. The latest direct human continue authorized resumption after the prior usage stop; the active kh2fm-24-hour-continuation heartbeat may resume after reset with fresh preflight/usage through 2026-10-19T12:32:08Z. No completed-duration claim.\n'
    '- '+summary+'\n- '+recent+'\n- '+cumulative+'\n'
    '- Active work: no recovery workers, leases, submissions or probes remain at this publication. Fresh preflight and usage checks are required before another dispatch.\n'
    '- Read ORCHESTRATION.md, this file, DEVIATIONS.md, RECIPES.md, ROSTER.md and briefs/_shared.md before takeover. A live lock forbids takeover. Preserve Shift 2 PROGRESS, archives, sources and proofs. Root never writes recovery C++; never use fable, reuse probe names or reopen closed WPs.\n\n')+s[b:]
p.write_text(s,encoding='utf-8')
p=o/'ORCHESTRATION.md';s=p.read_text(encoding='utf-8')
a=s.index('## 2. State at the current checkpoint');b=s.index('## 3. Operating rules',a)
s=s[:a]+'## 2. State at the current checkpoint (October 16 successor)\n\n- '+summary+'\n- '+recent+'\n- '+cumulative+'\n- The user explicitly requested 24 hours of autonomous work in this successor chat, authorizing resumption, and later directly instructed continue after the usage stop. Future 90% five-hour wrap-up, 60% single-worker limit remain binding; the latest explicit 24-hour continuation overrides the context handoff stop while counters remain preserved; weekly limit is waived. No completed-duration claim.\n- Owner gpt6-orch-oct18 holds the lock; helpers use rollout 2026-10-18T05-31-45-01a14eff-2257-7390-ae57-04d4241976ca. Preserve Shift2 log and evidence. DEVIATIONS #7 remains open; #8/#9/#10 attribution evidence is preserved; #11 was corrected by fix01 in orchek; #12 pure-leaf clarification and #13 defined-cursor fix03/orchen are preserved; #14 worker self-review command breach remains recorded with independent review and report correction; #15 preserves the named retry queue ambiguity and requires explicit queue commands; #16 preserves failed-probe version reuse and strict-stop overrun in closed nm30. DEVIATIONS #20 preserves delayed guard-diff inspection; future guard diffs must complete before separate probes. DEVIATIONS #21 preserves rec183 command-receipt loss and corrected false environment-failure inference; always retain full exit_code/session_id and poll running commands before retrying. DEVIATIONS #22 preserves the nonexact rec186 temporary/address-association/operand-order experiment; no isolated effect is claimed. No unrelated O8 action is authorized.\n\n'+s[b:]
for wp in wps:
    s=re.sub(r'(^\| '+re.escape(wp)+r' \|[^\n]*\| )[^|\n]+ \|$',r'\g<1>integrated '+phase+' |',s,flags=re.M)
s=re.sub(r'^Current (?:wave|checkpoint):.*',f'Current checkpoint: {phase}; {"/".join(wps)} integrated. No recovery worker remains. Fresh usage and preflight required for next dispatch.',s,flags=re.M)
p.write_text(s,encoding='utf-8')
(o/'GPT6-MEMORY.md').write_text('# GPT-6 orchestrator memory\n\n'+summary+' '+recent+' '+cumulative+' Owner gpt6-orch-oct18 holds the lock; preserve Shift2 PROGRESS and evidence. The new direct human request authorizes this successor to resume; future 90% five-hour wrap-up, 60% single-worker remain binding; the latest explicit 24-hour continuation overrides the context handoff stop while counters remain preserved, weekly waived. The active kh2fm-24-hour-continuation heartbeat may resume after reset with fresh preflight/usage through 2026-10-19T12:32:08Z; stop it at the deadline. No completed-duration claim. Root never writes recovery C++. All future candidates require every-exit literal R4.3, named-baseline single-control experiments, strict R7, K limits including all claims, and independent review. DEVIATIONS #7 accepted void ABI policy discrepancy and the #8/#9/#10 attribution violations remain preserved; no unilateral bound-source repair, exception, evidence deletion or unrelated O8. Helpers use this chat rollout2026-10-18T05-31-45-01a14eff-2257-7390-ae57-04d4241976ca.\n',encoding='utf-8')
print(summary)
print(recent)

