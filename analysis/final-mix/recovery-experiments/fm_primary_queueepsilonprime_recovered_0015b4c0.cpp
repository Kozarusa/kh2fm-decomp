#include "../common/types.h"
extern "C" u32* func_001050c8();

void func_0015b4c0(u64 payload)
{
 u32* receiver=func_001050c8();
 typedef void (*Callback)(u32*,u64);
 ((Callback)((u32*)*receiver)[1])(receiver,payload);
}
