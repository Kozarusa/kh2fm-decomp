from pathlib import Path
ex=Path(__file__).resolve().parent
source=(ex/'fm_primary_maskcopy_v2_00158548_2.cpp').read_text(encoding='utf-8')
source=source.replace('struct Masks { u64 reserved[2]; u64 values[256]; };\n','').replace('extern "C" Masks D_0034a970;', 'extern "C" u8 D_0034a970;')
name='fm_primary_maskrecord_v3_00158548.cpp'
(ex/name).write_text(source,encoding='utf-8')
runner=(ex/'probe_maskcopy_v2.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_maskrecord_v3.py').write_text(runner[:start]+'names='+repr([name])+runner[end:],encoding='utf-8')
