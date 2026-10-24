#include "../common/types.h"
struct Info {
    u8 pad0[8];
    u32 flags;
};
struct Object {
    u8 pad0[0xc];
    Info* info;
    u8 pad10[0x108 - 0x10];
    u32 flags108;
    u8 pad10c[0x160 - 0x10c];
    u32 flags160;
};

extern "C" f32 func_0016a0a0();
extern "C" bool func_001c0cd8(Object*);
extern "C" u32 func_0019c6f0(Object*);

s32 func_0019bb98(Object* object) {
    s32 result = 0;
    if (func_0016a0a0() == 0.0f || (object->flags108 & 4) != 0 || (object->flags160 & 0x2000000) != 0 ||
        func_001c0cd8(object) || (object->info->flags & 4) != 0 || func_0019c6f0(object) != 0) {
        result = 1;
    }
    return result;
}
