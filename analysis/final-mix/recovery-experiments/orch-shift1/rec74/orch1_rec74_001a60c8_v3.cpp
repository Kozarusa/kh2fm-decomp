#include "../common/types.h"
struct Entry {
    u8 pad[40];
    s32 value;
    // 44 bytes total
};
extern "C" Entry D_00350800[];
extern "C" s32 func_001a6658(s32);
extern "C" u32 func_001bdff0(void);

u32 func_001a60c8(void) {
    s32 index;
    for (index = 0; index < 6; index++) {
        D_00350800[index].value = func_001a6658(index);
    }
    return func_001bdff0();
}
