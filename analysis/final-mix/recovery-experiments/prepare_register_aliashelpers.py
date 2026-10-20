from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_freshhelpers.py').read_text(encoding='utf-8')
s=s.replace('freshhelpers','aliashelpers').replace('tablelookup','freshhelpers')
s=s.replace("['001367e0','0013c7d0']","['00137458','0013b4b0']")
(ex/'register_aliashelpers.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_freshhelpers_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_aliashelpers_curated.py').write_text(runner[:start]+"names=['fm_primary_aliashelpers_recovered_00137458.cpp','fm_primary_aliashelpers_recovered_0013b4b0.cpp']"+runner[end:],encoding='utf-8')
