#include "../common/types.h"
extern "C" u32 func_00138c10(s32, u32);
extern "C" u32 func_00154408(s32, s32);
extern "C" u32 func_00155d58(s32, s32);
extern "C" u32 func_001581d0(u8*);
extern "C" u32 func_002ba358(void);
extern "C" u32 func_002ba390(void);

// Preserve original registry aliases.
u32 func_001575c0(u8* object) asm("_Z16wtarget_001575c0jjjj");

u32 func_001575c0(u8* object) {
    s32 value = **(s32**)(*(u8**)(object + 52) + 1164);
    *(s32*)(object + 40) = value;
    *(s32*)(object + 36) = value;
    if (object[15611] == 0) {
        object[15611] = 1;
    } else {
        func_00138c10((s32)(object + 6704), func_00155d58((s32)object, 0));
    }
    func_00138c10((s32)(object + 7116), func_00155d58((s32)object, 1));
    func_00138c10((s32)(object + 8352), func_00155d58((s32)object, 2));
    func_00154408((s32)(object + 64), *(s32*)(object + 24));
    u32 result = func_001581d0(object);
    if (result != 0) {
        result = func_002ba358();
        if (result != 0) {
            return func_002ba390();
        }
    }
    return result;
}
