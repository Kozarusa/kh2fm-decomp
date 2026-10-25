#include "../common/types.h"

extern "C" u32 func_00160fd0(u32);
extern "C" u32 func_00161000(u32);

void func_002c1cb0(const u8* color, s32 mode) {
    switch (mode) {
    case 1:
        func_00160fd0(color[0]);
        func_00161000(color[1]);
        func_00161000(color[2]);
        break;
    case 2:
        func_00161000(color[0]);
        func_00160fd0(color[1]);
        func_00160fd0(color[2]);
        break;
    default:
        func_00161000(color[0]);
        func_00161000(color[1]);
        func_00161000(color[2]);
        break;
    }
}
