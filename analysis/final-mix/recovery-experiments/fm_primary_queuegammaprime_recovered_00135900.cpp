#include "../common/types.h"
extern "C" u8 D_00347d00;
extern "C" u32 D_00347cf0;
extern "C" void func_00135aa0(u32*);

void func_00135900(u32* object)
{
 *object=(u32)&D_00347d00;
 func_00135aa0(object);
 *(u32*)(object+2)=D_00347cf0;
 D_00347cf0=(u32)object;
}
