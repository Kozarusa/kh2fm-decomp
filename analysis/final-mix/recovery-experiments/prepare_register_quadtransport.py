from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_virtualguard.py').read_text(encoding='utf-8')
s=s.replace('virtualguard','quadtransport').replace('packetalias','virtualguard')
s=s.replace("['0013e5a8']","['0013f828','00140850']")
(ex/'register_quadtransport.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_virtualguard_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_quadtransport_curated.py').write_text(runner[:start]+"names=['fm_primary_quadtransport_recovered_0013f828.cpp','fm_primary_quadtransport_recovered_00140850.cpp']"+runner[end:],encoding='utf-8')
