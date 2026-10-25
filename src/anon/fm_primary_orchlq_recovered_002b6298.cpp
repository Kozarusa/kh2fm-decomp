#include "../common/types.h"
// Declarations copied from the accepted same-shape sibling fm_primary_orchlb_recovered_002593b8.cpp.
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(s32);
extern "C" u8 func_00253918(void);
extern "C" u32 func_002539e8(s32,void*);
extern "C" void func_00102448(u64, u32);

s32 func_002b6298(u64 task) {
    if (func_002538f8(1) != 0) {
        return 1;
    }
    if (func_00253928(1) == 0) {
        for (;;) {
            if (func_00253918() == 0 && func_002539e8(1, 0) == 0) {
                break;
            }
            func_00102448(task, 0);
        }
    }
    for (;;) {
        if (func_002538f8(1) != 0) {
            break;
        }
        func_00102448(task, 0);
    }
    return 1;
}
