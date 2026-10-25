#include "../common/types.h"
extern "C" u8 D_01e2a410[];
// why: no recovered site uses this callee; a0 address, a1-a3 and t0 words, t1 two out pointers
extern "C" s32 func_002bccd8(void*, s32, s32, s32, s32*, s32*);
// why: plain extern "C" name; the recovered definition takes six s32 arguments
extern "C" s32 func_002baf48(s32, s32, s32, s32, s32, s32);
extern "C" u32 func_002bce10(void*, s32);

s32 func_002ba6f0(s32 key, s32 first, s32 firstData, s32 second, s32 secondData, s32* handle)
{
    s32 result;
    *handle = -1;
    result = -1;
    if (func_002bccd8(D_01e2a410, key, first, second, handle, &result) != 0) {
        func_002baf48(*handle, 0, first, firstData, 0, 0);
        if (second != 0) {
            func_002baf48(*handle, 1, second, secondData, 0, 0);
        }
        func_002bce10(D_01e2a410, *handle);
    }
    return result;
}
