#include "../common/types.h"
extern "C" u8 D_00350758[];
extern "C" void func_0018d420(u32*);
extern "C" void func_00105110(u32*);

void func_001a4060(u32* object) {
    object[0] = (u32)D_00350758;
    *(u32*)object[0xb4] = 0;
    if ((s32)object != -208) {
        u32* cursor = object + 0xb4;
        u32* previous;
        do {
            previous = cursor;
            cursor = cursor - 4;
        } while (object + 0x34 != previous);
    }
    func_0018d420(object);
    func_00105110(object);
}
