#include "../common/types.h"
extern "C" u32* D_0035f610;
extern "C" u32 func_00294000(u32);
extern "C" s32 func_002a9d68(void);
// why: declaration copied exactly from the recovered call site in fm_primary_orchlk_recovered_002a1b18.cpp
extern "C" bool func_002a9f50(...);

bool func_002aa148(s32 id) {
    bool result = 1;
    u32* flags = (u32*)func_002a9d68();
    if (id < 0) {
        result = func_002a9f50(-1);
    } else {
        u32 object = func_00294000(3);
        s32 count = *(s32*)(object + 8);
        s32 index = 0;
        s8* cursor = (s8*)(object + 16);
        if (count > 0) {
            do {
                if (*cursor == id) {
                    u16 bit = *(u16*)(cursor + 4);
                    u32 word = bit >> 5;
                    u32 mask = 1 << (bit & 0x1f);
                    if ((D_0035f610[word] & mask) != 0) {
                        result = (flags[word] & mask) != 0;
                        if (!result) {
                            return result;
                        }
                    }
                }
                index++;
                cursor += 36;
            } while (index < count);
        }
    }
    return result;
}
