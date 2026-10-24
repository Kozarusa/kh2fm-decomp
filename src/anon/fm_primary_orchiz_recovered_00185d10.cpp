#include "../common/types.h"
extern "C" u32 D_01c608b8;
extern "C" u8 D_0032e020[];
extern "C" bool func_0019ba60(s32);
extern "C" u16 func_0016a070(u8*);
extern "C" void func_001d6088(s32, u8*);
extern "C" void func_001890a8(u32, u32);
extern "C" void func_001d7e78(u8*);

void func_00185d10(u8* object) {
    if (func_0019ba60(*(s32*)(object + 2788))) {
        D_01c608b8 = *(u32*)(object + 2788);
        u8* target = (u8*)*(u32*)(object + 2788);
        if (*(u32*)(target + 1416) & 0x80) {
            func_001d6088(func_0016a070(object), target);
        }
    }
    func_001890a8((u32)D_0032e020, func_0016a070(object));
    func_001d7e78(object);
}
