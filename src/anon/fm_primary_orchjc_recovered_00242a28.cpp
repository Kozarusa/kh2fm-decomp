#include "../common/types.h"
extern "C" u32 func_001058e8(void);

u32 func_00242a28(u8 value)
{
  u32 result = func_001058e8();
  register u32 truth asm("$16") = value != 0; // why: original truth uses s0
  asm volatile("" : "+r"(truth)); // why: original normalizes after call
  register u32 base asm("$2") = result + 0x41a0; // why: original adjusted result uses v0
  asm("" : "+r"(base)); // why: original forms adjusted base before load
  *(u32 *)(base + 4) = *(u32 *)(base + 4) & 0xfffffffe | truth;
  return base;
}
