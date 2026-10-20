#include "../common/types.h"
extern "C" volatile s32 D_0035f404;
extern "C" s32* volatile D_0035f40c;
void func_0028d068(s32 value, s32 index) {
    if (index < 0) {
        if (D_0035f404 > 0) {
            s32 count = 0;
            asm("" : "+r"(count)); // why: keeps count initialization before loop setup
            while (1) {
                D_0035f40c[count] = value;
                ++count;
                if (count >= D_0035f404) break;
            }
        }
    } else {
        D_0035f40c[index] = value;
    }
}



