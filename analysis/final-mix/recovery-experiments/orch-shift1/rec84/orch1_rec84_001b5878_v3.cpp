#include "../common/types.h"
extern "C" u32 func_001d1d68(s32);

void func_001b5878(s32 object) {
    if ((*(u32*)(object + 0xb4) & 4) != 0) {
        func_001d1d68(object + 0xa8);
    }
}
