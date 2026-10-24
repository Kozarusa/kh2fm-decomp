#include "../common/types.h"
typedef s32 (*Method)(u8*);
extern "C" f32 D_00349e10;
extern "C" u8* D_00352130;
extern "C" u64 func_00175af8(...);
extern "C" s32 func_00177860(...);
extern "C" void func_00178220(...);
extern "C" void func_00179718(u8*);
extern "C" void func_00179cb8(u8*);
extern "C" s32 func_0017a3b0(u8*);
extern "C" bool func_001917c0(void);
extern "C" bool func_00197920(...);
extern "C" void func_001a1b68(s32, f32);
extern "C" u64 func_001b9d40(...);

s32 func_00178758(u8* object) {
    func_00175af8(object);
    func_00179718(object);
    if ((*(Method*)(*(u8**)object + 64))(object) != 0 && *(s32*)(object + 1164) != 0 &&
        !func_00197920()) {
        if ((u32)(*(u8*)(*(s32*)(object + 1164) + 431) - 2) < 2) {
            f32 scale = D_00349e10;
            if (!func_001917c0()) {
                scale = scale * *(f32*)(D_00352130 + 108);
            }
            switch (*(u8*)(*(s32*)(object + 1164) + 431)) {
            case 2:
                scale = scale * *(f32*)(func_00177860(object) + 64);
                break;
            case 3:
                scale = scale * *(f32*)(func_00177860(object) + 108);
                break;
            }
            func_001a1b68(*(s32*)(object + 1164), -scale);
        }
    }
    func_00179cb8(object);
    if (func_001b9d40(object) != 0) {
        if (!(*(u32*)(object + 2040) & 0x20)) {
            func_00178220(object);
            *(u32*)(object + 2040) |= 0x20;
        }
        *(s32*)(object + 2888) = 0;
    }
    return func_0017a3b0(object);
}
