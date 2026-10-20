#include "../common/types.h"

extern "C" void func_0030f620(u32,u32);

static void helper(u32 *p)
{
  func_0030f620(0xb0001000u,*p);
}

void func_0030f690(u32 param_1)
{
  helper(&param_1);
}
