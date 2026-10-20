#include "../common/types.h"
extern "C" u8 D_00361f70;
extern "C" u32 D_00361f60;
extern "C" void func_002cf3f8(u32*);
extern "C" void func_00105110(u32*);
void func_002ceaa8(u32* object)
{
 *object=(u32)&D_00361f70;
 func_002cf3f8(object);
 D_00361f60=0;
 *(volatile u8*)((u8*)object+88)=0;
 func_00105110(object);
}
