#include "../common/types.h"
extern "C" void func_0030a278(void);
extern "C" void func_00305660(u32);
u64 func_0030a2d0(void) { func_0030a278(); register u32 base asm("$2"); asm("lui %0,0x36" : "=r"(base)); func_00305660(*(u32*)(base+0x616c)); return 0; }
