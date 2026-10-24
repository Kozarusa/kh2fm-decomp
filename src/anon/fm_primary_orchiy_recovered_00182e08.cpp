#include "../common/types.h"
extern "C" s32 D_0034ed00;
extern "C" s32 D_01c60588[];
extern "C" s32 func_0019b328(s32, s32);

s32 func_00182e08(s32 value) {
    s32 index = 0;
    if (D_0034ed00 > 0) {
        s32* base = D_01c60588;
        // why: keeps the table base in its own register before the +8 field offset is added
        asm("" : "+r"(base));
        s32* entry = base + 2;
        do {
            s32 result = func_0019b328(*entry, value);
            entry += 3;
            if (result != 0) {
                return result;
            }
            index++;
        } while (index < D_0034ed00);
    }
    return 0;
}
