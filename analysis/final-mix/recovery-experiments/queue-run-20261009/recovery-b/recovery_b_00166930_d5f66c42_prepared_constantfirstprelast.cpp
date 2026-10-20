#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_00166930(u32 p) {
  func_001666a0();
  u32 one=1;
  asm volatile("" : "+r"(one));
  *(volatile u16*)(p+10)=0;
  *(volatile u8*)(p+14)=one;
  asm volatile("" ::: "memory");
  *(volatile u16*)(p+12)=0;
}
