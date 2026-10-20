#include "../common/types.h"
extern "C" void func_001369d0(void);
extern "C" void func_001369f0(void);
extern "C" void func_00136a50(void);
extern "C" u32 D_00347d20;
extern "C" u16 D_003b8b20;
extern "C" u32 D_003b8b38;
extern "C" u32 D_00347d24;
void func_00136968(void)
{
  func_001369d0(); func_001369f0();
  D_00347d20=0xffffffff;
  register u16 *pair asm("$12")=&D_003b8b20;
  asm("" : "+r"(pair));
  pair[1]=0xffff;
  D_003b8b38=0xffffffff;
  pair[0]=0xffff;
  D_00347d24=0xffffffff;
  func_00136a50();
}
