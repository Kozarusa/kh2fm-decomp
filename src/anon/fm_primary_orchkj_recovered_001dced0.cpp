#include "../common/types.h"
// why: vtable slot 1 has no accepted declaration; its result is never used (ruling #36: stale, target is void)
typedef void (*Release)(u8*, s32);
extern "C" u8* D_01d5bb00;
extern "C" s32 D_01d5bb04;
extern "C" s32 D_01d5bb08;
extern "C" u8 D_00352af0;
extern "C" void func_001dcfb0(); // why: accepted definition fm_primary_orchcy_recovered_001dcfb0.cpp has C++ linkage and fails the isolated probe link; types kept, extern "C" added
extern "C" void func_001dd208(u8); // why: no accepted call site or definition (only an auto80 decls placeholder); parameter from a0 and its entry andi 0xff, body tails into store-only 001e70a0 so it returns nothing

void func_001dced0(void) {
    func_001dcfb0();
    if (D_01d5bb04 != 0) {
        u8* owner = D_01d5bb00;
        (*(Release*)(*(u8**)owner + 4))(owner, D_01d5bb04);
        D_01d5bb04 = 0;
    }
    if (D_01d5bb08 != 0) {
        u8* owner = D_01d5bb00;
        (*(Release*)(*(u8**)owner + 4))(owner, D_01d5bb08);
        D_01d5bb08 = 0;
    }
    func_001dd208(0);
    D_00352af0 = 0;
}
