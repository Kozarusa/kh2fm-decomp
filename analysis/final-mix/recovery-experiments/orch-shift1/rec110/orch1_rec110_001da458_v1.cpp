#include "../common/types.h"
extern "C" u32 func_001da3d8(s32,void*);

void func_001da458(s32 object, u32 value, s32* items, s32 count) {
    *(u32*)(object + 4) = value;
    u32 index = 0;
    do {
        u32* cursor = *(u32**)(object + 8);
        index = index + 1;
        *cursor = 0;
        *(u32**)(object + 8) = cursor + 1;
    } while (index < 4);
    if (count > 0) {
        do {
            func_001da3d8(object, items);
            count = count - 1;
            items = items + 1;
        } while (count != 0);
    }
}
