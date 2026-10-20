#include "../common/types.h"
extern "C" u8* D_01d49320;

s32 func_001bbb50(void) {
    if (D_01d49320 == 0) {
        return 0;
    }
    u8 kind = *(*(u8**)(D_01d49320 + 8) + 8);
    if (kind != 0x19) {
        if (kind < 0x1a) {
            if (kind != 2) {
                return 0;
            }
        } else if (kind != 0x20) {
            return 0;
        }
    }
    return 1;
}
