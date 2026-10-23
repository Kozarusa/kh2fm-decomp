#include "../common/types.h"
extern "C" u32 D_0035ece0;
extern "C" u64 func_00243190(void);
extern "C" void func_00243020(u64);

// Preserve original registry aliases.
void func_002430b0(u32 p) asm("_ZN2Tz7SubMenu5StartEi");

void func_002430b0(u32 p){register u32 high asm("$14")=0x360000;asm("" : "+r"(high));*(u32*)(high-0x1320)=p;func_00243020(func_00243190());}
