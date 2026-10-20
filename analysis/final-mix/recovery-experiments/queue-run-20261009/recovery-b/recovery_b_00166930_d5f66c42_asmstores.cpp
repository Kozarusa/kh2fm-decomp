#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_00166930(u32 p) {
  func_001666a0();
  asm volatile("sh $0,10(%0); sb %1,14(%0); sh $0,12(%0)" :: "r"(p),"r"(1) : "memory");
}
