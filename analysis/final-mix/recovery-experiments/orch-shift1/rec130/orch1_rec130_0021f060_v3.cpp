#include "../common/types.h"

extern "C" u32 D_01d9eaa4;
extern "C" u32 func_0021d048(u8* base, void* target, s32 flag);

void func_0021f060(volatile u8* object) // why: keeps store and load order
{
    u8* base = *(u8* volatile*)object;
    u8* inner = *(u8* volatile*)(object + 4);
    u8* table = *(u8**)base + (u32)inner[2] * 8;
    *(volatile u32*)(object + 24) = 0;
    *(volatile u8*)(object + 40) = 0;
    *(volatile u32*)(object + 36) = D_01d9eaa4;
    *(volatile u16*)(object + 18) = *(volatile u16*)(object + 18) | 0x30;
    *(volatile u16*)(object + 28) = 18;
    D_01d9eaa4 = func_0021d048(*(u8**)base + *(s16*)(table + 16), (u8*)object + 16, 0);
}
