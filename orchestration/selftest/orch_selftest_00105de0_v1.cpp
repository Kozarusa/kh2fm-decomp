#include "../common/types.h"
extern "C" s32 func_00103b38();
extern "C" void func_00102080(u8*);
extern "C" s32 D_0032b984;
extern "C" s32 D_0033cbac;
extern "C" u8 D_0033cbb0;
extern "C" u8 D_0033cb80[];

void func_00105de0(s32 value) {
    if (func_00103b38() == 0 && D_0032b984 != 2) {
        D_0033cbac = value;
        D_0033cbb0 = 1;
        func_00102080(D_0033cb80);
    }
}
