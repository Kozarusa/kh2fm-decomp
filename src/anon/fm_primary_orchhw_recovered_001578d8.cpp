#include "../common/types.h"
extern "C" u32 func_00138c10(s32, u32);
extern "C" s32 func_00139d78(u8*);
extern "C" s32 func_0013c7d0(void);
extern "C" u32 func_00155d58(s32, s32);
extern "C" s32 func_00155f40(u8*);
extern "C" s32 func_00155fc0(u8*);
extern "C" u64 func_00157aa0(u8*);

void func_001578d8(u8* object) {
    if (object[32] != 0) {
        return;
    }
    if (func_0013c7d0() != 0) {
        u8* gauge = object + 12060;
        func_00138c10((s32)(object + 6704), func_00155d58((s32)object, 0));
        func_00138c10((s32)(object + 11648), func_00155f40(object));
        if (func_00139d78(gauge) != 0) {
            func_00138c10((s32)gauge, func_00155fc0(object));
        }
        func_00157aa0(object);
        object[32] = 1;
    } else if (object[12052] != 0) {
        object[32] = 1;
    }
}
