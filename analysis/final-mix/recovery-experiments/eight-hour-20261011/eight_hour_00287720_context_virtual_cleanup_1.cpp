#include "../common/types.h"
extern "C" void func_002878c8(u32*);
extern "C" void func_0023f848(u32*);
void func_00287720(u32* object)
{
 func_002878c8(object);
 u32* receiver=(u32*)object[0];
 typedef void (*Callback)(u32*);
 ((Callback)((u32*)*receiver)[5])(receiver);
 u32 result=(u32)(object+3);
 asm("" : "+r"(result));
 func_0023f848((u32*)result);
}
