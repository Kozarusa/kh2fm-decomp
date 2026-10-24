#include "../common/types.h"
union Info {
    u32 word;
    u16 half[2];
};
struct Object {
    u32 flags;
    u8 pad[56];
    Info* info;
};
extern "C" u32 func_00170320(s32);
extern "C" s32 func_00196e88(f32, u32, s32, s32);

s32 func_00197318(Object* object) {
    func_00170320(2000);
    u32 flags = object->flags;
    object->flags = flags | 1;
    if ((u8)((object->info->half[1] >> 1) & 1) != 0) {
        return func_00196e88(0.0f, (u32)object, 3, 0);
    }
    object->flags = flags | 3;
    return func_00196e88(0.0f, (u32)object, 4, 0);
}
