#include "../common/types.h"
extern "C" s32 func_00242a00();
extern "C" void func_0023d1d0();
extern "C" void func_0023d1e0();
extern "C" s32 func_00242a68();
extern "C" s32 func_002b6bc4(s32);
s32 func_00242908() {
 if (func_00242a00()) func_0023d1d0(); else func_0023d1e0();
 s32 value = func_00242a68();
 s32 result;
 switch(value) { case 0: result=0; break; case 2: result=2; break; default: result=1; break; }
 return func_002b6bc4(result);
}
