#include "../common/types.h"
extern "C" void func_00158f90(void);
void func_00195c58(u64 unused,u32 object) { register u32 flags asm("$15"); asm("lw %0,1416(%1)" : "=r"(flags) : "r"(object),"m"(*(u32*)(object+0x588))); if(flags&0x80) func_00158f90(); }
