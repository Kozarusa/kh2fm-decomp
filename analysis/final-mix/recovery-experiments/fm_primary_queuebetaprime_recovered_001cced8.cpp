#include "../common/types.h"
extern "C" u8 D_003520d0;
extern "C" u32 D_003520c0;
extern "C" void func_001a4e30(u32*);
extern "C" void func_00105110(u32*);

void func_001cced8(u32* object)
{
 *(u32*)object=(u32)&D_003520d0;
 D_003520c0=0;
 func_001a4e30(object);
 func_00105110(object);
}
