#include "../common/types.h"
extern "C" void func_001652c8(u32,u64,u64,u64,u64,u64,u64,u64);
extern "C" u32 D_00348804;

void func_00143470(u64 p1,u64 p2,u64 p3,u64 p4,u64 p5,u64 p6,u64 p7)
{
  register u64 preserved asm("$16")=p6;
  register u64 sixth asm("$10")=preserved;
  asm("" : "+r"(sixth) : "r"(p7));
  func_001652c8(D_00348804,p1,p2,p3,p4,p5,sixth,p7);
  asm volatile("" : : "r"(preserved));
}
