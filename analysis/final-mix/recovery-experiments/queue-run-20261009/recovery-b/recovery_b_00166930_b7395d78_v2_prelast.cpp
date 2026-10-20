#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_00166930(u32 p) {
  func_001666a0();
  *(volatile u16*)(p+10)=0;
  *(volatile u8*)(p+14)=1;
  asm volatile("" ::: "memory");
  *(volatile u16*)(p+12)=0;
}
