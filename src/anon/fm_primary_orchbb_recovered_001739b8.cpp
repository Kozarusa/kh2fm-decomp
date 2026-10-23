#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_01c5f510;
extern "C" kn::FVector D_01c5f520;
extern "C" u8 D_00175548[];
extern "C" void func_002fd188(u8*);

void func_001739b8(u32* object) {
    if (D_01c5f510 == 0) {
        D_01c5f510 = 1;
        func_002fd188(D_00175548);
    }
    D_01c5f520 = *(kn::FVector*)(*(s32*)(*object + 4) + 0x850);
    object[0] = (u32)&D_01c5f520;
}
