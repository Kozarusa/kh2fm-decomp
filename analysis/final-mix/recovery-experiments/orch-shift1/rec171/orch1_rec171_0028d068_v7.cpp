#include "../common/types.h"
extern "C" volatile s32 D_0035f404;
extern "C" s32* volatile D_0035f40c;
void func_0028d068(s32 value, s32 index) {
    if (index < 0) {
        if (D_0035f404 > 0) {
            s32 count = 0;
            asm("" : "+r"(count)); // why: keeps count initialization before loop setup
            s32* pointer = D_0035f40c;
            do {
                pointer[count] = value;
                ++count;
            } while (count < D_0035f404 && (pointer = D_0035f40c, true));
        }
    } else {
        D_0035f40c[index] = value;
    }
}



