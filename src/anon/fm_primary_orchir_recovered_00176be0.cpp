#include "../common/types.h"
extern "C" u32 func_001a3a78(void);
extern "C" u32 func_001de168(...);

void func_00176be0(f32 value, u32 object) {
    u32 system;
    u32 handle;
    s32 base;
    f32 current;
    base = object;
    if (*(s32*)(base + 0xae4) == 0) {
        if (!(*(u32*)(base + 0x160) & 0x4000)) {
            system = func_001a3a78();
            handle = func_001de168(system, 6, 0, 1, 0x2714, object);
            *(u32*)(base + 0xae4) = handle;
            *(f32*)(base + 0xae8) = value;
            return;
        }
        current = *(f32*)(base + 0xae8);
    } else {
        current = *(f32*)(base + 0xae8);
    }
    if (current < value) {
        *(f32*)(base + 0xae8) = value;
    }
}
