#include "../common/types.h"
extern "C" u8 D_004f3820[];
extern "C" u8 D_00348698[];
extern "C" void func_0014c050(u8*);

void func_0015eaf8(s32 mode, s32 value) {
    if (value == 0xffff && mode == 1) {
        func_0014c050(D_004f3820);
    }
    if (value == 0xffff && mode == 0) {
        *(u8**)D_004f3820 = D_00348698;
    }
}
