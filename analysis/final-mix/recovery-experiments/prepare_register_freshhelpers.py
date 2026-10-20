from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_tablelookup.py').read_text(encoding='utf-8')
s=s.replace('tablelookup','freshhelpers').replace('mediumcall','tablelookup')
s=s.replace("['00132f38']","['001367e0','0013c7d0']")
(ex/'register_freshhelpers.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_tablelookup_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_freshhelpers_curated.py').write_text(runner[:start]+"names=['fm_primary_freshhelpers_recovered_001367e0.cpp','fm_primary_freshhelpers_recovered_0013c7d0.cpp']"+runner[end:],encoding='utf-8')
