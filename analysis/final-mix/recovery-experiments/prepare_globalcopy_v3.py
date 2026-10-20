from pathlib import Path
ex=Path(__file__).resolve().parent
names=[]
source=(ex/'fm_primary_maskcopy_v2_00158ac8_1.cpp').read_text(encoding='utf-8').replace('if(destination!=source)', 'if(source!=destination)')
name='fm_primary_globalcopy_v3_00158ac8_1.cpp'
(ex/name).write_text(source,encoding='utf-8')
names.append(name)
for variant in range(1,4):
 source=(ex/'fm_primary_maskcopy_v2_00158b20_1.cpp').read_text(encoding='utf-8')
 split=source.index('  source=(u32)&D_0034a9d0;')
 head,tail=source[:split],source[split:]
 tail=tail.replace('  destination=object+0x70;', '  register u32 final_destination asm("$4")=object+0x70;')
 tail=tail.replace('if(source!=destination)', 'if(final_destination!=source)').replace('*(Quad *)destination','*(Quad *)final_destination').replace('"r"(destination)','"r"(final_destination)')
 if variant>=2:
  marker='asm' if variant==2 else 'asm volatile'
  tail=tail.replace('  register u32 final_destination', f'  {marker}("" : "+r"(source) : "r"(object));\n  register u32 final_destination')
 source=head+tail
 name=f'fm_primary_globalcopy_v3_00158b20_{variant}.cpp'
 (ex/name).write_text(source,encoding='utf-8')
 names.append(name)
runner=(ex/'probe_maskrecord_v3.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_globalcopy_v3.py').write_text(runner[:start]+'names='+repr(names)+runner[end:],encoding='utf-8')
