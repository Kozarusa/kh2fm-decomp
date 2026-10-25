#include "../common/types.h"
extern "C" s8* D_0035f1fc;
extern "C" int func_002953c8(...);        // copied from fm_primary_conditionfinish_recovered.cpp
extern "C" u32 func_002941d8(s32);        // copied from fm_primary_conditionfinish_recovered.cpp
// why: no recovered call site types these callees; no argument registers are set before the jal and v0 is used
extern "C" s32 func_00296f80(void);
extern "C" s32 func_00296f90(void);
// why: no recovered call site types this callee; a0..a2 are set before the tail jump (registry name RequestLoad(unsigned int, void*, unsigned int))
extern "C" void func_00293bd0(u32, s32, u32);

void func_00274cf0(s32 kind) {
    switch (kind) {
    case 0:
        func_00293bd0(1, 0, 0);
        return;
    case 1:
        func_00293bd0(2, func_00296f80(), 0);
        return;
    case 2:
        if (*D_0035f1fc == 1) {
            if (func_002941d8(func_002953c8(1)) != 0) {
                func_00293bd0(2, func_00296f90(), 0);
                return;
            }
        }
        func_00293bd0(2, func_002953c8(*D_0035f1fc) + 1, 0);
        return;
    case 13:
        func_00293bd0(2, func_002953c8(15) + 1, 0);
        return;
    }
}
