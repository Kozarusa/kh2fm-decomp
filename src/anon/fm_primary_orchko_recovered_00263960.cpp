#include "../common/types.h"
struct Allocator;
typedef u32* (*AllocateFn)(Allocator*, s32, s32);
struct Allocator { AllocateFn* table; };
extern "C" s32 D_0035f0b8;
extern "C" s32 D_0035f0bc;
extern "C" s32 D_0035f0c0;
extern "C" u32* volatile D_0035f0dc; // why: volatile keeps the vtable store before this global store
extern "C" u8* D_00347f80;
extern "C" char D_00347e60;
extern "C" char D_0035f360;
// why: no recovered source calls or defines it; two arguments derived from a0/a1 set from a3/t0
extern "C" void func_00263bb0(u32, u32);
extern "C" void func_00239700(u32);

void func_00263960(s32 first, s32 second, s32 third, u32 fourth, u32 fifth) {
    D_0035f0b8 = first;
    D_0035f0bc = second;
    D_0035f0c0 = third;
    func_00263bb0(fourth, fifth);
    Allocator* allocator = *(Allocator**)(D_00347f80 + 0x14);
    u32* object = allocator->table[0](allocator, 0x1cc, 0);
    object[3] = 0;
    object[0] = (u32)&D_00347e60;
    func_00239700((u32)(object + 6));
    object[0x66] = 0;
    *(volatile u32*)object = (u32)&D_0035f360; // why: volatile keeps the vtable store before the global store
    D_0035f0dc = object;
}
