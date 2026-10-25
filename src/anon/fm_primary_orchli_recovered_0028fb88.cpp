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

// why: read as a plain word so the u32 stores to the object may alias it, which keeps the original store before the reload
extern "C" u32 D_00347f80;
extern "C" u8 D_00347e60[];
// why: declaration copied from the call site in fm_primary_orchjg_recovered_0028d0f8.cpp
extern "C" s32 func_00239700(u32);
// why: declaration copied from the call site in fm_primary_orchjf_recovered_0028b940.cpp
extern "C" u32* func_0028dfe8(u32* object);
// why: the callee's original instructions only store a0 and a1 as halfwords and never write v0 or $f0, so the tail call returns nothing
extern "C" void func_00258d40(u32 first, u32 second);

void func_0028fb88(u32* object, u32 first, u32 second, u16* values) {
  Allocator* allocator = ((Manager*)D_00347f80)->allocator;
  u32* entry = allocator->table[0](allocator, 408, 0);
  entry[3] = 0;
  *(u8**)entry = D_00347e60;
  func_00239700((u32)(entry + 6));
  object[0] = (u32)entry;
  allocator = ((Manager*)D_00347f80)->allocator;
  u32* light = allocator->table[0](allocator, 60, 0);
  func_0028dfe8(light);
  object[1] = (u32)light;
  s32 index = 0;
  do {
    ((u16*)(object + 2))[index] = values[index];
    index++;
  } while (index < 3);
  object[4] = first;
  func_00258d40(first, second);
}
