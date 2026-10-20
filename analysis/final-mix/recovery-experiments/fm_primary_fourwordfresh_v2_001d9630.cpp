#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(...);
extern "C" bool func_001a6d08(...);
extern "C" bool func_001b8958(...);
extern "C" bool func_001bb4a0(...);
extern "C" bool func_001bb4b0(...);
extern "C" bool func_001c5f38(...);
extern "C" bool func_001ca448(...);
extern "C" bool func_001db200(...);
extern "C" bool func_001dc9e0(...);
extern "C" bool func_001e6c40(...);
extern "C" bool func_001e6d08(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001a35f8(...);
extern "C" s32 func_001db888(...);
extern "C" s64 func_0017e668(...);
extern "C" s64 func_001db9a8(...);
extern "C" s64 func_001e6b90(...);
extern "C" u16 func_001a8b68(...);
extern "C" u16 func_001d01e0(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00105868(...);
extern "C" u32 func_0014c9d8(...);
extern "C" u32 func_0014c9f0(...);
extern "C" u32 func_0014f688(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016c5b8(...);
extern "C" u32 func_0016c640(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_00176cd0(...);
extern "C" u32 func_001780d8(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017df58(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_00190920(...);
extern "C" u32 func_00198450(...);
extern "C" u32 func_001987a8(...);
extern "C" u32 func_00198860(...);
extern "C" u32 func_0019baa8(...);
extern "C" u32 func_001a3188(...);
extern "C" u32 func_001a4ff8(...);
extern "C" u32 func_001a6c90(...);
extern "C" u32 func_001ada38(...);
extern "C" u32 func_001ba158(...);
extern "C" u32 func_001bbcb0(...);
extern "C" u32 func_001bbe38(...);
extern "C" u32 func_001bbe78(...);
extern "C" u32 func_001bdab0(...);
extern "C" u32 func_001c1748(...);
extern "C" u32 func_001c1890(...);
extern "C" u32 func_001c6748(...);
extern "C" u32 func_001c6760(...);
extern "C" u32 func_001c8d80(...);
extern "C" u32 func_001c8d98(...);
extern "C" u32 func_001c99b0(...);
extern "C" u32 func_001c9ab8(...);
extern "C" u32 func_001ca988(...);
extern "C" u32 func_001ce3e8(...);
extern "C" u32 func_001d16f8(...);
extern "C" u32 func_001d1950(...);
extern "C" u32 func_001d2110(...);
extern "C" u32 func_001d2248(...);
extern "C" u32 func_001d3350(...);
extern "C" u32 func_001d3388(...);
extern "C" u32 func_001d4f40(...);
extern "C" u32 func_001d6cc8(...);
extern "C" u32 func_001d7b10(...);
extern "C" u32 func_001d8718(...);
extern "C" u32 func_001d87b8(...);
extern "C" u32 func_001d8c70(...);
extern "C" u32 func_001da3d8(...);
extern "C" u32 func_001db250(...);
extern "C" u32 func_001db8b8(...);
extern "C" u32 func_001dbd68(...);
extern "C" u32 func_001dc738(...);
extern "C" u32 func_001dca30(...);
extern "C" u32 func_001e2c00(...);
extern "C" u32 func_001e6c00(...);
extern "C" u32 func_001e7070(...);
extern "C" u32 func_001e7088(...);
extern "C" u32 func_00276fd0(...);
extern "C" u32 func_00321728(...);
extern "C" u64 func_001bd3e0(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_001e2c78(...);

void func_001d9630(u16 *param_1,int param_2)

{
  register int count asm("$16") = param_2;
  register u16 *cursor asm("$17") = param_1;
  asm volatile("" : : "r"(cursor));
  if (0 < count) {
    do {
      if (*cursor != 0) {
        func_001a3188(*cursor,100,0);
        *cursor = 0;
      }
      count = count - 1;
      cursor = cursor + 1;
    } while (count != 0);
  }
  return;
}
