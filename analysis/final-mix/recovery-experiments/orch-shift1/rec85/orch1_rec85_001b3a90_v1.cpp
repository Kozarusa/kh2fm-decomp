#include "../common/types.h"
extern "C" u32 D_00351078[];
extern "C" u8* D_00351068;
extern "C" void func_001b3b70(u8*, u32, u32, u32);
extern "C" u16 func_0016a070(u8*);

void func_001b3a90(u8* object, u32 entry, u32 vector) {
    func_001b3b70(object, entry, 2, vector);
    *(u32*)(object + 0x588) = *(u32*)(object + 0x588) | 0x10000;
    *(u32**)object = D_00351078;
    *(u32*)(object + 0x600) = *(u32*)(object + 0x600) & 0xffffff87;
    *(u32*)(object + 0x3b0) = 1;
    if (func_0016a070(object) == 0x1390) {
        D_00351068 = object;
    }
}
