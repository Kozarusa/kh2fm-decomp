#include "../common/types.h"
extern "C" void func_001656d0(u8* object, u32 first, u32 second);
extern "C" u8* D_0034c7a0;

struct Pool {
    u8 objects[0x400];
    s32 freeList[0x40];
    s32 freeCount;
};

u8* func_001659b8(u32 first, u32 second) {
    Pool* pool = (Pool*)D_0034c7a0;
    s32 index = pool->freeCount - 1;
    pool->freeCount = index;
    u8* object = pool->objects + pool->freeList[index] * 16;
    func_001656d0(object, first, second);
    return object;
}
