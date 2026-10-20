#include "../common/types.h"
extern "C" u8 D_0035de14;
extern "C" u8 D_0035de15;
void func_00232110(u8* object) {
    D_0035de14 = 1;
    s32 value = *(s16*)(object + 6);
    if(value == 0) {
        D_0035de15 = 0;
        return;
    }
    if(value == 1) {
        D_0035de15 = value;
        return;
    }
}
