#include "../common/types.h"
struct UnitEntry {
    u16 kind : 2;
    u16 id : 13;
    u16 spare : 1;
};
extern "C" bool func_00181500(...);
extern "C" u32 func_00181178(...);
extern "C" u32 func_0019b2b0(...);
extern "C" u32 func_0019b2d8(...);
extern "C" u32 func_001a6c90(u32);
extern "C" u32 func_001a8258(...);
extern "C" u32 func_001a8438(...);

void func_00198ee8(u8* object) {
    s32 index;

    if (*(s32*)(object + 0x8) != 0xffff) {
        if (!func_00181500(*(s32*)(object + 0x8))) {
            func_00181178(*(s32*)(object + 0x8));
        }
    }
    if (*(s32*)(object + 0xc) >= 0) {
        func_001a6c90(*(s32*)(object + 0xc));
    }
    if (*(s32*)(object + 0x18) > 0) {
        for (index = 0; index < *(s32*)(object + 0x18); index++) {
            func_001a8438(func_001a8258((*(u32**)(object + 0x1c))[index]));
        }
    }
    for (index = 0; index < (s16)*(u16*)(object + 0x2e); index++) {
        switch (((UnitEntry*)(object + 0x20))[index].kind) {
        case 0:
            func_0019b2d8(((UnitEntry*)(object + 0x20))[index].id);
            break;
        case 1:
            func_0019b2b0(((UnitEntry*)(object + 0x20))[index].id);
            break;
        }
    }
    *(s32*)object = -1;
}
