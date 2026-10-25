#include "../common/types.h"
struct Object {
    s32 (**vtable)(Object*);
};
extern "C" u8* D_00361f60;
extern "C" void func_00180c88(s32, s32, f32);
extern "C" bool func_00197920(void);
extern "C" void func_001d86a0(s32, s32);
extern "C" void func_002dd4f8(u8*);

void func_002e0698(Object* object, s32 other) {
    func_00180c88(other + 320, object->vtable[12](object), 0.0f);
    u8* state = D_00361f60;
    if (*(s32*)(state + 0x8074) > 0 && *(s32*)(state + 0x80) == 2 && !func_00197920()) {
        func_001d86a0(-1, 1);
    }
    // why: void; the original tail-jumps into func_002dd4f8, whose own instructions write no v0
    // (it only stores zero after func_001d90e0), and no accepted definition of it exists, so no typed return is invented
    func_002dd4f8(state);
}
