#include "../common/types.h"
extern "C" bool func_002282f0(...);
extern "C" u32 func_00227ca8(void*);
extern "C" u32 func_001671e8(s32,u8);
extern "C" u32 func_00167218(void);

u32 func_0022cea0(u8* object) {
    register u8* pointer asm("$17") = object; // why: original preserves object in s1 separately from flag in s0
    u32 result = func_002282f0(*(s16*)(pointer + 4));
    if (result != 0) return result;
    if (pointer[6] == 0) {
        u8 flag = pointer[7];
        u32 value = func_00227ca8(pointer + 8);
        return func_001671e8(value, flag == 0);
    } else {
        return func_00167218();
    }
}
