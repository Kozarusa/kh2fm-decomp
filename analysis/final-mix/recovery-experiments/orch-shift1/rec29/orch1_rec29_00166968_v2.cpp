#include "../common/types.h"
extern "C" void func_001666d0(void*, u16, u32, u16, u16);

void func_00166968(u8* object, u8 flag, u16 a, u32 b, u16 c, u16 d, s16 e, s16 f) {
    func_001666d0(object, a, b, c, d);
    object[14] = flag;
    *(s16*)(object + 10) = e;
    *(s16*)(object + 12) = f;
}
