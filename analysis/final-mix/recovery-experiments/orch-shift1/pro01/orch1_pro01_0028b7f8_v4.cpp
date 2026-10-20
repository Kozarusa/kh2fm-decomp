#include "../common/types.h"

extern "C" char D_0035f3a0;
extern "C" void func_0028b8a0(void*);
extern "C" void func_0023f820(u32);

void func_0028b7f8(u32 object)
{
  *(volatile u32 *)object = (u32)&D_0035f3a0;
  func_0028b8a0((void*)object);
  func_0023f820(object);
  // dead assignment: blocks the sibling call at expansion, removed later
  object = 0;
}
