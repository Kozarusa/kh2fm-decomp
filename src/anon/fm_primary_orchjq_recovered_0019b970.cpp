#include "../common/types.h"
extern "C" u8 D_01c62198[];
extern "C" void func_00199cd0(u32*);

// Preserve original registry aliases.
void func_0019b970(u32 flag, u32 priority) asm("_Z16wtarget_0019b970jjjj");

void func_0019b970(u32 flag, u32 priority) {
    if (priority == 0xffff) {
        if (flag == 1) {
            u8* base = D_01c62198;
            asm("" : "+r"(base)); // why: keeps the +4 cursor offset a separate addiu after the address pair
            u32* entry = (u32*)(base + 4);
            s32 count = 63;
            do {
                entry[0] = 0;
                count--;
                entry[3] = 0;
                entry[2] = 0;
                entry += 14;
            } while (count != -1);
        }
    }
    if (priority == 0xffff) {
        if (flag == 0) {
            u8* array = D_01c62198;
            if (array != 0) {
                u8* pointer = array + 3584;
                u8* base = array;
            loop:
                if (pointer == base) {
                    return;
                }
                pointer -= 56;
                func_00199cd0((u32*)pointer);
                goto loop;
            }
        }
    }
}
