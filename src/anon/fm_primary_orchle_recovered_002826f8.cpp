#include "../common/types.h"
extern "C" const void* D_003741d0[5];
extern "C" u32 func_00281180(u32, s32);
// why: two arguments read from a0 (party) and a1 (passed through unchanged); result tested against zero
extern "C" s32 func_00281480(u32, s32);
extern "C" u32 func_002813b8(void);
extern "C" u32 func_00281420(void);

// why: typed return; every exit returns the value this function computed in s2

u32 func_002826f8(u8* object, s32 index, u32 kind) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_003741d0
    static const void* targets[5] asm("fm_switch_table_002826f8") = {
        &&first, &&sora, &&slot0, &&slot1, &&slot2};
    register u8* self asm("$17") = object; // why: original keeps the object pointer in s1 and the result in s2
    u8* sheet = *(u8**)(func_00281180(*(u32*)(self + 4100), index) + 580);
    u32 result = 0;
    if (kind >= 5) goto done;
    goto *D_003741d0[kind];
first:
    result = 1;
    goto done;
sora:
    if (func_00281480(*(u32*)(self + 4100), index) != 0) {
        s32 forms = func_002813b8() & func_00281420();
        for (s32 bit = 0; bit < 7; bit++) {
            result += (forms >> bit) & 1;
        }
    }
    return result;
slot0:
    result = sheet[16];
    goto done;
slot1:
    result = sheet[17];
    goto done;
slot2:
    result = sheet[18];
done:
    return result;
}
