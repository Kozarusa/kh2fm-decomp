#include "../common/types.h"
extern "C" u8* volatile D_0035dcf4;
void func_0022e368(u8* object) {
    register s32 count asm("$13") = 0; // why: original keeps loop count in t5
    register s32 offset asm("$12") = 0; // why: original keeps byte offset in t4
    do {
        u8* pointer = D_0035dcf4 + offset;
        ++count;
        if (*(s32*)(pointer + 4) == -1) {
            *(s32*)(pointer + 4) = *(s16*)(object + 8);
            asm volatile("" ::: "memory"); // why: keeps store order
            *(s32*)(D_0035dcf4 + offset) = *(s16*)(object + 10);
            asm volatile("" ::: "memory"); // why: keeps store order
            *(u16*)(D_0035dcf4 + offset + 8) = *(u16*)(object + 12);
            asm volatile("" ::: "memory"); // why: keeps store order
            *(u16*)(D_0035dcf4 + offset + 46) = *(u16*)(object + 4);
            asm volatile("" ::: "memory"); // why: keeps store order
            *(s32*)(D_0035dcf4 + offset + 12) = 0;
            return;
        }
        offset += 52;
    } while (count < 96);
}
