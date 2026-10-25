#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
// why: layout copied from the accepted callee definition fm_primary_orchcg_recovered_001b2520.cpp
struct Ring {
    s32 size;
    s32 high;
    s32 index;
    s32 pad;
    s32 pad2;
    Quad* items;
};
struct __attribute__((aligned(16))) Point { f32 x; f32 y; f32 z; f32 w; };
extern "C" f32 D_0036d9d0;
extern "C" s32 func_00182e08(s32);               // copied from accepted fm_primary_orchiz_recovered_00184eb8.cpp
extern "C" u32 func_001050d8(u64);               // copied from accepted fm_primary_addresspair_recovered_001a6c60.cpp
extern "C" void func_001b2380(Ring*, u32);
// why: exact types of the accepted definition fm_primary_orchcg_recovered_001b2520.cpp; extern "C" because the C++ linkage declaration fails the isolated probe link (orch1_lg262_001b2618_v2)
extern "C" void func_001b2520(Ring* ring, Quad* value);

Ring* func_001b2618(s32 value) {
    s32 index = 0;
    u8* list = (u8*)func_00182e08(value);
    Ring* ring = (Ring*)func_001050d8(28);
    func_001b2380(ring, *(u16*)(list + 2));
    if (*(u16*)(list + 2) != 0) {
        f32* address = &D_0036d9d0;
        asm("" : "+r"(address)); // why: original forms the full address before the lwc1
        f32 w = *address;
        u8* entry = list;
        do {
            Point point;
            point.x = *(f32*)(entry + 8);
            point.y = *(f32*)(entry + 12);
            point.z = *(f32*)(entry + 16);
            point.w = w;
            index++;
            entry += 12;
            func_001b2520(ring, (Quad*)&point);
        } while (index < *(u16*)(list + 2));
    }
    return ring;
}
