#include "../common/types.h"
extern "C" u8 D_0035daec;
extern "C" u8 D_0035daed;
extern "C" s64 func_00225a68();

s32 func_00225aa8() {
 s32 result=0;
 if (D_0035daec || D_0035daed || func_00225a68()) result=1;
 return result;
}
