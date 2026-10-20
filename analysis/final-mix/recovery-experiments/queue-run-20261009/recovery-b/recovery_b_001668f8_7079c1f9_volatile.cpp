#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_001668f8(u32 p) {
  func_001666a0();
  *(volatile u16*)(p+10)=0;
  *(volatile u8*)(p+14)=1;
  *(volatile u16*)(p+12)=0;
}
