#include "../common/types.h"
extern "C" u8 D_0032e020[];
extern "C" s32 func_001d6ec8(void);
extern "C" u32 func_001d5b78(...);

u32 func_001d5cd0(void) {
    s32 limit = func_001d6ec8();
    u8* base = D_0032e020;
    // why: keeps the table base in its own register as in the original
    asm("" : "+r"(base));
    u8 count = base[4150];
    if (count < limit) {
        return func_001d5b78(0, count);
    }
    return 0;
}
