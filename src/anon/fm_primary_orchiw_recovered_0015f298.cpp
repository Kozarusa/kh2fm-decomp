#include "../common/types.h"
extern "C" u8 D_0034c70c;
extern "C" u8 D_0034c6f0[];
extern "C" void func_001431c0();
extern "C" u32 func_00161228();
extern "C" u32 func_001de4b0(s32, s32, s32);
extern "C" bool func_001dc9e0(s32);
extern "C" void func_001dc698(s32, s32);

u32 func_0015f298() {
    u32 entry = 0;
    u32 last;
    s32 index;
    func_001431c0();
    u32 result = func_00161228();
    if (D_0034c70c != 1) {
        return result;
    }
    goto scan;
done:
    return last;
scan:
    for (index = 0; index < 64; index++) {
        while ((entry = last = func_001de4b0((s32)D_0034c6f0, index, entry)) != 0) {
            if (func_001dc9e0(entry)) {
                func_001dc698(entry, 0);
            }
        }
    }
    goto done;
}
