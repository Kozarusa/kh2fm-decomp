#include "../common/types.h"
extern "C" u8* volatile D_0035dcf4;
void func_0022e368(u8* object) {
    register s32 count asm("$13") = 0; // why: original keeps loop count in t5
    s32 offset = 0;
    do {
        u8* pointer = D_0035dcf4 + offset;
        ++count;
        if (*(s32*)(pointer + 4) == -1) {
            *(s32*)(pointer + 4) = *(s16*)(object + 8);
            *(s32*)(D_0035dcf4 + offset) = *(s16*)(object + 10);
            *(u16*)(D_0035dcf4 + offset + 8) = *(u16*)(object + 12);
            *(u16*)(D_0035dcf4 + offset + 46) = *(u16*)(object + 4);
            *(s32*)(D_0035dcf4 + offset + 12) = 0;
            return;
        }
        offset += 52;
    } while (count < 96);
}
