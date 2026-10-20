#include "../common/types.h"
extern "C" u8* D_01d49320;
extern "C" bool func_001bb4a0(void);

bool func_001bb4b0(void) {
    bool result = false;
    if (func_001bb4a0()) {
        result = (*(u32*)(D_01d49320 + 4) & 4) == 0;
    }
    return result;
}