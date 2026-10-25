#include "../common/types.h"
extern "C" u8* D_00352ae0;
extern "C" u32 func_001dc9d0(u32);
extern "C" u32 func_001dc738(...);

void func_001dda78() {
    u8* object = D_00352ae0;
    while (object != 0) {
        u8* next = *(u8**)(object + 0x28);
        if (func_001dc9d0((u32)object) == 0) {
            u8 hidden = (*(s32*)(object + 8) >> 26) & 1;
            if (hidden == 0) {
                if (func_001dc738(object) == 0) {
                    s32 flags = *(s32*)(object + 8);
                    if ((flags & 0x100000) != 0) {
                        if (object != 0) {
                            (*(void (**)(u8*))(*(u8**)object + 4))(object);
                        }
                    } else {
                        u8 active = flags & 1;
                        if (active != 0) {
                            *(s32*)(object + 8) = flags | 0x100000;
                        }
                    }
                }
            }
        }
        object = next;
    }
}
