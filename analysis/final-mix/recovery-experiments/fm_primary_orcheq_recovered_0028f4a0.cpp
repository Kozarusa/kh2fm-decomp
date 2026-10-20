#include "../common/types.h"
extern "C" u16 D_0035f470[];

void func_0028f4a0(u16* pointer) {
    s32 index = 0;
    do {
        D_0035f470[index] = pointer[index];
        ++index;
    } while (index < 3);
}
