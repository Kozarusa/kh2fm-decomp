#include "../common/types.h"
extern "C" s32 func_002766d0(void);
extern "C" void func_00139d78(s32);

void func_0029e2f8(s32 param_1) {
 s32 base = func_002766d0();
 param_1 = param_1 + 1;
 asm volatile("" : "+r"(param_1));
 func_00139d78(base + param_1 * 0x198 + 0x4398);
 asm volatile("" ::: "memory");
}
