#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_00142b70(...);
extern "C" u32 func_00165ef0(...);
extern "C" s32 func_00164718(s32, u8*);

s32 func_00165a10(u8* object) {
    s32* entry = 0;
    s32 result = 0;
    while ((entry = (s32*)func_00165ef0(entry)) != 0) {
        if (entry[0] != *(s32*)(object + 124) && (entry[2] & 1) == 0 && func_00142b70(entry[1]) == 0) {
            if (func_00164718(entry[1], object) != 0) {
                kn::FVector* destination = (kn::FVector*)(object + 16);
                result = 1;
                kn::FVector difference;
                // why: VU macro vector subtract copied from accepted sibling 00116d08; noreorder as in 001786e0 keeps sqc2 out of the branch delay slot
                asm volatile(".set noreorder; lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0; .set reorder"
                             : "=m"(difference) : "r"(object + 48), "r"(object) : "memory");
                if (destination != &difference) {
                    // why: lq/sq copy primitive (plain Quad copy failed in v6); noreorder keeps sq out of the loop branch delay slot
                    asm volatile(".set noreorder; lq $8,0(%1); sq $8,0(%0); .set reorder" : : "r"(destination), "r"(&difference) : "$8", "memory");
                }
            }
        }
    }
    return result;
}
