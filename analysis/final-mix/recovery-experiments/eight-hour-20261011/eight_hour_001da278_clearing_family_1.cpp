#include "../common/types.h"
extern "C" u8 D_00352970;
extern "C" u32 D_00352960;
extern "C" void func_001a4e30(u32*);
extern "C" void func_00105110(u32*);
void func_001da278(u32* object)
{
 *(volatile u32*)object=(u32)&D_00352970;
 D_00352960=0;
 func_001a4e30(object);
 func_00105110(object);
}
