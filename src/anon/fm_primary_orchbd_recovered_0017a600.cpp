#include "../common/types.h"
extern "C" u32 func_00190140(s32);
extern "C" u32 func_00190f80(s32, s32, f32);
extern "C" u32 func_0019ca90(s32, s32, s32);
extern "C" u32 func_0019d358(s32);

void func_0017a600(s32 object) {
    s32 target = object + 0x9f4;
    if (func_00190140(target) == 0) {
        func_00190f80(target, object, 0.0f);
        if (func_00190140(target) != 0) {
            func_0019ca90(*(s32*)(object + 0xb40), 1, target);
            func_0019d358(*(s32*)(object + 0xb40));
        }
    }
}
