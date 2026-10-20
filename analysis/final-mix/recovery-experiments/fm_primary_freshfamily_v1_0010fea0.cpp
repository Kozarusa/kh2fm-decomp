#include "../common/types.h"
// Complete-range fresh proposal, pending independent original-byte proof.
extern "C" s64 func_00112720(void);
s32 func_0010fea0(u32 object) { s64 available=func_00112720(); if(!available) { s32* item=(s32*)(object+0xc58); s32 count=1; s32 value=*item; while(++item,*(s32*)(object+0xc54)==value) { ++count; if(count>2) return *(s32*)(object+0xc54); value=*item; } } return 0; }
