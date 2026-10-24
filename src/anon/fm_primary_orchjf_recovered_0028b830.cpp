#include "../common/types.h"

extern "C" char D_0035f3a0;
extern "C" void func_0028b8a0(void*);
extern "C" void func_0023f820(u32);
extern "C" u32 func_00106420(u32);

u32 func_0028b830(u32 object)
{
  *(volatile u32 *)object = (u32)&D_0035f3a0;
  func_0028b8a0((void*)object);
  func_0023f820(object);
  return func_00106420(object);
}
