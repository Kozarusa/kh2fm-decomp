#include "../common/types.h"

extern "C" void func_0023c098(u32);
extern "C" void func_002369f0(u32);
extern "C" s32 func_00106420(u32);
extern "C" char D_00363880;
extern "C" char D_003637e0;

s32 func_00325ae8(u32 object)
{
  *(u32 *)object = (u32)(long)&D_00363880;
  func_0023c098(object + 64);
  func_002369f0(object + 40);
  asm volatile ("" ::: "memory"); // why: keeps store order
  *(u32 *)object = (u32)(long)&D_003637e0;
  return func_00106420(object);
}
