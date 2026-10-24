#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" u64 func_001a1de0(u32);
extern "C" bool func_001b58a8(void);
extern "C" s32 func_00177860(s32);
extern "C" void func_001a1d50(f32, u8*);

void func_00176f00(u8* object) {
    if (*(u32*)(object + 0x48c) == 0) {
        return;
    }
    if (func_001a1de0(*(u32*)(object + 0x48c)) == 0) {
        return;
    }
    if ((*(u32*)(object + 0x7f8) & 4) != 0) {
        return;
    }
    if ((*(u32*)(object + 0x588) & 0x80) != 0) {
        if (func_001b58a8()) {
            return;
        }
    }
    f32 scale = -D_00349e10;
    s32 entry = func_00177860((s32)object);
    func_001a1d50(scale * *(f32*)(entry + 0x38), *(u8**)(object + 0x48c));
}
