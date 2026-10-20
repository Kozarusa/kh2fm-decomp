#include "../common/types.h"
extern "C" volatile s32 D_0032ba20,D_003a6a50;
extern "C" s64 func_00103b38(s32);
void func_00103500(s32 value){if(func_00103b38(value)==0){D_003a6a50=value;D_0032ba20=-1;}else if(D_0032ba20!=value){D_0032ba20=value;}}
