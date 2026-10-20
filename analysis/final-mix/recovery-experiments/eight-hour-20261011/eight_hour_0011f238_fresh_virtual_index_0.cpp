#include "../common/types.h"
s16 func_0011f238(u32* object,u32 index)
{
 typedef u32 (*Callback)(u32*);
 u32 base=((Callback)(*(u32**)*object)[8])(object);
 return *(s16*)((u32)base+index*64+4);
}
