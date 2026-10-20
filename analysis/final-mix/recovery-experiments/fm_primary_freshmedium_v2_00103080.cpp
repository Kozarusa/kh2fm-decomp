#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" char D_0032b930; extern "C" u32 D_0032b9a0[]; void func_00103080(s64 first,s64 second) { if(second==0xffff && first==1) { D_0032b9a0[0]=(u32)&D_0032b930; D_0032b9a0[6]=130000; D_0032b9a0[10]=0x1000; *(u8*)((u32)D_0032b9a0+8)=0x54; D_0032b9a0[1]=0; D_0032b9a0[7]=0; D_0032b9a0[8]=0; D_0032b9a0[9]=0; D_0032b9a0[5]=1; } }
