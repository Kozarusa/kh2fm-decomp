#include "../common/types.h"
s32 func_0028ac98(s16* object,s32 index) { register s32 scaled asm("$14"); asm("sll %0,%1,3" : "=r"(scaled) : "r"(index)); if(index==*object) return scaled+*(s32*)((u32)object+0x30); return scaled+*(s32*)((u32)object+0x2c); }
