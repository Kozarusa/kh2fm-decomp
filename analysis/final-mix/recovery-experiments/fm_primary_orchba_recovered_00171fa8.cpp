#include "../common/types.h"
extern "C" u64 func_0016cf00(...);
extern "C" void func_00177460(s32, u64);
extern "C" s32 D_0034d8a0;

void func_00171fa8(s32* object) {
    s32 count = 1;
    s32 owner = ((s32*)object[0])[1];
    s32 args[2];
    args[0] = owner;
    if (object[2] != 0) {
        args[1] = object[2];
        count = 2;
    }
    u64 result = func_0016cf00(D_0034d8a0, 0, object[1], args, count);
    func_00177460(owner, result);
}
