#include "../common/types.h"
extern "C" s32 D_0032b984;
extern "C" s32 D_0033cbac;
extern "C" u8 D_0033cbb0;
extern "C" u8 D_0033cb80[];
extern "C" s32 func_00103b38();
extern "C" void func_00102080(u8*);

void func_00105de0(s32 value) {
    if (func_00103b38() != 0) {
        return;
    }
    if ((D_0032b984 ^ 2) == 0) {
        return;
    }
    D_0033cbb0 = 1;
    D_0033cbac = value;
    func_00102080(D_0033cb80);
}

