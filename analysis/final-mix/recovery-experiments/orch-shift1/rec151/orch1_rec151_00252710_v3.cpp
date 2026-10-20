#include "../common/types.h"
extern "C" s32 func_00252110();
extern "C" bool func_001a6d08(u32);
extern "C" u8 D_00372600[];
s32 func_00252710() {
 register s32 result asm("$16")=0; // why: original persistent boolean result occupies s0
 s32 index=func_00252110();
 u32 value=D_00372600[index];
 if(value) { result=func_001a6d08(value)!=0; asm("" : "+r"(result)); } // why: keeps boolean conversion destination in original result register
 return result;
}


