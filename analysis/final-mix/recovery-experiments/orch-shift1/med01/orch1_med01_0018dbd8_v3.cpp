#include "../common/types.h"

bool func_0018dbd8(u8* object) {
    u32* flags = (u32*)(object + 4);
    return (*flags & 2) || ({
        bool selected;
        if (*flags & 8) {
            selected = true;
        } else if (*flags & 0x10) {
            selected = true;
        } else {
            selected = false;
        }
        selected;
    }) || (*flags & 0x200);
}
