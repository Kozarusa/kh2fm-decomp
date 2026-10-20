#include "../common/types.h"
s32 func_0028ac98(s16*p,s32 i){register s32 index asm("$14")=i*8; s32 base=(i==*p?*(s32*)((char*)p+0x30):*(s32*)((char*)p+0x2c));return base+index;}