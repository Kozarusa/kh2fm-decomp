#include "../common/types.h"
extern "C" f32 D_00375e74;
extern "C" u8 D_00362c18[];
extern "C" f32 func_002dea00(u32*, f32, f32);

f32 func_002dfb10(u32* object) {
    f32 start = 0.0f;
    asm("" : "+f"(start)); // why: original forms the zero argument first, before the address
    f32* limit = &D_00375e74;
    asm volatile("" : "+r"(limit)); // why: keeps store order: the object copy and address are formed before the load
    f32 result = func_002dea00(object, start, *limit);
    object[0] = (u32)D_00362c18;
    object[2] = object[2] | 0x800;
    return result;
}
