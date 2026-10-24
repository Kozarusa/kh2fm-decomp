#include "../common/types.h"
extern "C" u8 D_003625e0[];
extern "C" void func_002d0f38(u32*);
extern "C" u32 func_00105110(u8*);

u32 func_00325498(u32* object) {
    *object = (u32)D_003625e0;
    if ((s32)object != -3232) {
        // why: original keeps loop start in t7
        register u8* cursor asm("$15") = (u8*)object + 3360;
        // why: original keeps loop end in t6
        register u8* end asm("$14") = (u8*)object + 3232;
        // why: original keeps an empty reverse walk over eight 16-byte members (shape of accepted sibling 001a4060)
        while (1) {
            if (end == cursor) {
                cursor -= 16; // why: original also steps the cursor on the exit path (branch delay slot)
                break;
            }
            cursor -= 16;
        }
    }
    func_002d0f38(object);
    return func_00105110((u8*)object);
}
