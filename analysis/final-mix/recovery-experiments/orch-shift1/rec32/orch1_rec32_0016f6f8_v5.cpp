#include "../common/types.h"
extern "C" u8* func_0016e920(u32);

u32 func_0016f6f8(u32 id) {
    if ((id & 0x40000000) != 0) {
        u8* data = func_0016e920(id);
        if (data != 0) {
            s32 kind = data[4];
            if (kind == 0x16) {
                return 0;
            }
            if (kind < 0x17) {
                return kind != 7;
            }
            return kind != 0x18;
        }
    }
    return 0;
}