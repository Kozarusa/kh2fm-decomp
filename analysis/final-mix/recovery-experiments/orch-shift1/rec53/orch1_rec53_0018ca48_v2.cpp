#include "../common/types.h"

u32 func_0018ca48(u32 value) {
    if (value < 0x13) {
        switch (value) {
        case 1:
            return 1;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return value;
        }
    }
    return value;
}
