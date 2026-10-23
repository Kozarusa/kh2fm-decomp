#include "../common/types.h"
struct Target { s32 words[5]; };
struct Object {
    u8 pad0[2548];
    Target target;
    u8 pad1[2940 - 2568];
    u32 flags;
};
extern "C" Target D_003417b0;
extern "C" u32 func_00190128(void*);
extern "C" u32 func_00190140(s32);
extern "C" void func_0010d918(Object*, Target*, Target*);

u32 func_001125d8(Object* object, s32 mode, Target* source) {
    s32 flag;
    u32 result;
    switch (mode) {
    case 0:
        break;
    case 1:
        object->target = *source;
        break;
    case 2:
        object->target = D_003417b0;
        break;
    case 3:
        func_00190128(&object->target);
        func_0010d918(object, &object->target, &object->target);
        break;
    }
    flag = 0;
    result = func_00190140((s32)&object->target);
    if (result != 0) {
        flag = object->target.words[0] != 0;
    }
    if ((flag & 0xff) == 0) {
        result = func_00190128(&object->target);
    }
    if (mode == 0) {
        object->flags &= 0xfffeffff;
    } else {
        object->flags |= 0x10000;
    }
    return result;
}
