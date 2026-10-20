#include "../common/types.h"
extern "C" u32 func_00139d78(void);
u32 func_0028eb88(u8* object, s32 index, f32 first, f32 second) {
    u32 result = func_00139d78();
    *(f32*)(*(u8**)(object + 56) + index * 380 + 368) = first;
    *(f32*)(*(u8**)(object + 56) + index * 380 + 372) = second;
    return result;
}
