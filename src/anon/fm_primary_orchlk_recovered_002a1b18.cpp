#include "../common/types.h"
extern "C" s8* D_0035f5d4;
// why: no argument register is set before the jal and its result is unused
extern "C" void func_002a18d0(void);
// why: a0 is the halfword loaded with lhu; v0 is tested against zero
extern "C" s32 func_002a9e98(u16);
extern "C" bool func_002a9f50(...);

s32 func_002a1b18() {
    s32 index;
    s32 result;
    u16 id;

    index = 0;
    result = 0;
    func_002a18d0();
    if (D_0035f5d4[0] > 0) {
        do {
            id = *(u16*)(D_0035f5d4 + index * 8 + 80);
            index++;
            if (func_002a9e98(id) != 0) {
                result = 1;
                if (!func_002a9f50(id)) {
                    break;
                }
                result = 2;
            }
        } while (index < D_0035f5d4[0]);
    }
    return result;
}
