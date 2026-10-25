#include "../common/types.h"

extern "C" bool func_001c0cd8(s32);
extern "C" void func_001c0e60(s32);
extern "C" void func_0016bd60(u8*, s32);

// Return type s32* as in the accepted callers fm_primary_orchba_recovered_00171c60.cpp and
// fm_primary_orchkc_recovered_001cedc0.cpp; the original returns object + 0x570 in v0.

// Preserve original registry aliases.
s32* func_001c0d38(u8* object, u8* parent, u32 kind, u32 flags) asm("_Z16u_tail4_001c0d38jjjj");

s32* func_001c0d38(u8* object, u8* parent, u32 kind, u32 flags) {
    if (func_001c0cd8((s32)object)) {
        func_001c0e60((s32)object);
    }
    *(u16*)(object + 0x574) = kind;
    *(u8**)(object + 0x570) = parent;
    *(u16*)(object + 0x576) = flags;
    asm volatile("" ::: "memory"); // why: keeps store order (the original stores the header before loading the owner)
    s32 marked = 0;
    if ((*(u32*)(*(u8**)(object + 0xc) + 8) & 2) != 0 || (*(u32*)(object + 0x160) & 0x40) != 0) {
        marked = 1;
    }
    *(u32*)(object + 0x57c) = 0;
    *(u32*)(object + 0x578) = marked ? 5 : 0;
    // why: VU macro store of vf0, same sqc2 $vf0 sequence as accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    asm volatile("sqc2 $vf0,0(%0)" : : "r"(object + 0x540) : "memory");
    if ((flags & 2) == 0) {
        // why: original zero-fills the vector with the VU macro, same sequence as accepted fm_primary_orchfj_recovered_002c17d8.cpp
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(object + 0x550) : "memory");
        *(u32*)(object + 0x7f8) |= 8;
    }
    func_0016bd60(object, 3);
    u8** list = (u8**)(parent + 0x760);
    u8* node = object + 0x670;
    if (list[1] == 0) {
        list[1] = node;
        list[0] = node;
        *(u8**)(object + 0x75c) = 0;
    } else {
        *(u8**)(list[1] + 0xec) = node;
        *(u8**)(object + 0x75c) = 0;
        list[1] = node;
    }
    if (*(u32*)(object + 0x80c) == 0) {
        *(u32*)(object + 0x60c) = *(u32*)(parent + 0x80c);
    } else if (*(u32*)(parent + 0x80c) == 0) {
        *(u32*)(parent + 0x60c) = *(u32*)(object + 0x80c);
    }
    return (s32*)(object + 0x570);
}
