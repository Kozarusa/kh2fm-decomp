#include "../common/types.h"
extern "C" u64 func_002361d0(...);
extern "C" u64 func_00239870(...);
extern "C" u64 func_00239700(...);
extern "C" u64 func_002361a0(...);
extern "C" char D_0034af40;
extern "C" char D_0034b0e0;

void func_0015d730(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_002361a0((u32)(long)&D_0034af40);
  }
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_00239700((u32)(long)&D_0034b0e0);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    func_00239870((u32)(long)&D_0034b0e0);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    func_002361d0((u32)(long)&D_0034af40);
    return;
  }
  return;
}
