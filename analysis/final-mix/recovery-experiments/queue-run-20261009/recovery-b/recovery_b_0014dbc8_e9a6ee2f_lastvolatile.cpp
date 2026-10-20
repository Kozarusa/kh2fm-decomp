#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_0014dbc8(u32 p) {
  func_001666a0();
  *(u8 *)(p+0x1d9)=0;
  asm volatile("" ::: "memory");
  *(u32 *)(p+0x1d0)=0;
  *(u16 *)(p+0x1d4)=0;
  *(u8 *)(p+0x1d6)=0;
  *(u8 *)(p+0x1d7)=0;
  *(volatile u8 *)(p+0x1d8)=0;
}
