from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_packetalias.py').read_text(encoding='utf-8')
s=s.replace('packetalias','virtualguard').replace('aliashelpers','packetalias')
s=s.replace("['001337f0','00133980']","['0013e5a8']")
(ex/'register_virtualguard.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_packetalias_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_virtualguard_curated.py').write_text(runner[:start]+"names=['fm_primary_virtualguard_recovered_0013e5a8.cpp']"+runner[end:],encoding='utf-8')
