#include "../common/types.h"
extern "C" f32 func_0016b558(...);
extern "C" u32 func_00176db0(...);
// Original register and control-flow proposal; independent exact gates required.
u32 func_002eb068(int param_1) {
 register u32 object asm("$14") = *(u32 *)(param_1+12);
 asm volatile("" : "+r"(object));
 register u32 value asm("$15") = *(u32 *)(object+4);
 register u32 first asm("$14") = value ^ 0x33;
 value ^= 0x3d;
 asm volatile("" : "+r"(first), "+r"(value));
 u32 result = 0;
 if (value == 0 || first == 0) result = 1;
 return result;
}
