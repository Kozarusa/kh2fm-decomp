#include "../common/types.h"
// Reuse the original t7 pointer/predicate register and retain its zero exit value.
void func_001c0a80(u8 *param_1) {
 register s32 index asm("$14") = 0;
 asm volatile("" : "+r"(index));
 register u32 state asm("$15") = (u32)param_1 + index;
 for (;;) {
  asm volatile("sb $0,0(%1)" : "+r"(index) : "r"(state) : "memory");
  ++index;
  asm volatile("slti %0,%1,19" : "=r"(state) : "r"(index));
  if (state == 0) break;
  state = (u32)param_1 + index;
 }
 asm volatile("" : : "r"(state));
}
