#include "../common/types.h"
extern "C" s16 D_00371840[];
u8* func_00243150(s32 value) {
 u8* result=0;
 if(D_00371840[0]>=0) {
 register u8* pointer asm("$14")=(u8*)D_00371840; // why: original cursor occupies t6
 s32 item=*(volatile s16*)pointer;
 do { if(item==value) result=pointer; pointer+=12; item=*(s16*)pointer; } while(item>=0);
 }
 return result;
}



