#include "../common/types.h"
extern "C" u16 D_0036e390[];
extern "C" bool func_0017a538(...);
extern "C" bool func_001a2478(void*);
extern "C" s32 func_00177860(s32);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001b8e88(u64);
// why: accepted orchdr 001bc6a8 declares u8, but v3 (u8) compiled sltiu where the original compares with signed slti
extern "C" s8 func_001bc2a8(u16*, u32, u32);
extern "C" u32 func_00190128(void*);
extern "C" u64 func_001bd3e0(...);

s32 func_001d1070(u8* object) {
    u8 buffer[32];
    if (func_0017a538(object) || !func_001a2478(*(void**)(object + 1164))) return 0;
    u32 index = 0;
    u32* abilities = (u32*)func_00177860((s32)object);
    u16* list = D_0036e390;
    do {
        u8* entry = (u8*)func_001a80c8(*list);
        list++;
        u16 bit = *(u16*)(entry + 4);
        if (abilities[bit >> 5] & (1 << (bit & 0x1f))) {
            u32 id = func_001b8e88(*(u16*)(entry + 16));
            if (func_001bc2a8((u16*)id, (u32)object, 0) < 4) {
                func_00190128(buffer);
                func_001bd3e0(*(u32*)(object + 2884), 1, *(u16*)(entry + 16), buffer, 1, 0);
                return 1;
            }
        }
        index++;
    } while (index < 4);
    return 0;
}
