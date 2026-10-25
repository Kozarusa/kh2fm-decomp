#include "../common/types.h"
// Declarations copied from fm_primary_oneword_recovered_00253538.cpp.
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(s32);
extern "C" u8 func_00253918(void);
extern "C" u32 func_002539e8(s32,void*);
// Declaration copied from fm_primary_orchaz_recovered_00170dd0.cpp.
extern "C" void func_00102448(u64, u32);

u32 func_002593b8(s32 object, u64 task) {
    if (func_002538f8(object) != 0) {
        return 1;
    }
    if (func_00253928(object) == 0) {
        for (;;) {
            if (func_00253918() == 0 && func_002539e8(object, 0) == 0) {
                break;
            }
            func_00102448(task, 0);
        }
    }
    for (;;) {
        if (func_002538f8(object) != 0) {
            break;
        }
        func_00102448(task, 0);
    }
    return 1;
}
