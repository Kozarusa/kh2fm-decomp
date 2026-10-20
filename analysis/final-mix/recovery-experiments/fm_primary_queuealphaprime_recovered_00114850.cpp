#include "../common/types.h"
extern "C" u8 D_003461e8;
extern "C" void func_00113668(u32*);
extern "C" void func_00105110(u32*);

void func_00114850(u32* object)
{
 *(u32*)object=(u32)&D_003461e8;
 func_00113668(object);
 func_00105110(object);
}
