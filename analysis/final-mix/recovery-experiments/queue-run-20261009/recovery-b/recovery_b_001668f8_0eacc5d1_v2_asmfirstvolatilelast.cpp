#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_001668f8(u32 p) {
  func_001666a0();
  asm volatile("sh $0,10(%0); sb %1,14(%0)" :: "r"(p),"r"(1) : "memory");
  *(volatile u16*)(p+12)=0;
}
