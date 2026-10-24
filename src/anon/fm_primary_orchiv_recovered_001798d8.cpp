#include "../common/types.h"
extern "C" u8* D_00352130;
extern "C" u8* func_0017df58(s32);
extern "C" s32 func_0019ba60(u8*);
extern "C" void func_0016cce8(s32, s32, void*, s32, s32);
extern "C" void func_001a1b68(u8*, f32);
extern "C" void func_00179a68(u8*, f32);
extern "C" s32 func_00177760(u8*, u8*, s32, u8*);

s32 func_001798d8(u8* object, u8* target, s32 value, u8* info) {
    s32 index = 0;
    do {
        u8* entry = func_0017df58(index);
        index++;
        if (entry != 0 && func_0019ba60(entry) != 0 && *(s32*)(entry + 1156) != 0) {
            s32 args[2];
            args[0] = (s32)target;
            args[1] = value;
            func_0016cce8(*(s32*)(entry + 1156), 15, args, 2, 0);
        }
    } while (index < 2);
    u8 level = info[41];
    if (level != 0) {
        u32 flags = *(u32*)(target + 1416);
        if (flags & 0x10) {
            f32 scale = (s32)level;
            u8* other = *(u8**)(object + 1164);
            switch (other[431]) {
            case 2:
                scale = -scale * *(f32*)(D_00352130 + 116);
                if (flags & 0x800) {
                    scale = scale * *(f32*)(D_00352130 + 100);
                }
                func_001a1b68(other, scale);
                break;
            case 3:
                if (*(f32*)(other + 436) == 0.0f) {
                    break;
                }
            case 1:
                if (flags & 0x800) {
                    scale = scale * *(f32*)(D_00352130 + 96);
                }
                func_00179a68(object, scale);
                break;
            }
        }
    }
    return func_00177760(object, target, value, info);
}
