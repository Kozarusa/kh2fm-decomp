#include "../common/types.h"
// Declaration copied from fm_primary_clearsequence_recovered_001d7940.cpp.
extern "C" bool func_00181500(s64);

// why: the original walks 8-byte records (index shifted by 3) reading a halfword flag at +4 and a byte kind at +6
struct FlagRecord {
    u32 head;
    u16 flag;
    u8 kind;
    u8 pad;
};
extern "C" FlagRecord D_003742c8[];

u32 func_00283ab8(u32 kind) {
    u32 result = 0;
    s32 index;
    for (index = 0; D_003742c8[index].flag != 0; index++) {
        if (kind == (u32)-1 || D_003742c8[index].kind == kind) {
            if (func_00181500(D_003742c8[index].flag)) {
                result = 1;
                break;
            }
        }
    }
    return result;
}
