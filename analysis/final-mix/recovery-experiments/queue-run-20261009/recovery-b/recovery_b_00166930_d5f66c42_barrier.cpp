#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_00166930(u32 p) {
  func_001666a0();
  *(u16*)(p+10)=0;
  asm volatile("" ::: "memory");
  *(u8*)(p+14)=1;
  *(u16*)(p+12)=0;
}
