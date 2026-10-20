#include "../common/types.h"
// Complete-range proposal; independent original-byte verification required.
extern "C" char D_0032b930; extern "C" u32 D_0032b968[]; void func_00102c90(s64 first,s64 second) { if(second==0xffff && first==1) { D_0032b968[0]=(u32)&D_0032b930; D_0032b968[6]=130000; D_0032b968[10]=0x3800; *(u8*)((u32)D_0032b968+8)=0x46; D_0032b968[1]=0; D_0032b968[7]=0; D_0032b968[8]=0; D_0032b968[9]=0; D_0032b968[5]=1; } }
