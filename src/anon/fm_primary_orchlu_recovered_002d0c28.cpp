#include "../common/types.h"
struct Object {
    u8 pad0[0x108];
    u32 flags;
    u8 pad1[0xaf0 - 0x10c];
    u32 lflag[7];
    u32 effect;
    s32 count;
};
extern "C" void func_001dc818(s32);
extern "C" bool func_002cf270(u32*, u32);
extern "C" s32 func_002cf280(u32*, u32, u32);
extern "C" void func_002cf2b0(u32*, u32);
extern "C" void func_002d0cf0(Object*);

void func_002d0c28(Object* object) {
    if (object->count == 0) {
        if (object->effect != 0) {
            func_001dc818(object->effect);
            object->effect = 0;
        }
        object->flags |= 3;
        func_002cf280(object->lflag, 0x2000, 0);
    }
    object->count = object->count + 1;
    if (func_002cf270(object->lflag, 0x4000) && object->count < 5) {
        return;
    }
    func_002cf2b0(object->lflag, 0x2000);
    func_002cf2b0(object->lflag, 0x4000);
    func_002d0cf0(object);
}
