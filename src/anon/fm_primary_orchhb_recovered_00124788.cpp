#include "../common/types.h"
extern "C" u32* func_00124748(u32*,s32);

s32 func_00124788(u32* object, s32 kind)
{
    typedef s32 (*Callback)(u8*);
    s32 total = 0;
    u32* receiver = func_00124748(object, kind);
    u8* base = (u8*)object[1];
    s32* offsets = (s32*)(base + 16);
    while (*offsets != 0) {
        u8* entry = &base[*offsets];
        if ((u32*)entry == receiver) break;
        offsets++;
        total += ((Callback)((u32*)*(u32*)entry)[12])(entry);
    }
    return total;
}
