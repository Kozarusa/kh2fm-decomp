#include "../common/types.h"
extern "C" u8* volatile D_0035dcf8;
void func_00232db0(s32 value) {
    s32 index = 0;
    s32 sentinel = -1;
    do {
        s32 offset = index * 64;
        ++index;
        s32* pointer = (s32*)(offset + D_0035dcf8);
        if (pointer[0] != sentinel && pointer[1] == value) {
            pointer[0] = sentinel;
            *(s32*)(offset + D_0035dcf8 + 4) = sentinel;
            *(s32*)(offset + D_0035dcf8 + 8) = 0;
            return;
        }
    } while (index < 64);
}
