#include "../common/types.h"
extern "C" void func_002fd160(void) __attribute__((noreturn));
u8* func_00100920(u8 kind,u32 p) { u8* result=0; s32 code; if(kind==255) goto done; code=kind&0x70; switch(code) { case 0: case 16: case 80: break; case 32: result=(u8*)*(s32*)(p+4); break; case 48: result=(u8*)*(s32*)(p+8); break; default: func_002fd160(); } done: return result; }
