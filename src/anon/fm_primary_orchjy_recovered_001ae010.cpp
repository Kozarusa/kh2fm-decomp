#include "../common/types.h"
struct Names {
    s32 entry[2];
};
extern "C" Names D_0036d850;
extern "C" s32 func_002ff1a4(void*, s32);
extern "C" char* func_002ff8b0(char*, s32);

s32 func_001ae010(char* path) {
    Names names = D_0036d850;
    char* dot = func_002ff8b0(path, 46);
    if (dot != 0) {
        register char* ext asm("$16") = dot + 1; // why: original keeps the extension pointer in s0
        s32 index = 0; // why: initialising the counter before the cursor gives the original s2-then-s1 setup order
        register s32* cursor asm("$17") = names.entry; // why: original walks the name table with s1
        for (; index < 2; index++) {
            if (func_002ff1a4(ext, *cursor++) == 0) {
                return 1;
            }
        }
    }
    return 0;
}
