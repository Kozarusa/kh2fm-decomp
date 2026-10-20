#include "../common/types.h"
extern "C" u32 func_001a8bf8(s32,s32);
extern "C" bool func_001c8db8(void*,s64);
extern "C" s32 func_001a8bd0(u64);
extern "C" u32 func_001b58a8(void);
extern "C" char D_00351ec0;

u32 func_001b6070(void) {
 s32 status = func_001b58a8();
 register u32 result asm("$15") = 0;
 if(status == 0) {
  u32 inner = 0;
  s32 object = func_001a8bd0(~0ULL);
  status = func_001a8bf8(object,3);
  if(status != 0x12) inner = func_001c8db8((void *)&D_00351ec0,0) == 0;
  asm volatile ("" : "+r"(inner));
  result = inner;
 }
 asm volatile ("" : "+r"(result));
 return result;
}
