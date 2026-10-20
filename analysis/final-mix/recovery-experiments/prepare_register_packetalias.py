from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_aliashelpers.py').read_text(encoding='utf-8')
s=s.replace('aliashelpers','packetalias').replace('freshhelpers','aliashelpers')
s=s.replace("['00137458','0013b4b0']","['001337f0','00133980']")
(ex/'register_packetalias.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_aliashelpers_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_packetalias_curated.py').write_text(runner[:start]+"names=['fm_primary_packetalias_recovered_001337f0.cpp','fm_primary_packetalias_recovered_00133980.cpp']"+runner[end:],encoding='utf-8')
