#include "../common/types.h"
extern "C" u8* D_0035dcf0;
extern "C" void func_002278e0(u8*);
void func_00227078(void) {
    if (D_0035dcf0 != 0) {
        s32 offset = 0;
        s32 count = 127;
        do {
            u8* object = D_0035dcf0 + offset;
            s32 state = *(s32*)(object + 4);
            offset += 84;
            if (state != 0 && state == 2) func_002278e0(object);
            --count;
        } while (count >= 0);
    }
}