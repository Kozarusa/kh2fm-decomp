from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_quadtransport.py').read_text(encoding='utf-8')
s=s.replace('quadtransport','bytewrapper').replace('virtualguard','quadtransport')
s=s.replace("['0013f828','00140850']","['0014e140']")
(ex/'register_bytewrapper.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_quadtransport_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_bytewrapper_curated.py').write_text(runner[:start]+"names=['fm_primary_bytewrapper_recovered_0014e140.cpp']"+runner[end:],encoding='utf-8')
