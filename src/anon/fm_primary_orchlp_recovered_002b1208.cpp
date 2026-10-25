#include "../common/types.h"
extern "C" u32* D_0035f630;
extern "C" void func_002765e8(s32 index, s32 first, s32 second);
// why: no recovered declaration; a0 carries the slot number (28) and v0 is used as a signed position
extern "C" s32 func_00276608(s32);

// why: the only exit is a tail call into func_002765e8, whose accepted definition is void and whose instructions are store-only (stale-b), so no value flows out

void func_002b1208(u32 flags) {
    s32 count = 0;
    u32* entry = D_0035f630;
    for (s32 index = 0; index < 10; index++) {
        if (*entry & 0x2000000) count++;
        entry += 9;
    }
    s32 position = func_00276608(28);
    if (flags & 0x10000) {
        position = position + 1;
    } else {
        position = position - 1;
    }
    if (position < 0) {
        position = count - 1;
    } else if (position >= count) {
        position = 0;
    }
    func_002765e8(28, position, 0);
}
