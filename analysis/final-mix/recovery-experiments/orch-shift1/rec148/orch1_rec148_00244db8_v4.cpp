#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u8* D_0035ed04;
u32 func_00244db8() {
 s32 offset=0;
 s32 count=1;
 u32 result;
 do {
 result=func_00139d78(D_0035ed04+offset);
 if(result) { u8* object=(u8*)(offset+(u32)D_0035ed04); register u32* table asm("$14")=*(u32**)object; // why: original virtual table occupies t6
 register u32 (*callback)(u8*) asm("$15")=(u32 (*)(u8*))table[5]; // why: original virtual callback occupies t7
 result=callback(object); }
 --count; offset+=408;
 } while(count>=0);
 return result;
}



