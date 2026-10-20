#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 func_0024dfe0();
extern "C" u8* D_0035ede8;
s32 func_0024e530() {
 s32 offset=0,index=0;
 while(1) {
 s32 result=index<func_0024dfe0();
 ++index;
 if(!result) return result;
 if(func_00139d78(D_0035ede8+offset)) {
 u8* object=(u8*)(offset+(u32)D_0035ede8);
 u32* table=*(u32**)object;
 u32 (*callback)(u8*)=(u32 (*)(u8*))table[5];
 callback(object);
 }
 offset+=408;
 }
}
