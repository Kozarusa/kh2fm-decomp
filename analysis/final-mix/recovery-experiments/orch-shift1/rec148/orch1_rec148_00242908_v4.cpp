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
 if(value == 1) result=1; else if(value < 2) { if(value == 0) result=0; else result=1; } else { if(value == 2) result=2; else result=1; }
 return func_002b6bc4(result);
}



