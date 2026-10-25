#include "../common/types.h"
// why: extern "C" keeps the plain func_ symbol; accepted call sites (0024e158, 00257388) use this exact declaration
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
// why: extern "C" keeps the plain func_ symbol; result unused here, arguments from a0/a1 set before the jal
extern "C" void func_0028b6f0(u8*, u32);
// why: extern "C" keeps the plain func_ symbol; result unused here, arguments from a0/a1 set before the jal
extern "C" void func_0028b720(u8*, u32);
// why: extern "C" keeps the plain func_ symbol; original returns a0 + 48 in v0 (a pointer)
extern "C" u8* func_0023f1b0(u32);
// why: extern "C" keeps the plain func_ symbol; accepted definition returns u8* from (object, s32, s32), its object struct is not shared here
extern "C" u8* func_0023c3e0(u8*, s32, s32);
// why: extern "C" keeps the plain func_ symbol; original writes no v0 (its tail callee is a flag store)
extern "C" void func_0028dd28(u8*, u8*);

void func_0028b520(u8* self, u32 first, u32 second, u32 third, u32 layoutKey, u32 parentValue, u32 childValue, s32 extra, s32 stackValue) {
    *(u32*)(self + 436) = layoutKey;
    func_0028d980(self, first, second, third, layoutKey, extra, -1, stackValue, 0);
    func_0028b6f0(self, parentValue);
    func_0028b720(self, childValue);
    s32 value = *(s32*)(func_0023f1b0(*(u32*)(self + 436)) + 0x4c);
    s32 index = 0;
    u8* cursor = self;
    do {
        if (value == *(s16*)(cursor + 0x1bc)) {
            u8* entry = func_0023c3e0(func_0023f1b0(*(u32*)(self + 436)), *(s16*)(cursor + 0x1c2), 0);
            func_0028dd28(self, entry);
            break;
        }
        index++;
        cursor += 2;
    } while (index < 3);
    *(s16*)(self + 0x1c8) = value;
}
