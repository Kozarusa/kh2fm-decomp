#include "../common/types.h"
extern "C" void func_00158f90(void);
void func_00195c58(u64 unused,u32 object) { u32 flags=*(u32*)(object+0x588); asm("" : "+r"(flags)); if(flags&0x80) func_00158f90(); }
