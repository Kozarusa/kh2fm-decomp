#include "../common/types.h"
extern "C" u8 D_0035f3a0;
extern "C" void func_0023f7e0(u32*);
extern "C" void func_0028b870(u32*);
void func_0028b788(u32* object)
{
 func_0023f7e0(object);
 *(volatile u32*)object=(u32)&D_0035f3a0;
 func_0028b870(object);
}
