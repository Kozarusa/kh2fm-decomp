#include "../common/types.h"

struct Allocator;
typedef u32* (*AllocateFunction)(Allocator*, s32, s32);
struct Allocator {
  AllocateFunction* table;
};
struct Manager {
  u8 pad[20];
  Allocator* allocator;
};

extern "C" Manager* D_00347f80;
extern "C" u32* func_0028dfe8(u32* object);

u32* func_0028b940(u32* object)
{
  Allocator* allocator = D_00347f80->allocator;
  u32* result = allocator->table[0](allocator, 60, 0);
  u32* value = func_0028dfe8(result);
  object[0] = (u32)result;
  object[1] = 0;
  object[8] = 0;
  object[9] = 0;
  object[10] = 0;
  object[11] = 0;
  object[12] = 0;
  return value;
}
