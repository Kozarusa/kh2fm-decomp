#include "../common/types.h"
extern "C" u64 func_00184540(u32, u32, f32, f32);

u32 func_002bec38(u32 value, u32, u8* object) {
    u8* pointer = *(u8**)(object + 300);
    func_00184540(value, (u32)object, *(f32*)(pointer + 40), *(f32*)(pointer + 44));
    return value;
}
