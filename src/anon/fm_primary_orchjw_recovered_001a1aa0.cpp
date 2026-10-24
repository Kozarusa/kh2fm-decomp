#include "../common/types.h"

void func_001a1aa0(u8* object, s32 delta) {
    s32 value = object[0x1b0] + delta;
    if (delta >= 0) {
        if (value >= 100) {
            do {
                if (object[0x1b1] < object[0x1b2]) {
                    object[0x1b1]++;
                }
                if (object[0x1b1] >= object[0x1b2]) {
                    value = 100;
                    break;
                }
                value -= 100;
            } while (value >= 100);
        }
    } else if (value < 0) {
        if (object[0x1b1] != 0) {
            object[0x1b1]--;
            value += 100;
        } else {
            value = 0;
        }
    }
    object[0x1b0] = value;
}
