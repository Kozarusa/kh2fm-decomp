// func_001317a8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" f32 D_0036abec;
extern "C" f32 D_0036abf0;

s32 func_001317a8(f32 value,u32 object)
{
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register u32 base asm("$15") = *(u32 *)(object + 4);
    f32 scaled = value * *(volatile f32 *)(base + 0x58);
    s32 count = *(volatile s32 *)(base + 0x24);
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register f32 * denominator asm("$15") = & D_0036abec;
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register s32 limit asm("$13") = count - 1;
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    asm volatile("" : "+r"(denominator));
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register f32 divided asm("$f12") = scaled / * denominator;
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    asm volatile("" : "+f"(divided));
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register f32 * addition asm("$15") = & D_0036abf0;
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    asm volatile("" : "+r"(addition));
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register f32 increment asm("$f1") = * addition;
    s32 index = (divided + increment);
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    asm volatile("" : "+f"(increment));
    if (index < 0)
        index = 0;
    if (count <= index)
        index = limit;
    return index;
}
