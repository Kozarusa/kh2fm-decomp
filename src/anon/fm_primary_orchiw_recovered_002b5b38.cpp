#include "../common/types.h"
extern "C" u32 func_00287cd0(...);
extern "C" void func_00289038(...);
extern "C" void func_002890e0(...);
extern "C" u32 func_002891d0(...);
extern "C" u32 func_002891e8(...);
extern "C" u32 func_00289310(...);
extern "C" u32 func_00289358(...);
extern "C" u32 func_0028cf28(...);
extern "C" u32 func_0028d008(...);
extern "C" void func_002b5c30(...);
extern "C" s32 D_0035f64c;

u32 func_002b5b38(u64 object, s32 kind, u64 target) {
    u32 result;
    s32 current;
    result = func_00287cd0();
    if (result == 1 && (result = func_00289310(object), result != 0)) {
        func_002890e0(object, 1, 2, 0, 0xffffffffffffffff);
        current = func_002891e8(object);
        func_00289038(object, current, 1, 1, 2, 0, 0xffffffffffffffff);
        if (kind == 0xc && func_00289358(D_0035f64c) != 0) {
            func_002b5c30(0);
        }
        result = func_0028d008(target);
        if (result != 0) {
            s32 item = func_002891d0(object);
            return func_0028cf28(target, (u64)item);
        }
    }
    return result;
}
