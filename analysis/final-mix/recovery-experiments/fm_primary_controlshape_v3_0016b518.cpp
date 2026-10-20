#include "../common/types.h"
extern "C" f32 func_0016b558(...);
extern "C" u32 func_00176db0(...);
// Original register and control-flow proposal; independent exact gates required.
void func_0016b518(int param_1,u64 param_2,u64 param_3) {
 register u64 retained asm("$6") = param_3;
 register u32 flags asm("$15") = *(u32 *)(param_1+0x588);
 flags &= 4;
 asm volatile("" : "+r"(flags));
 if (flags != 0) { func_00176db0(); asm volatile("" ::: "memory"); }
 else { asm volatile("" : "+r"(retained)); func_0016b558(param_1,retained); asm volatile("" ::: "memory"); }
}
