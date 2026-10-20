#include "../common/types.h"
extern "C" u32 D_01d49960;
extern "C" u32 D_01d49968;
void func_001c8a90(void)
{
  volatile u32 *base=&D_01d49960;
  *base=0; base[1]=0; D_01d49968=0;
}
