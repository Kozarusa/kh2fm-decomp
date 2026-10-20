#include "../common/types.h"
extern "C" u8* volatile D_0035dcf8;
void func_00232db0(s32 value) {
    register s32 index asm("$11") = 0; // why: original loop index uses t3
    register s32 sentinel asm("$10") = -1; // why: original sentinel uses t2
    asm("" : "+r"(sentinel)); // why: retains sentinel register allocation
    asm("" : "+r"(index)); // why: preserves initialized loop index register
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
