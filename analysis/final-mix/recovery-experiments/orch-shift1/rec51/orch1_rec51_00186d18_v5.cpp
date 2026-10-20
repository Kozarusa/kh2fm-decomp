#include "../common/types.h"

struct Sub {
    s32 flag;
    u8 pad[16];
    s32 value;
};

s32 func_00186d18(u8* object) {
    Sub* sub = (Sub*)(object + 320);
    s32 result = 0;
    if (sub->flag != 0) {
        s32 value = sub->value;
        s32 below = value < 140;
        if (below == 0) {
            result = value < 151;
        }
    }
    return result;
}
