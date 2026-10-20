#include "../common/types.h"
extern "C" u8* D_01d9e6e0;
extern "C" f32 D_00370b6c[];
extern "C" void func_002f4000(u8*);

void func_0021f5d8(u8* object) {
    D_01d9e6e0[168] = 2;
    func_002f4000(object + 64);
    *(f32*)(object + 172) = D_00370b6c[0];
}
