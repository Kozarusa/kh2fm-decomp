#include "../common/types.h"
extern "C" s32 D_00348704;
extern "C" void func_0013f230();
extern "C" void func_0013f378();
extern "C" void func_0013f498();
extern "C" void func_0015d540();

void func_0013f050(s32 value) {
    if (value < 0) {
        D_00348704 = value & 0x7fffffff;
    } else {
        D_00348704 = value;
        value &= 0x3fffffff;
        if (value == 1) {
            func_0013f230();
        } else if (value == 0) {
            func_0015d540();
        } else if (value == 2) {
            func_0013f378();
        } else if (value == 3) {
            func_0013f498();
        }
    }
}