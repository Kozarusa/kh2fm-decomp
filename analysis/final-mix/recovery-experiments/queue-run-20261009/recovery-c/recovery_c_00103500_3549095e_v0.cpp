#include "../common/types.h"
extern "C" u32 D_0032ba20,D_003a6a50;
extern "C" s64 func_00103b38(u64);
void func_00103500(u64 value){if(func_00103b38(value)==0){D_003a6a50=value;D_0032ba20=-1;}else if(D_0032ba20!=value){D_0032ba20=value;}}
