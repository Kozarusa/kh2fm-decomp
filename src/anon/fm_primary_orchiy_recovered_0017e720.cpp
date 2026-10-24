#include "../common/types.h"
extern "C" f32 D_0034ebb8;
extern "C" f32 D_00349e10;
extern "C" u8* D_00352130;
extern "C" s32 func_001a8bd0(s32);
extern "C" u8* func_001a8c10(s32, s32);
extern "C" s32 func_0017e668(u8*);
extern "C" u8* func_001a1658(u8*, s32);
extern "C" void func_001a1950(u8*, s32, s32, s32);
extern "C" void func_001a17c8(u8*);

void func_0017e720() {
    D_0034ebb8 = D_0034ebb8 - D_00349e10;
    if (D_0034ebb8 <= 0.0f) {
        s32 index = 1;
        s32 member = func_001a8bd0(-1);
        do {
            u8* part = func_001a8c10(member, index);
            index++;
            if (part != 0 && func_0017e668(part) == 0) {
                u8* object = func_001a1658(part, -1);
                if ((*(u32*)(object + 0x1dc) & 0x10) != 0) {
                    func_001a1950(object, 1, 0, 0);
                }
                func_001a17c8(object);
            }
        } while (index < 4);
        D_0034ebb8 = *(f32*)(D_00352130 + 0x168);
    }
}
