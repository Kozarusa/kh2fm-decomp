#include "../common/types.h"
extern "C" u8* D_01d9e6e0;
extern "C" f32 D_00370b6c[];
extern "C" void func_002f4000(u8*);

void func_0021f5d8(u8* object) {
    D_01d9e6e0[168] = 2;
    func_002f4000(object + 64);
    f32* source = D_00370b6c;
    asm("" : "+r"(source)); // why: keeps address formation separate from the load
    *(f32*)(object + 172) = *source;
}
