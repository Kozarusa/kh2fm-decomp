#include "../common/types.h"
// why: copied from fm_primary_orchae_recovered_001398d0.cpp (hide call site)
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
// why: base pointer loaded with lw, then offset by 0x17d8 / 0x1970
extern "C" u8* D_0035f5b0;
// why: pointer loaded with lw and passed as a0 to both menu queries
extern "C" s16* D_0035f200;
// why: copied from fm_primary_orchag_recovered_0013e3b0.cpp
extern "C" s32 func_00139d78(u8*);
// why: copied from fm_primary_orchlb_recovered_0025d560.cpp
extern "C" s32 func_0028b040(s16* object);
// why: no non-variadic call site exists; a0 is the same object, result compared signed (slti)
extern "C" s32 func_0028afa8(s16* object);
// why: copied from fm_primary_orchae_recovered_001398d0.cpp
extern "C" u32 func_00139570(Node*);
// why: copied from fm_primary_orchae_recovered_00139858.cpp
extern "C" u32 func_00139580(Node*);

void func_0029daa0(void) {
    if (func_00139d78(D_0035f5b0 + 0x17d8) == 0) {
        return;
    }
    if (func_00139d78(D_0035f5b0 + 0x1970) == 0) {
        return;
    }
    s32 index = func_0028b040(D_0035f200);
    s32 count = func_0028afa8(D_0035f200);
    if (count < 2) {
        func_00139570((Node*)(D_0035f5b0 + 0x17d8));
        func_00139570((Node*)(D_0035f5b0 + 0x1970));
        return;
    }
    if (index == 0) {
        func_00139570((Node*)(D_0035f5b0 + 0x17d8));
        func_00139580((Node*)(D_0035f5b0 + 0x1970));
        return;
    }
    if (index >= count - 1) {
        func_00139580((Node*)(D_0035f5b0 + 0x17d8));
        func_00139570((Node*)(D_0035f5b0 + 0x1970));
    } else {
        func_00139580((Node*)(D_0035f5b0 + 0x17d8));
        func_00139580((Node*)(D_0035f5b0 + 0x1970));
    }
}
