#include "../common/types.h"

s32 func_00154ee8(u8* object) {
    switch (*(s32*)(object + 0x18)) {
    case 0:
        return 0x48;
    case 1:
        return 0x43;
    case 2:
        return 0x48;
    }
    return 0x48;
}