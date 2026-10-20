#include "../common/types.h"
extern "C" u32 func_001abb78(void*);
extern "C" u32 func_00239bf8(s32, s32);

void func_001abdf0(s32* object, s32 mode) {
    *object = mode;
    switch (mode) {
    case 0:
        break;
    case 1:
        func_00239bf8((s32)(object + 1), 0x41);
        return;
    case 2:
        func_001abb78(object + 0x57);
        return;
    }
}
