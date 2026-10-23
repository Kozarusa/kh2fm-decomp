#include "../common/types.h"
extern "C" s32 D_00350dec;
extern "C" s32 func_001708f8(...);
extern "C" s32 func_001af7c0(s32 object, s32 value);

void func_001af778(s32* object) {
    object[1] = func_001708f8(D_00350dec, -1);
    object[13] = func_001af7c0((s32)object, object[12]);
}
