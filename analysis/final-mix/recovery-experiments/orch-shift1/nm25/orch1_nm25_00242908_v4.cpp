#include "../common/types.h"
extern "C" s32 func_00242a00();
extern "C" void func_0023d1d0();
extern "C" void func_0023d1e0();
extern "C" s32 func_00242a68();
extern "C" u64 func_002b6bc4(u32);
u64 func_00242908() {
 if (func_00242a00()) func_0023d1d0(); else func_0023d1e0();
 s32 value = func_00242a68();
 s32 result;
 if(value == 1) goto one; if(value >= 2) goto two; result=0; if(value == 0) goto done; one: result=1;
 asm("" : "+r"(result)); // why: retain one-label result assignment before shared exit
 goto done; two: {
 register s32 comparison asm("$15") = 2; // why: original comparison constant occupies t7 independently of result
 result=2; if(value == comparison) goto done; goto one; } done:
 asm("" : "+r"(result)); // why: constrain result lifetime at shared exit before tail call
 return func_002b6bc4(result);
}









