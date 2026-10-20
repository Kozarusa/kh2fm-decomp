#include "../common/types.h"
extern "C" u8 D_00351da8;
extern "C" u32 D_00351d98;
extern "C" void func_001a4e30(u32*);
extern "C" void func_00105110(u32*);

void func_001c7c68(u32* object)
{
 *(u32*)object=(u32)&D_00351da8;
 D_00351d98=0;
 func_001a4e30(object);
 func_00105110(object);
}
