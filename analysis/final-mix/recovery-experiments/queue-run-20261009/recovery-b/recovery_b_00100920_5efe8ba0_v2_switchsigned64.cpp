#include "../common/types.h"
extern "C" void func_002fd160(void) __attribute__((noreturn));
s64 func_00100920(u8 kind,u32 p) { s64 result=0; if(kind==255) goto done; s32 code=kind&0x70; switch(code) { case 0: case16: case80: break; case32: result=*(s32*)(p+4); break; case48: result=*(s32*)(p+8); break; default: func_002fd160(); } done: return result; }
