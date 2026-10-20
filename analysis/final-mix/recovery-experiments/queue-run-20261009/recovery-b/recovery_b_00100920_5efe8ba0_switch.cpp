#include "../common/types.h"
extern "C" void func_002fd160(void) __attribute__((noreturn));
u32 func_00100920(u8 kind,u32 p) { u32 result=0; if(kind!=255) { s32 code=kind&0x70; switch(code) { case 0: case 16: case 80: break; case 32: result=*(u32*)(p+4); break; case 48: result=*(u32*)(p+8); break; default: func_002fd160(); } } return result; }
