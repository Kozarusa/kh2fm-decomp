#include "../common/types.h"
extern "C" void func_0017dbb8(u32*);
void func_0010c7f0(u32* object)
{
 func_0017dbb8(object);
 u32* receiver=(u32*)object[728];
 typedef u32 (*Callback)(u32*);
 u32 result=((Callback)((u32*)*receiver)[5])(receiver);
 asm("" : : "r"(result));
}
