// func_00166808: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
// func_00166808: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 func_001666f0(void*, u16, u32, u16, u16);

u32 func_00166808(u8* object, u8 flag, u16 a, u32 b, u16 c, u16 d, s16 e, s16 f) {
    u32 result;
    result = func_001666f0(object, a, b, c, d);
    *(s16 *)(object + 10) = e;
    *(s16 *)(12 + object) = f;
    object [14] = flag;

    return result;
}
