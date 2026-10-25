#include "../common/types.h"
// Declarations copied from accepted fm_primary_oneword_recovered_001b72c0.cpp.
extern "C" s32 func_00176b58(...);
extern "C" int func_00177860(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_001a2a50(...);
extern "C" u32 func_001d02c8(...);
extern "C" u32 func_001d97c8(...);

void func_001ba598(s32* object) {
    if (object[1] != 0) {
        if (object[3] == 4) {
            func_001d02c8(object[2]);
        } else {
            s32 level = 100;
            s32 entry = func_00176b58(object[3]);
            if (func_0019ba60(entry)) {
                level = *(u16*)(func_00177860(entry) + 0x50) + 100;
            }
            if (func_001a2a50(object[1], object[4], object[3], level)) {
                if (object[3] == 1) {
                    func_001d97c8();
                }
            }
        }
        object[1] = 0;
    }
}
