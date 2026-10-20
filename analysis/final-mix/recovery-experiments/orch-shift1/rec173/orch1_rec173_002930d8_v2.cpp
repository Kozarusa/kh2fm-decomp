#include "../common/types.h"
extern "C" s16 D_0035f4e0;
extern "C" s32* D_0035f4dc;
void func_002930d8(void) {
    if (D_0035f4e0 != 0) {
        if (D_0035f4e0 > 1) {
            s32 index = 1;
            if (index < D_0035f4e0) {
                do {
                    s32* pointer = D_0035f4dc + index;
                    ++index;
                    pointer[-1] = *pointer;
                } while (index < *(volatile s16*)&D_0035f4e0);
            }
        }
        --D_0035f4e0;
    }
}

