#include "../common/types.h"
struct Pair {
  s32 first;
  s32 second;
};
extern "C" Pair D_00354690;
extern "C" void func_001e60b0();

void func_001e6250(void)
{
  Pair *pointer;
  func_001e60b0();
  pointer = &D_00354690;
  pointer->first = 0;
  pointer->second = -1;
}
