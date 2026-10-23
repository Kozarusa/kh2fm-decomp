#include "../common/types.h"
extern "C" u8* D_0035dcf0;
extern "C" void func_002278e0(u8*);

void func_00227078(void) {
    if (D_0035dcf0 != 0) {
        s32 active = 2;
        s32 offset = 0;
        s32 count = 127;
        do {
            u8* object = (u8*)(offset + (u32)D_0035dcf0);
            s32 state = *(s32*)(object + 4);
            offset += 84;
            if (state != 0) {
                if (state == active) func_002278e0(object);
            }
            --count;
        } while (count >= 0);
    }
}
