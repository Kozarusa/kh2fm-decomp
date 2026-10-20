#include "../common/types.h"
extern "C" u32 func_00143fc8(s32,u32);
extern "C" u32 func_001e3468(s32);
extern "C" char D_00352b00;

u32 func_001dccc8(s32 param_1,u8 param_2) {
 register u32 result asm("$13") = 0;
 if((*(u32 *)(param_1+8)&0x1000000)!=0) return 0;
 if(param_2 != 0) {
  result = func_001e3468(*(u32 *)(param_1+0x1c));
  result = func_00143fc8((s32)(long)&D_00352b00,result);
 }
 asm volatile ("" : "+r"(result));
 return result;
}
