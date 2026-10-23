#include "../common/types.h"
struct Inner { u8 pad[0x4]; };
struct Holder { s32* owner; s32 second; f32 scale; };
extern "C" u32 func_00188470(s32, s32, f32);

void func_00173e38(Holder* object) {
    func_00188470(object->owner[1] + 0x300, object->second, object->scale);
}
