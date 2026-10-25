#include "../common/types.h"
typedef u32 (*AllocateFunction)(u32, s32, s32);
extern "C" u32 D_00347f80;
extern "C" u8 D_0035ebb8[];

// why: the only exit leaves the direct v0 result of the last indirect allocator call (no float evidence), so the return is that pointer

u32 func_002b3df8(u32* object) {
    object[0] = 0;
    object[1] = 0;
    object[2] = 0;
    u32 allocator = *(u32*)(D_00347f80 + 20);
    u32* first = (u32*)(**(AllocateFunction**)allocator)(allocator, 76, 0);
    first[3] = 0;
    first[0] = (u32)D_0035ebb8;
    object[0] = (u32)first;
    allocator = *(u32*)(D_00347f80 + 20);
    u32* block = (u32*)(**(AllocateFunction**)allocator)(allocator, 232, 0);
    block[0] = 3;
    u32* items = block + 1;
    u32* item = items;
    s32 count = 2;
    do {
        item[3] = 0;
        count--;
        item[0] = (u32)D_0035ebb8;
        item += 19;
    } while (count != -1);
    object[1] = (u32)items;
    allocator = *(u32*)(D_00347f80 + 20);
    u32* last = (u32*)(**(AllocateFunction**)allocator)(allocator, 76, 0);
    last[3] = 0;
    last[0] = (u32)D_0035ebb8;
    object[2] = (u32)last;
    return (u32)last;
}
