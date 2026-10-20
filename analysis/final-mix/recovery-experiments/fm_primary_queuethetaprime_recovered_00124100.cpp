#include "../common/types.h"
extern "C" u32* func_00124748(u32*,s32);

void func_00124100(u32* object,u64 payload)
{
 u32* receiver=func_00124748(object,0);
 typedef void (*Callback)(u32*,u64);
 ((Callback)((u32*)*(u32*)receiver)[11])(receiver,payload);
}
