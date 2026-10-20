#include "../common/types.h"
extern "C" void func_0011d440(u32*);
void func_0011c4b0(u32* object)
{
 func_0011d440(object);
 u32* receiver=(u32*)object[5];
 typedef u32 (*Callback)(u32*,u32*);
 u32 result=((Callback)((u32*)*receiver)[11])(receiver,object);
 asm("" : : "r"(result));
}
