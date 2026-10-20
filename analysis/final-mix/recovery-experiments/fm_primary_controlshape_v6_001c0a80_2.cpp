#include "../common/types.h"
// Canonical indexed loop with the observed counter and cursor registers.
void func_001c0a80(u8 *param_1) {
 register s32 index asm("$14") = 0;
 asm volatile("" : "+r"(index));
 register u8 *cursor asm("$15");
 do {
  cursor = param_1 + index;
  *cursor = 0;
  ++index;
 } while(index < 19);
}
