#include "../common/types.h"
extern "C" u8* func_00192388(u8*);
extern "C" u64 func_00192440(...);

s32 func_00192b80(u8* text) {
    u32 count = 1;
    if (text != 0) {
        do {
            u64 control = func_00192440(text, 0);
            u32 previous = count;
            if (control != 0) {
                u32 value = *text;
                if (value == 2) {
                    ++count;
                } else if (value == 0) {
                    return (s32)count;
                }
            }
            text = func_00192388(text);
            if (previous != count) {
                if (text == 0 || (func_00192440(text, 0) != 0 && *text == 0)) {
                    --count;
                }
            }
        } while (text != 0);
    }
    return (s32)count;
}
