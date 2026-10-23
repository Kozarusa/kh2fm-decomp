// func_001333f8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 func_00313bc0(f32);

u32 func_001333f8(u8* object, u32 numerator, u32 denominator) {
    f32 ratio = (f32)numerator / (f32)denominator;
    u32 result = func_00313bc0((f32)*(u32*)(object + 0x24) * ratio);
    return (result >> 16) & 0xfff;
}
