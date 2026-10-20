#include "../common/types.h"
extern "C" f32 func_0016b558(...);
extern "C" u32 func_00176db0(...);
// Original register and control-flow proposal; independent exact gates required.
void func_001c0a80(u8 *param_1) {
 register s32 index asm("$14") = 0;
 asm volatile("" : "+r"(index));
 register u8 *cursor asm("$15") = param_1 + index;
 for (;;) { *cursor = 0; ++index; if(index > 18) break; cursor = param_1 + index; }
 // Retain the last stored cursor on loop exit, allowing the original likely branch.
 asm volatile("" : : "r"(cursor));
}
