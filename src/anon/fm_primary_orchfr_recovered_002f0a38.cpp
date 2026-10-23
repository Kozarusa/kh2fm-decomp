#include "../common/types.h"
extern "C" u32 func_0017f5f8(s32, s32, s32, f32, f32);

struct Args {
    s32 base;
    s32 index;
    f32 value;
};

u32 func_002f0a38(Args* args) {
    return func_0017f5f8(args->base + 0x140, args->index, 0, args->value, 0.0f);
}
