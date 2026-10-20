#include "../common/types.h"

extern "C" u32 D_01d9eaa4;

struct Table {
    u8 pad00[16];
    s16 offset;
};

struct Source {
    u8* base;
};

struct Inner {
    u8 pad[2];
    u8 index;
};

struct Object {
    Source* source;
    Inner* inner;
    u8 pad08[8];
    u32 target[2];
    u16 pad18;
    u16 flags;
};

extern "C" u32 func_0021d048(u8* base, void* target, s32 flag);

struct Full {
    Source* source;
    Inner* inner;
    u8 pad08[8];
    u8 target[8];
    u32 field24;
    u16 pad28;
    u16 flags;
    u8 pad32[4];
};

void func_0021f060(u8* object)
{
    Source* source = *(Source**)object;
    Inner* inner = *(Inner**)(object + 4);
    u8* table = source->base + (u32)inner->index * 8;
    *(u32*)(object + 24) = 0;
    *(u8*)(object + 40) = 0;
    *(u32*)(object + 36) = D_01d9eaa4;
    *(u16*)(object + 18) = *(u16*)(object + 18) | 0x30;
    *(u16*)(object + 28) = 18;
    D_01d9eaa4 = func_0021d048(source->base + ((Table*)table)->offset, object + 16, 0);
}
