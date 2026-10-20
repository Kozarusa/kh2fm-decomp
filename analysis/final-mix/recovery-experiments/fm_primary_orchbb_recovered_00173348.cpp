#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_01c5f4d0;
extern "C" kn::FVector D_01c5f4e0;
extern "C" u8 D_00175538[];
extern "C" void func_002fd188(u8*);
extern "C" kn::FVector func_00143e50(u16, s32);

void func_00173348(u32* object) {
    if (D_01c5f4d0 == 0) {
        D_01c5f4d0 = 1;
        func_002fd188(D_00175538);
    }
    D_01c5f4e0 = func_00143e50(*(u16*)object, 0);
    object[0] = (u32)&D_01c5f4e0;
}
