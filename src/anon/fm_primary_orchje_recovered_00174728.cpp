// func_00174728: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 func_001ad990(s32, f32, f32, f32);

u32 func_00174728(s32* object) {
    int target = *(s32 *)(4 + object [0]);
    f32 first = ((f32 *) object) [1];
    f32 second = ((f32 *) object) [2];
    f32 third = ((f32 *) object) [3];
    return func_001ad990(0x8c8 + target, first, second, third);
}
