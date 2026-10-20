"""Run mandatory native checks and refresh the selected continuation's receipts."""
from pathlib import Path
import subprocess
import sys

stage = Path('/root/kh2fm-build')
workspace = Path('/mnt/c/Users/KoZa/Documents/ChatGPT')
audit = workspace / 'tools/kh2-audit'
batch = sys.argv[1] if len(sys.argv) > 1 else 'primary-matrix'
assert batch in ('primary-matrix', 'worker-b-initializers', 'primary-resume', 'primary-width', 'primary-near', 'primary-close', 'primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments')
log = workspace / f'analysis/final-mix/native-build/{batch}-final-checks.log'

commands = [
    [sys.executable, str(audit / 'check_native_build.py'), str(stage), str(workspace / 'tools/kh2-reference')],
    [sys.executable, 'tools/objdiff.py', 'report', '--elf', 'kh2.elf'],
    [sys.executable, str(audit / 'save_fm_native_checkpoint.py')],
]
bundles = ['scalar-curated-bundle', 'scalar-extra-curated-bundle',
             'autonomous-curated-bundle', 'followup-complete-bundle',
             'last-window-curated-bundle', 'oct7-complete-curated-bundle',
             'oct7-clamp-curated-bundle', 'primary-matrix-curated-bundle']
if batch in ('worker-b-initializers', 'primary-resume', 'primary-width', 'primary-near', 'primary-close', 'primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('worker-b-initializers-curated-bundle')
if batch in ('primary-resume', 'primary-width', 'primary-near', 'primary-close', 'primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-resume-curated-bundle')
if batch in ('primary-width', 'primary-near', 'primary-close', 'primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-width-curated-bundle')
if batch in ('primary-near', 'primary-close', 'primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-near-curated-bundle')
if batch in ('primary-close', 'primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-close-curated-bundle')
if batch in ('primary-transport', 'primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-transport-curated-bundle')
if batch in ('primary-schedule', 'primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-schedule-curated-bundle')
if batch in ('primary-argument', 'primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-argument-curated-bundle')
if batch in ('primary-structure', 'primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-structure-curated-bundle')
if batch in ('primary-packet', 'primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-packet-curated-bundle')
if batch in ('primary-animation', 'primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-animation-curated-bundle')
if batch in ('primary-floatload', 'primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-floatload-curated-bundle')
if batch in ('primary-oneword', 'primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-oneword-curated-bundle')
if batch in ('primary-twoword', 'primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-twoword-curated-bundle')
if batch in ('primary-twowordnext', 'primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-twowordnext-curated-bundle')
if batch in ('primary-order', 'primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-order-curated-bundle')
if batch in ('primary-threeword', 'primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-threeword-curated-bundle')
if batch in ('primary-transportnext', 'primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-transportnext-curated-bundle')
if batch in ('primary-addresspair', 'primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-addresspair-curated-bundle')
if batch in ('primary-floatpacket', 'primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-floatpacket-curated-bundle')
if batch in ('primary-threewordnext', 'primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-threewordnext-curated-bundle')
if batch in ('primary-capacity', 'primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-capacity-curated-bundle')
if batch in ('primary-fourword', 'primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-fourword-curated-bundle')
if batch in ('primary-workertwo', 'primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-workertwo-curated-bundle')
if batch in ('primary-twowordfresh', 'primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-twowordfresh-curated-bundle')
if batch in ('primary-clearsequence', 'primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-clearsequence-curated-bundle')
if batch in ('primary-fourwordfresh', 'primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-fourwordfresh-curated-bundle')
if batch in ('primary-fourwordnext', 'primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-fourwordnext-curated-bundle')
if batch in ('primary-fiveword', 'primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-fiveword-curated-bundle')
if batch in ('primary-sixword', 'primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-sixword-curated-bundle')
if batch in ('primary-sixwordnext', 'primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-sixwordnext-curated-bundle')
if batch in ('primary-workerthree', 'primary-floatarguments'):
    bundles.append('primary-workerthree-curated-bundle')
if batch == 'primary-floatarguments':
    bundles.append('primary-floatarguments-curated-bundle')
for name in bundles:
    commands.append([sys.executable, str(audit / 'verify_fm_scalar_native_bundle.py'),
                     str(workspace / f'analysis/final-mix/recovery-experiments/{name}.json')])
for name in ('switch-helpers', 'switch-byte'):
    commands.append([sys.executable, str(audit / 'verify_fm_native_switch_tables.py'), name])
with log.open('w') as output:
    for command in commands:
        output.write(' '.join(command) + '\n')
        output.flush()
        subprocess.run(command, cwd=stage, stdout=output, stderr=subprocess.STDOUT, check=True)
print(f'Native checks, saved artifacts, {len(bundles)} recovery bundles, and two switch receipts passed.')
