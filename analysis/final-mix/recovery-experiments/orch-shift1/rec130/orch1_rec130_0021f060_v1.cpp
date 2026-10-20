#include "../common/types.h"

extern "C" u32 D_01d9eaa4;
extern "C" u32 func_0021d048(u32 base, void* target, s32 flag);

struct Inner {
    u8 pad[2];
    u8 index;
};

struct Object {
    u32** source;
    Inner* inner;
    u8 pad08[0x0c];
    u16 flags;
    u8 pad14[2];
    u32 target[2];
    u32 pad20;
    u32 value;
    u32 saved;
    u16 pad28;
};

void func_0021f060(u8* object)
{
    u32** source = *(u32***)object;
    u8* inner = *(u8**)(object + 4);
    u8* table = (u8*)*source + (u32)inner[2] * 8;
    *(u32*)(object + 24) = 0;
    *(u8*)(object + 40) = 0;
    *(u32*)(object + 36) = D_01d9eaa4;
    *(u16*)(object + 18) = *(u16*)(object + 18) | 0x30;
    *(u16*)(object + 28) = 18;
    D_01d9eaa4 = func_0021d048((u32)*source + *(s16*)(table + 16), object + 16, 0);
}
