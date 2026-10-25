// func_001ae8d8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
struct ReadRequest {
    s32 mode;
    s32 sector;
    u32 data;
    s32 size;
    s32 flag;
};
extern "C" ReadRequest D_00350cb0;
extern "C" u8 D_00350ca8[];
extern "C" u64 func_001ae678(...);
extern "C" u64 func_002f79c8(...);
extern "C" s32 func_002f7be8(s32, u32, u32, u8*);

s32 func_001ae8d8(s32* object, u32 data, s32 size, s32 mode, s32 flag) {
    register s32 * sector;
    sector = (s32 *)(object [2] + 8);
    u32 count = u32(size + 0x7ff) >> 11;
    D_00350cb0.mode = mode;
    ReadRequest * request = & D_00350cb0;
    request->sector = object [2];
    request->size = size;
    request->data = data;
    request->flag = flag;
    while (1 != 0)
    {
        if (2 == func_002f79c8(1))
        {
            register int result = (func_002f7be8(* sector, count, data, D_00350ca8));
            if (result == 1)
            {
                return result;
            }
        }
        func_001ae678();
    }
}
