#include "../common/types.h"
struct Block {
    u32 words[9];
};
extern "C" u32 func_001bbb08(...);
extern "C" u32 func_001ba158(void);
extern "C" Block func_00199098(s32 index); // why: accepted C++ definition fails isolated probe link (copied from accepted 001bbba8); same types, C linkage

s32 func_001d50b8(u8* event, Block* out) {
    if (event[0] != 16) {
        return 0;
    }
    if (func_001bbb08() != 225) {
        return 0;
    }
    u32* world = (u32*)func_001ba158();
    u32 other = event[1];
    u32 kind = *world;
    if (kind == other || ((kind == 18 || kind == 21) && (other == 18 || other == 21))) {
        *out = func_00199098(7);
        return 1;
    }
    return 0;
}
