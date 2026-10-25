#include "../common/types.h"
// why: copied from fm_primary_orchea_recovered_00250748.cpp, which calls it
extern "C" u16 func_002891e8(...);
// why: copied from fm_primary_orcheb_recovered_00252618.cpp, which calls it
extern "C" s32 func_00252110(u32);
// why: copied from fm_primary_orchfc_recovered_002b5078.cpp, which calls it
extern "C" u32 func_00139d78(...);
// why: copied from fm_primary_orchce_recovered_002803e0.cpp, which calls it (its definition in fm_primary_width_recovered_02.cpp is void)
extern "C" void func_0028da70(u32, s32);
// why: no recovered source calls it; eight word arguments derived from a0-a3 and t0-t3, and its final call goes to func_001386e0 whose accepted definition (fm_scalar_recovered_00.cpp) is void
extern "C" void func_0028d8c0(u32, u32, u32, u32, u32, s32, s32, u32);
extern "C" u32 D_0035ee58;
extern "C" u8* D_0035ee7c;
extern "C" u32 D_0035ee60;
struct Entry { s16 field[3]; };
extern "C" Entry D_00372650[];

// why: void per DEVIATIONS #36: both exits are stale-b (final calls func_0028d8c0 and func_0028da70 chain into accepted-void definitions)

void func_00252540() {
    s32 index = func_00252110(func_002891e8(D_0035ee58));
    if (func_00139d78(D_0035ee7c) == 0) {
        func_0028d8c0((u32)D_0035ee7c, 30015, 3, 3, D_0035ee60,
                      D_00372650[index].field[0], D_00372650[index].field[2], 0);
        register u8* object asm("$13") = D_0035ee7c; // why: original keeps the reloaded object pointer in t5
        object[0x195] = 1;
        register u8* part asm("$14") = D_0035ee7c + 0x18; // why: original keeps the sub-object address in t6
        asm("" : "+r"(part)); // why: the original forms the +0x18 sub-object address before the +0xb8 access
        *(u32*)(part + 0xb8) |= 8;
    } else {
        func_0028da70((u32)D_0035ee7c, D_00372650[index].field[2]);
        *(s32*)(D_0035ee7c + 0x188) = -1;
    }
}
