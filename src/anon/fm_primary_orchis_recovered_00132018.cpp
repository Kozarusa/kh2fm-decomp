#include "../common/types.h"

u32 func_00132018(u32 object) {
    if (object != 0) {
        s32 kind = *(s16*)object;
        if (kind != -1) {
            if (kind != 0) goto failed;
            u32 offset = *(u32*)(object + 4) << 2;
            u32 relative = *(u32*)(object + 32) + offset;
            return object + relative;
        } else {
            u32 offset = *(u32*)(object + 4) << 2;
            object += *(u32*)((offset + object) + 4);
            return func_00132018(object);
        }
    } else {
        goto failed;
    }
failed:
    return 0;
}
