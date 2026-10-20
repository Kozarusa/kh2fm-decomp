#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u8* D_0035ed04;
u32 func_00244db8() {
 s32 offset=0;
 s32 count=1;
 u32 result;
 do {
 result=func_00139d78(D_0035ed04+offset);
 if(result) { u8* object=D_0035ed04+offset; result=((u32 (*)(u8*))(*(u32**)object)[5])(object); }
 --count; offset+=408;
 } while(count>=0);
 return result;
}
