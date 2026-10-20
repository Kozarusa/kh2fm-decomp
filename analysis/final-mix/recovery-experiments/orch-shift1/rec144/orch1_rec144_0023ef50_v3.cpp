#include "../common/types.h"
extern "C" s32 func_00236ca8(...);
void func_0023ef50(u8* object) {
    s32 count = *(s32*)(object + 40);
    s32 index = 0;
    if (count > 0) {

        do {
            s32 result = func_00236ca8(*(s32*)(object + 88), index);
            index++;
            *(u8*)(result + 400) = 1;
        } while (index < count);
    }
}

