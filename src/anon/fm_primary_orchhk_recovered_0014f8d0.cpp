#include "../common/types.h"
struct Allocator;
typedef u8* (*AllocFn)(Allocator*, s32, s32);
struct Allocator { AllocFn* table; };
struct Manager { u8 pad[20]; Allocator* allocator; };
extern "C" Manager* D_00347f80;
extern "C" void func_0031bc58(u8*);
extern "C" void func_0014fe00(u8*, s32, s32, s32, s32, s32, s32, s32, s32);

u8* func_0014f8d0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    Allocator* allocator = D_00347f80->allocator;
    u8* object = allocator->table[0](allocator, 6192, 0);
    func_0031bc58(object);
    func_0014fe00(object, a, b, c, d, e, f, g, h);
    return object;
}
