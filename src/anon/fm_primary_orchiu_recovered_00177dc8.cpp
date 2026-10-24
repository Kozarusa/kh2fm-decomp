#include "../common/types.h"
extern "C" u8 D_0034e958[];
extern "C" u8 D_01c5f530[];
extern "C" s32 D_0034e948;
extern "C" s32 func_0016a070(s32);
extern "C" u64 func_0016f6a0(...);
extern "C" void func_00175670(u8*, u8*, s32, s32);
extern "C" void func_00176168(u8*, u64, s32);
extern "C" u64 func_001781a8(...);
extern "C" u32 func_001818a0();
extern "C" s32 func_001a15d0(s32, s32);

u64 func_00177dc8(u8* object, u8* entry, s32 kind, s32 owner, s32 mode) {
    func_00175670(object, entry, 0, mode);
    *(s32*)(object + 2872) = owner;
    *(s32*)(object + 0) = (s32)D_0034e958;
    *(s32*)(object + 2896) = kind;
    *(s32*)(object + 2884) = (s32)D_01c5f530;
    *(s32*)(object + 2892) = -1;
    *(s32*)(object + 2876) = (s32)D_01c5f530;
    *(s32*)(object + 2880) = (s32)(D_01c5f530 + 0xac0);
    *(s32*)(object + 2904) = 0xffff;
    *(s32*)(object + 1416) |= 0x80;
    *(s32*)(object + 2888) = 0;
    *(s32*)(object + 2900) = 0;
    *(s32*)(object + 2912) = 0;
    *(u8*)(object + 2916) = 0;
    D_0034e948 = (s32)object;
    *(s32*)(object + 1896) |= 0x10;
    s32 player = func_001a15d0(func_0016a070((s32)object), *(s32*)(object + 2896));
    *(s32*)(object + 1164) = player;
    if (player != 0) {
        *(s32*)(player + 604) = (s32)object;
        *(u8*)(*(s32*)(object + 1164) + 431) = 0;
        if (func_001818a0() == 0) {
            *(s32*)(*(s32*)(object + 1164) + 592) |= 2;
            *(s32*)(*(s32*)(object + 1164) + 592) |= 4;
        }
    }
    u8* self = object;
    u64 weapon = func_0016f6a0(entry, 0);
    s32 slot = 0;
    if (weapon != 0) {
        func_00176168(self, weapon, slot);
    }
    s32 value = *(s32*)(object + 2896);
    s32 ranged = value != 0 && value < 7;
    asm("" : "+r"(ranged)); // why: original re-masks the flag word to a byte (andi 0xff) before testing it
    if ((u8)ranged || value == 10) {
        u8* self2 = object;
        u64 weapon2 = func_0016f6a0(entry, 1);
        s32 slot2 = 1;
        if (weapon2 != 0) {
            func_00176168(self2, weapon2, slot2);
        }
    }
    return func_001781a8(object);
}
