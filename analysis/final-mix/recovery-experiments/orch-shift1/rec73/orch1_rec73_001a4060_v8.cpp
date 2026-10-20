#include "../common/types.h"
extern "C" u8 D_00350758[];
extern "C" void func_0018d420(u32*);
extern "C" void func_00105110(u32*);

void func_001a4060(u32* object) {
    object[0] = (u32)D_00350758;
    *(u32*)object[0xb4] = 0;
    if ((s32)object != -208) {
        // why: original keeps the cursor in t7 and the end in t6
        register u32* cursor asm("$15") = object + 0xb4;
        register u32* end asm("$14") = object + 0x34;
        while (1) {
            if (end == cursor) {
                cursor = cursor - 4;
                break;
            }
            cursor = cursor - 4;
        }
    }
    func_0018d420(object);
    func_00105110(object);
}
