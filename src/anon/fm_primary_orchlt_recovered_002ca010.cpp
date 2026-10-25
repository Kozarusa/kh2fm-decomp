#include "../common/types.h"
struct Allocator;
typedef u8* (*AllocFn)(Allocator*, s32, s32);
struct Allocator { AllocFn* table; };
struct Manager { u8 pad[20]; Allocator* allocator; };
struct GlandingInfo { u8 pad[9608]; s32 owner; };
extern "C" Manager* D_00347f80;
extern "C" GlandingInfo* D_00361e00;
extern "C" s32 func_002cab58();
extern "C" void func_002c9f20(GlandingInfo*);
extern "C" s32 func_002c90c8(u8*, s32);

void func_002ca010(s32 owner) {
    if (func_002cab58() != 0) {
        return;
    }
    if (D_00361e00 != 0) {
        if (D_00361e00->owner == owner) {
            return;
        }
        func_002c9f20(D_00361e00);
        D_00361e00 = 0;
    }
    Allocator* allocator = D_00347f80->allocator;
    u8* info = allocator->table[0](allocator, 9616, 0);
    func_002c90c8(info, owner);
}
