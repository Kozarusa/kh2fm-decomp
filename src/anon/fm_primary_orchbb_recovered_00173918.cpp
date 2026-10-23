#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s8 D_01c5f4f0;
extern "C" kn::FVector D_01c5f500;
extern "C" u8 D_00175540[];
extern "C" void func_002fd188(u8*);

void func_00173918(u32* object) {
    if (D_01c5f4f0 == 0) {
        D_01c5f4f0 = 1;
        func_002fd188(D_00175540);
    }
    D_01c5f500 = *(kn::FVector*)(*(s32*)(*object + 4) + 0x860);
    object[0] = (u32)&D_01c5f500;
}
