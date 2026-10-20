from pathlib import Path
import json,subprocess
ex=Path(__file__).resolve().parents[2]
out=Path(__file__).resolve().parent
src=(ex/'fm_primary_fourwordfresh_v2_0014dc48.cpp').read_text()
old='  asm volatile("" : : : "memory");\n  asm volatile("sb $0,0x1d6(%0); sb $0,0x1d7(%0); sb $0,0x1d8(%0)" : : "r"(iVar1) : "memory");'
variants={
'precisemem': '  asm volatile("sb $0,0x1d6(%3); sb $0,0x1d7(%3); sb $0,0x1d8(%3)" : "=m"(*(u8*)(iVar1+0x1d6)), "=m"(*(u8*)(iVar1+0x1d7)), "=m"(*(u8*)(iVar1+0x1d8)) : "r"(iVar1));',
'splitmem':'\n'.join('  asm volatile("sb $0,0x%x(%%1)" : "=m"(*(u8*)(iVar1+0x%x)) : "r"(iVar1));'%(i,i) for i in [0x1d6,0x1d7,0x1d8]),
}
for tag,repl in variants.items():
 assert old in src
 (out/f'sa_frame_0014dc48_{tag}.cpp').write_text(src.replace(old,repl))
src=(ex/'fm_primary_fiveword_v2_002e5f70.cpp').read_text()
start=src.index('  *(u64 *)(param_1 + 0x230)')
end=src.index('  return;',start)
variants={
'precisemem':'  *(u64 *)(param_1 + 0x230) = 0;\n  asm volatile("sw $0,0x220(%4); sw $0,0x224(%4); sw $0,0x228(%4); sw $0,0x22c(%4)" : "=m"(*(u32*)(param_1+0x220)), "=m"(*(u32*)(param_1+0x224)), "=m"(*(u32*)(param_1+0x228)), "=m"(*(u32*)(param_1+0x22c)) : "r"(param_1));\n',
'volatileall': '\n'.join('  *(volatile %s *)(param_1 + 0x%x) = 0;'%(t,i) for t,i in [('u64',0x230),('u32',0x220),('u32',0x224),('u32',0x228),('u32',0x22c)])+'\n',
}
for tag,repl in variants.items():
 (out/f'sa_frame_002e5f70_{tag}.cpp').write_text(src[:start]+repl+src[end:])
