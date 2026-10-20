#include "../common/types.h"
extern "C" u64 func_00124748(u32*,s32);
u64 func_00123d90(u32* object,u64 payload)
{
 u64 receiver=func_00124748(object,0);
 typedef u64 (*Callback)(u64,u64);
 return ((Callback)((u32*)*(u32*)receiver)[6])(receiver,payload);
}
