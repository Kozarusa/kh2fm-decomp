#include "../common/types.h"
extern "C" u8 D_00350758[];
extern "C" void func_0018d420(u32*);
extern "C" void func_00105110(u32*);

void func_001a4060(u32* object) {
    object[0] = (u32)D_00350758;
    *(u32*)object[0xb4] = 0;
    if ((s32)object != -208) {
        u8* cursor = (u8*)object + 720;
        u8* end = (u8*)object + 208;
        do {
            cursor -= 16;
        } while (end != cursor + 16);
    }
    func_0018d420(object);
    func_00105110(object);
}
