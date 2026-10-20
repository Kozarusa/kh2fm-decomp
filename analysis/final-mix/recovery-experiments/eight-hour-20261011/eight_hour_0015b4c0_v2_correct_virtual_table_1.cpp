#include "../common/types.h"
extern "C" u32* func_001050c8();
void func_0015b4c0(u64 payload)
{
 u32* receiver=func_001050c8();
 typedef u32 (*Callback)(u32*,u64);
 u32 result=((Callback)((u32*)*receiver)[1])(receiver,payload);
 asm("" : : "r"(result));
}
