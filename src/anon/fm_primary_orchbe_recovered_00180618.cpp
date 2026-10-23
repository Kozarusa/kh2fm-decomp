#include "../common/types.h"
extern "C" s64 func_00180cd0(s32);

typedef f32 (*QueryFn)(void*);
struct VTable {
    u8 pad[0x1c];
    QueryFn query;
};
struct Target {
    VTable** vtable;
};

// Preserve original registry aliases.
u32 func_00180618(u8* object) asm("_Z16ctarget_00180618jjjj");

u32 func_00180618(u8* object) {
    u32 result = 0;
    if (func_00180cd0((s32)object) == 0) {
        u32 positive = 0.0f < *(f32*)(object + 0x34);
        if ((positive & 0xff) == 0) {
            void* target = *(void**)(object + 0xc);
            f32 value = (*(VTable**)target)->query(target);
            if (value <= *(f32*)(object + 0x30)) {
                result = 1;
            }
        }
    }
    return result;
}
