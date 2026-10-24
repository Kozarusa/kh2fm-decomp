#include "../common/types.h"
extern "C" u8 D_01c6cae0[];
extern "C" u32 D_01c6cb00[];
extern "C" void func_001ddd10(u32);
extern "C" void func_001ddd88(u32);

// Preserve original registry aliases.
void func_001a3d70(s32 initialize, s32 priority) asm("_Z16wtarget_001a3d70jjjj");

void func_001a3d70(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1) {
        func_001ddd10((u32)D_01c6cae0);
    }
    if (priority == 0xffff && initialize == 1) {
        u32* base = D_01c6cb00;
        u32* cursor = base;
        s32 count = 3;
        do {
            *cursor = 0;
            count--;
            cursor++;
        } while (count >= 0);
        base[4] = 0;
    }
    if (priority == 0xffff && initialize == 0) {
        func_001ddd88((u32)D_01c6cae0);
    }
}
