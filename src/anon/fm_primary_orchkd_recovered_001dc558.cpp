#include "../common/types.h"
// why: exact types of the accepted definition (tiny_auto80_queue func_001e6b90), C linkage like its callers
extern "C" u32 func_001e6b90(void);
// why: return type bool as in every accepted declaration; no accepted call site, and the accepted (u32,u64,u32,u8,u32) parameters lack the float while (...) promotes f32 to double, so parameters follow the callee's registers (a0-a3 words stored with sw/sb, f12 stored with swc1)
extern "C" bool func_001e6c40(u32, u32, u32, u32, f32);
extern "C" u32 func_001e2c00(s64);
extern "C" u32 func_001e6c00(u64);

bool func_001dc558(u8* object, f32 scale) {
    bool ok = true;
    if (*(s32*)(object + 4) != 4) {
        u32 manager = func_001e6b90();
        *(u32*)(object + 0x1c) = manager;
        ok = func_001e6c40(manager, *(u32*)(object + 0x14), *(u32*)(object + 0x18), *(u32*)(object + 0x10), scale) != 0;
    }
    if (!ok && *(s32*)(object + 0x1c) != 0) {
        func_001e2c00(*(s32*)(object + 0x1c));
        func_001e6c00(*(s32*)(object + 0x1c));
        *(u32*)(object + 0x1c) = 0;
    }
    return ok;
}
