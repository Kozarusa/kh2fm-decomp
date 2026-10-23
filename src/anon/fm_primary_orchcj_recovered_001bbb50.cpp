#include "../common/types.h"
extern "C" u8* D_01d49320;

s32 func_001bbb50(void) {
    if (D_01d49320 == 0) {
        return 0;
    }
    s32 kind = *(*(u8**)(D_01d49320 + 8) + 8);
    switch (kind) {
    case 2:
    case 0x19:
    case 0x20:
        return 1;
    }
    return 0;
}
