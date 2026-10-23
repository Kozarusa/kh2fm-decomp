#include "../common/types.h"
extern "C" u8 D_00351f78;
extern "C" u32 D_00351f68;
extern "C" void func_001a4e30(u32*);
extern "C" void func_00105110(u32*);

void func_001ca718(u32* object)
{
 *(u32*)object=(u32)&D_00351f78;
 D_00351f68=0;
 func_001a4e30(object);
 func_00105110(object);
}
