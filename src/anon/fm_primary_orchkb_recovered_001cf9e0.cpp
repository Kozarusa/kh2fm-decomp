#include "../common/types.h"
extern "C" u32 func_0016ac38(...);
extern "C" u32 func_001dc840(s32);
extern "C" u32 func_001940f0(...);
extern "C" u32 func_00194108(...);

void func_001cf9e0(u8* object, s32 mode) {
    switch (mode) {
    case 0: {
        if (*(s32*)(object + 2976) == 0) {
            *(s32*)(object + 2976) = func_0016ac38(object, 12, 1, 0, 0);
        }
        s32 effect = *(s32*)(object + 2980);
        if (effect != 0) {
            func_001dc840(effect);
            *(s32*)(object + 2980) = 0;
        }
        func_001940f0(object, 2);
        func_00194108(object, 1);
        break;
    }
    case 1: {
        if (*(s32*)(object + 2980) == 0) {
            *(s32*)(object + 2980) = func_0016ac38(object, 13, 1, 0, 0);
        }
        s32 effect = *(s32*)(object + 2976);
        if (effect != 0) {
            func_001dc840(effect);
            *(s32*)(object + 2976) = 0;
        }
        func_001940f0(object, 1);
        func_00194108(object, 2);
        break;
    }
    }
}
