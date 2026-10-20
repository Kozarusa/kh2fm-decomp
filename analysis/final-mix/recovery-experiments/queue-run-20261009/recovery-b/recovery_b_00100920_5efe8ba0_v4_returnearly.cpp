#include "../common/types.h"
extern "C" void func_002fd160(void) __attribute__((noreturn));
u32 func_00100920(u8 kind,u32 p) { u32 result; s32 code; if(kind==255) return 0; code=kind&0x70; if(code==32) goto load4; if(code<33) { if(code==0 || code==16) return 0; goto bad; } if(code==48) goto load8; result=0; if(code!=80) goto bad; done: return result; load8: result=*(u32*)(p+8); goto done; load4: result=*(u32*)(p+4); goto done; bad: func_002fd160(); }
