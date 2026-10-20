#include "../common/types.h"
typedef void (*Callback)(u32*,u32*);
extern "C" u8 D_00347e40;
extern "C" u32* D_00347f80;
extern "C" void func_0031cd50(u32*);
void func_0031ca20(u32* object)
{
 *(volatile u32*)object=(u32)&D_00347e40;
 func_0031cd50(object);
 u32* receiver=(u32*)D_00347f80[5];
 ((Callback*)receiver[0])[1](receiver,object);
}
