#include "../common/types.h"
// Complete-range fresh proposal, pending independent original-byte proof.
u32 func_0010f6f8(f32 fraction,u32 object) { u32 result=0; if(!(*(u32*)(object+0x7f8)&4)) { u32 owner=*(u32*)(object+0x48c); if(owner) { result=1; if((s32)((f32)*(s32*)(owner+0x184)*fraction)<=*(s32*)(owner+0x180)) result=0; } } return result; }
