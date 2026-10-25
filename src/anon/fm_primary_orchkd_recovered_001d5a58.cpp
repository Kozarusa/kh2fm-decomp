#include "../common/types.h"
struct Block {
    u32 words[9];
};
extern "C" u8 D_00352770;
extern "C" u8 D_00350379;
extern "C" bool func_001bb4a0(void);
extern "C" Block func_00199098(s32 index); // why: accepted C++ definition fails isolated probe link; same types as fm_primary_orchka_recovered_001bbba8.cpp, C linkage

// why: first argument register a0 is not read; kept so out stays in a1

s32 func_001d5a58(s32 unused, Block* out) {
    if (D_00352770 != 0) {
        if (D_00350379 == 0) {
            return 0;
        }
        if (!func_001bb4a0()) {
            goto copy; // why: original places the copy block after the epilogue
        }
    }
    return 0;
copy:
    *out = func_00199098(0);
    return 1;
}
