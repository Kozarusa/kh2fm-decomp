#include "../common/types.h"
extern "C" volatile s32 D_0035f404;
extern "C" s32* volatile D_0035f40c;
void func_0028d068(s32 value, s32 index) {
    if (index < 0) {
        if (D_0035f404 > 0) {
            register s32 count asm("$13") = 0; // why: original count uses t5
            do {
                D_0035f40c[count] = value;
                ++count;
            } while (count < D_0035f404);
        }
    } else {
        D_0035f40c[index] = value;
    }
}


