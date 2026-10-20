from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_bytewrapper.py').read_text(encoding='utf-8')
s=s.replace('bytewrapper','globalargument').replace('quadtransport','bytewrapper')
s=s.replace("['0014e140']","['0014f578']")
(ex/'register_globalargument.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_bytewrapper_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalargument_curated.py').write_text(runner[:start]+"names=['fm_primary_globalargument_recovered_0014f578.cpp']"+runner[end:],encoding='utf-8')
