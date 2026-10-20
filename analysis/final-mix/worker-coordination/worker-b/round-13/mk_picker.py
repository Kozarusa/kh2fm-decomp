import json, re, os

os.chdir("C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b")
src = open('round-12/pick_targets.py').read()

addrs = []
for r in os.listdir('.'):
    if re.match(r'round-\d+$', r):
        c = os.path.join(r, 'claim.json')
        if os.path.exists(c):
            d = json.load(open(c))
            for k, v in d.items():
                if k.endswith('addresses') and isinstance(v, list):
                    for e in v:
                        addrs.append(str(e.get('address') if isinstance(e, dict) else e).lower())

new = ' '.join(sorted(set(addrs)))
marker = '001050d8 0016fac8 00171810"""'
assert marker in src
src = src.replace(marker, marker[:-3] + ' ' + new + '"""')
src = src.replace('"""Round-12 target picker.', '"""Round-13 target picker.')
src = src.replace('every worker-b address ever attempted (rounds 1-11)',
                  'every worker-b address ever attempted (rounds 1-12, harvested from the round claims)')
open('round-13/pick_targets.py', 'w').write(src)
print(len(set(addrs)), 'addresses harvested')