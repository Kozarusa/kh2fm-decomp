#include "../common/types.h"
extern "C" s32 D_01c61958;
extern "C" void func_001c1130(u64);
extern "C" void func_001c11a8(s32);

// Preserve original registry aliases.
void func_00191938(s32 value) asm("_Z16wtarget_00191938jjjj");

void func_00191938(s32 value) {
    if (value != 0) {
        if (value >= 0) {
            if (value < 3) {
                func_001c1130(6);
            }
        }
    } else {
        func_001c11a8(6);
    }
    D_01c61958 = value;
}
