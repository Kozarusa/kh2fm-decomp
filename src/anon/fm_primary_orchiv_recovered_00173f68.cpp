#include "../common/types.h"
struct __attribute__((aligned(16))) Vec4 {
    f32 x; f32 y; f32 z; f32 w;
};
struct Owner { s32 pad; s32 link; };
union Holder { Owner* owner; f32 value; };
extern "C" Vec4* func_0016c028(s32);
extern "C" f32 func_00184a90(s32);

f32 func_00173f68(Holder* object) {
    s32 link = object->owner->link;
    f32 height = func_00184a90(link);
    f32 result;
    if (0.0f < height - func_0016c028(link)->y) {
        result = func_00184a90(link) - func_0016c028(link)->y;
    } else {
        result = 0.0f;
    }
    f32 value = -result;
    object->value = value;
    return value;
}
