#include "../common/types.h"
extern "C" bool func_002282f0(...);
extern "C" u32 func_00227ca8(void*);
extern "C" u32 func_001671e8(s32,u8);
extern "C" u32 func_00167218(void);
u32 func_0022cea0(u8* object) {
    u32 result = func_002282f0(*(s16*)(object + 4));
    if (result != 0) return result;
    if (object[6] != 0) return func_00167218();
    u8 flag = object[7];
    u32 value = func_00227ca8(object + 8);
    return func_001671e8(value, flag == 0);
}
