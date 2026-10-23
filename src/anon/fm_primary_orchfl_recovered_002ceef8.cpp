#include "../common/types.h"
struct Box { s32 a, b, c, d, e, f; };
extern "C" u8* D_00361f60;
extern "C" s32 func_002cec08(u8*, Box*);

bool func_002ceef8(s32 unused, u8* object) {
    u8* frustum = D_00361f60;
    Box* source = (Box*)(object + 0x740);
    Box box = *source;
    return func_002cec08(frustum, &box) != 0;
}
