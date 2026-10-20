#include "../common/types.h"

extern "C" char D_00367860;
extern "C" void func_003167f8(void*);
extern "C" void func_00106420(u32);

void func_00315678(u32 object)
{
  *(volatile u32 *)object = (u32)&D_00367860;
  func_003167f8((void*)object);
  func_00106420(object);
  // why: keeps the call from becoming a tail call
  asm volatile ("");
  return;
}
