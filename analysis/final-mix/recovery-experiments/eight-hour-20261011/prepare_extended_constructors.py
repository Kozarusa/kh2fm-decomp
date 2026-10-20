from pathlib import Path
import json
import sqlite3
import subprocess
import sys
base=Path(__file__).resolve().parent
helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
sources={}
for address in ('001c2c98','001c2ce8'):
    original=(base.parent/f'fm_worker_b_round24_{address}_v02.cpp').read_text()
    table='*(u32 *)param_1 = (u32)(long)&func_00351468;'
    mode='*(u32 *)((u8 *)param_1 + 2748) = uVar2;'
    assert table+'\n  '+mode in original
    for profile in (0,1,2):
        text=original
        if profile!=2:
            text=text.replace(table+'\n  '+mode,mode+'\n  '+table)
        if profile:
            text=text.replace('func_001d7cd0(u32);','func_001d7cd0(u32,u64,u64);').replace(f'func_{address}(u32 param_1)',f'func_{address}(u32 param_1,u64 second,u64 third)').replace('func_001d7cd0(param_1);','func_001d7cd0(param_1,second,third);')
            text=text.replace('char func_00351468','u8 D_00351468').replace('(u32)(long)&func_00351468','(u32)&D_00351468')
        sources[f'eight_hour_{address}_revisit_store_order_{profile}.cpp']=text
for profile in (0,1):
    for address in ('00185b00','00185b70'):
        text=f'#include "../common/types.h"\nextern "C" u8 D_0034ed78;\nextern "C" f32 D_0036c900;\nextern "C" void func_001d7cd0(u32*,u64,u64);\nextern "C" u32 func_0016a090(u32*);\nvoid func_{address}(u32* object,u64 second,u64 third)\n{{\n func_001d7cd0(object,second,third);\n object[700]=0;\n *object=(u32)&D_0034ed78;\n object[0x162]|=0x10;\n'
        if profile:
            text+=' register f32* scale asm("$15")=&D_0036c900;\n asm("" : "+r"(scale));\n *(f32*)(object+0x2bd)=*scale;\n'
        else:
            text+=' *(f32*)(object+0x2bd)=D_0036c900;\n'
        text+=' if(func_0016a090(object)==2)object[0x2af]|=0x8000;\n}\n'
        sources[f'eight_hour_{address}_inherited_float_constructor_{profile}.cpp']=text
    for address in ('001ae9a0','001aea00'):
        text=f'#include "../common/types.h"\nextern "C" u8 D_00350ce0;\nextern "C" f32 D_0036d858;\nextern "C" void func_00185b00(u32*,u64,u64);\nvoid func_{address}(u32* object,u64 second,u64 third)\n{{\n func_00185b00(object,second,third);\n *object=(u32)&D_00350ce0;\n object[0x162]|=0x400;\n'
        if profile:
            text+=' register u8* nested asm("$13")=(u8*)object+1648;\n asm("" : "+r"(nested));\n register f32* scale asm("$15")=&D_0036d858;\n asm("" : "+r"(scale));\n *(u32*)(nested+264)=0;\n *(f32*)(nested+260)=*scale;\n'
        else:
            text+=' object[0x1de]=0;\n *(f32*)(object+0x1dd)=D_0036d858;\n'
        text+=' object[0x2af]|=0x8404;\n}\n'
        sources[f'eight_hour_{address}_nested_float_constructor_{profile}.cpp']=text
    text='#include "../common/types.h"\nextern "C" u8 D_003622c0;\nextern "C" f32 D_00375af0;\nextern "C" void func_002d0ea8(u32*,u64,u64,u64);\nvoid func_002d49c0(u32* object,u64 second,u64 third,u64 fourth)\n{\n func_002d0ea8(object,second,third,fourth);\n object[0x2fc]=0;\n *object=(u32)&D_003622c0;\n register f32 copied asm("$f1")=*(volatile f32*)(object+0x2fc);\n'
    if profile:
        text+=' register f32* block asm("$14")=(f32*)(object+0x300);\n asm("" : "+r"(block),"+f"(copied));\n block[3]=copied;\n block[1]=copied;\n block[2]=copied;\n register f32* scale asm("$15")=&D_00375af0;\n asm("" : "+r"(scale));\n object[0x30d]=0;\n *(f32*)(object+0x304)=*scale;\n block[0]=copied;\n'
    else:
        text+=' *(f32*)(object+0x303)=copied;\n *(f32*)(object+0x301)=copied;\n *(f32*)(object+0x302)=copied;\n object[0x30d]=0;\n *(f32*)(object+0x304)=D_00375af0;\n *(f32*)(object+0x300)=copied;\n'
    text+=' object[0x305]=0;\n object[0x306]=0;\n object[0x307]=0;\n object[0x30c]=0;\n}\n'
    sources[f'eight_hour_002d49c0_float_block_constructor_{profile}.cpp']=text
    text='#include "../common/types.h"\nextern "C" u8 D_00347bb0;\nextern "C" u8 D_003a99f0[];\nextern "C" void func_00124bb8(u32*,u32);\nextern "C" void func_0011ed90(u32);\nvoid func_00127f40(u32* object,u32 resource)\n{\n func_00124bb8(object,resource);\n u32 header=object[1];\n *object=(u32)&D_00347bb0;\n register u32 origin asm("$13")=(u32)D_003a99f0;\n'
    if profile:
        text+=' asm("" : "+r"(origin));\n'
    text+=' u32 first=*(u16*)(header+16);\n u32 end=*(u16*)(header+18);\n object[2]=origin;\n u32 count=end-first;\n u32 buffer=origin+*(volatile u16*)(header+18)*64;\n object[3]=buffer;\n object[4]=buffer+count*64;\n object[5]=buffer+count*64+count*64;\n func_0011ed90(header+*(u32*)(header+24));\n}\n'
    sources[f'eight_hour_00127f40_buffer_constructor_{profile}.cpp']=text
db=sqlite3.connect((base.parents[1]/'worker-coordination/recovery-queue.sqlite3').as_uri()+'?mode=ro',uri=True)
leases=[]
for address in sorted({name.split('_')[2] for name in sources}):
    state,queue=db.execute('select state,queue from targets where address=?',(address,)).fetchone()
    assert state=='ready',(address,state)
    result=subprocess.run([sys.executable,str(helper),'claim','--worker','eight-hour-primary','--queue',queue,'--count','1','--address',address],capture_output=True,text=True)
    assert result.returncode==0,result.stdout+result.stderr
    claimed=json.loads(result.stdout)['leases']
    assert len(claimed)==1,address
    leases.extend(claimed)
for name,text in sources.items():
    (base/name).write_text(text)
with (base/'extended-constructor-leases.json').open('x') as stream:
    json.dump(leases,stream,indent=2)
(base/'extended-constructor-variants.json').write_text(json.dumps(list(sources)))
(base/'probe_extended_constructors.py').write_text((base/'probe_quad_copy.py').read_text().replace('quad-copy-variants.json','extended-constructor-variants.json'))
record_path=base.parents[1]/'worker-coordination/eight-hour-run-20261011.json'
record=json.loads(record_path.read_text())
if not any(row['phase']=='queuegammaprime' for row in record['accepted_batches']):
    record['accepted_batches'].append({'phase':'queuegammaprime','functions':13,'instruction_bytes':956,'exact_total':5968,'checkpoint':'primary-queuegammaprime-checkpoint-2026-10-08.json'})
record['phase']='extended-constructor-ABI-and-field-typing'
record_path.write_text(json.dumps(record,indent=2)+'\n')
print(f'Claimed {len(leases)} functions; prepared {len(sources)} ABI proposals.')
