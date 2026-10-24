#include "../common/types.h"
extern "C" s8 D_0036d018[];
extern "C" s32 D_01c61afc;
extern "C" s32 func_00168b88(s32,u32,s32,s32);

s32 func_00195360(s32* out) {
    register s32 first asm("$18") = func_00168b88(D_01c61afc, 24, // why: original keeps the first result in s2
        D_0036d018[0] | ((u32)D_0036d018[1] << 8) | ((u32)D_0036d018[2] << 16) | ((u32)D_0036d018[3] << 24), 0);
    s32 second = func_00168b88(D_01c61afc, 25,
        D_0036d018[0] | ((u32)D_0036d018[1] << 8) | ((u32)D_0036d018[2] << 16) | ((u32)D_0036d018[3] << 24), 0);
    register s32 value asm("$14") = *(s32*)(first + 8); // why: original loads the first word into t6
    s32 other = *(s32*)(second + 8);
    out[0] = value;
    out[1] = other;
    return second;
}
