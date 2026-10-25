#include "../common/types.h"
extern "C" void* D_00347f80;
extern "C" u8 D_0035ebb8[];

typedef void** (*AllocFunc)(void*, s32, s32);

// why: all exits leave the indirect allocator v0 (stored into object[2]); no float use, so it is returned as a pointer

void** func_002b3d00(void** object) {
    object[0] = 0;
    object[1] = 0;
    object[2] = 0;
    void* heap = *(void**)((u8*)D_00347f80 + 20);
    void** first = (**(AllocFunc**)heap)(heap, 76, 0);
    first[3] = 0;
    first[0] = D_0035ebb8;
    object[0] = first;
    heap = *(void**)((u8*)D_00347f80 + 20);
    void** block = (**(AllocFunc**)heap)(heap, 232, 0);
    *(u32*)block = 3;
    void** items = block + 1;
    void** item = items;
    s32 count = 2;
    do {
        item[3] = 0;
        count--;
        item[0] = D_0035ebb8;
        item += 19;
    } while (count != -1);
    object[1] = items;
    heap = *(void**)((u8*)D_00347f80 + 20);
    void** last = (**(AllocFunc**)heap)(heap, 76, 0);
    last[3] = 0;
    last[0] = D_0035ebb8;
    object[2] = last;
    return last;
}
