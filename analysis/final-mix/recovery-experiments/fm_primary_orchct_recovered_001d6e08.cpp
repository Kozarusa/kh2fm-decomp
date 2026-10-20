#include "../common/types.h"
extern "C" u32 func_0016ed50(void*,s64,s64);

void func_001d6e08(s32 object) {
    s32 *pointer = (s32*)(object + 4);
    s32 count = 1;
    do {
        s32 item = *pointer;
        pointer++;
        if (item != 0) {
            func_0016ed50((void*)item, -1, 30);
        }
        count--;
    } while (count >= 0);
}
