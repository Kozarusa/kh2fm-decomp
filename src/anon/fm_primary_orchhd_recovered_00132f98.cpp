#include "../common/types.h"
extern "C" s32 func_00132338(u8*);
extern "C" u8* func_00132350(u8*);
extern "C" u8* func_00132c68(u8*);

s32 func_00132f98(u8* object, u32 value, s32* out, s32 unused, s32 filter) {
    s32 count = 0;
    while (object != 0) {
        if (func_00132338(object) == 1) {
            u8* entry = func_00132c68(object);
            if ((filter == 0 || *(s32*)(object + 4) == filter) && entry != 0 &&
                *(u16*)(entry + 2) == value && *(s32*)(object + 636) != 0) {
                if (out != 0) {
                    out[count] = (s32)object;
                }
                count++;
            }
        }
        object = func_00132350(object);
    }
    return count;
}
