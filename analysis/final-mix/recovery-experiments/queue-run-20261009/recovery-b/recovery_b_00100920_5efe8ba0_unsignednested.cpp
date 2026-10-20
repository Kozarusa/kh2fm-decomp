#include "../common/types.h"
extern "C" void func_002fd160(void) __attribute__((noreturn));
u32 func_00100920(u8 kind,u32 p) { u32 result=0; if(kind!=255) { u32 code=kind&0x70; if(code==32) result=*(u32*)(p+4); else if(code<33) { if(code!=0 && code!=16) func_002fd160(); } else if(code==48) result=*(u32*)(p+8); else { result=0; if(code!=80) func_002fd160(); } } return result; }
