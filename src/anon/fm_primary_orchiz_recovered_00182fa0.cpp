#include "../common/types.h"
extern "C" u8 D_01c60588[];
extern "C" void func_001828b8(u8*);

// Preserve original registry aliases.
void func_00182fa0(u32 flag, u32 priority) asm("_Z16wtarget_00182fa0jjjj");

void func_00182fa0(u32 flag, u32 priority) {
    if (priority == 0xffff) {
        if (flag == 1) {
            u8* entry = D_01c60588;
            s32 count = 63;
            do {
                *(s32*)(entry + 4) = 0;
                count--;
                entry += 12;
            } while (count != -1);
        }
    }
    if (priority == 0xffff) {
        if (flag == 0) {
            u8* array = D_01c60588;
            if (array != 0) {
                u8* pointer = array + 768;
                u8* base = array;
            loop:
                if (pointer == base) {
                    return;
                }
                pointer -= 12;
                func_001828b8(pointer);
                goto loop;
            }
        }
    }
}
