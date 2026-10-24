#include "../common/types.h"
extern "C" s32 D_0035dcf8;

void func_00232db0(s32 value) {
    s32 index = 0;
    do {
        s32 offset = index * 64;
        index++;
        s32* pointer = (s32*)(offset + D_0035dcf8);
        if (pointer[0] != -1 && pointer[1] == value) {
            pointer[0] = -1;
            *(s32*)(offset + D_0035dcf8 + 4) = -1;
            *(s32*)(offset + D_0035dcf8 + 8) = 0;
            return;
        }
    } while (index < 64);
}
