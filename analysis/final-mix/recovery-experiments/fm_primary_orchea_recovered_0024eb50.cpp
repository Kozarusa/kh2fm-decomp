#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 D_0035ee18[];

void func_0024eb50() {
    u32* pointer = D_0035ee18;
    s32 count = 4;
    do {
        if (*pointer) {
            if (func_00139d78(*pointer) != 0) {
                u32 object = *pointer;
                ((void (*)(u32))(*(u32*)(*(u32*)object + 20)))(object);
            } else *pointer = 0;
        }
        --count;
        ++pointer;
    } while (count >= 0);
}
