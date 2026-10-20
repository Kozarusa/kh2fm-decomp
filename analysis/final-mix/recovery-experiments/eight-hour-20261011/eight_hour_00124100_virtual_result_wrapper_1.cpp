#include "../common/types.h"
extern "C" u32* func_00124748(u32*,s32);
u64 func_00124100(u32* object,u64 payload)
{
 u32* receiver=func_00124748(object,0);
 typedef u64 (*Callback)(u32*,u64);
 return ((Callback)((u32*)*(u32*)receiver)[11])(receiver,payload);
}
