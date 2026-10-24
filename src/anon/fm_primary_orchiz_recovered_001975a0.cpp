#include "../common/types.h"
extern "C" u8 D_00350379;
extern "C" u8 D_0032b9dd;
extern "C" u32 D_0032b9e0;
extern "C" void func_0014ce60(void);
extern "C" void func_00194980(void);
extern "C" bool func_0019f060(void*);
extern "C" u32 func_0014abe8(void);
extern "C" u32 func_0014abf8(void);
extern "C" u32 func_0014aa80(s32, u64, u8);
extern "C" u32 func_00170320(s32);
extern "C" void func_00197780();
extern "C" void func_00197cc0();
extern "C" s32 func_00242ea8();
extern "C" s32 func_00242ee8();
extern "C" u32 func_0014aba8(void);
extern "C" u32 func_001058e8(void);
extern "C" u32 func_0014a138(u8);
extern "C" u32 func_0019f070(void*, u32);

struct StateFlags {
    u16 pad;
    u16 bits;
    u32 bit(s32 shift) { return ((u32)bits >> shift) & 1; }
};

u32 func_001975a0(u32* object) {
    void* jumper = object + 3;
    func_0014ce60();
    func_00194980();
    if (!func_0019f060(jumper)) {
        if ((u8)(*(StateFlags**)(object + 15))->bit(4) != 0) {
            func_0014aa80(func_0014abe8(), 6, 0);
            func_0014aa80(func_0014abf8(), 6, 0);
        }
        if ((u8)(*(StateFlags**)(object + 15))->bit(0) != 0) {
            func_00170320(-200);
        }
        if ((object[0] & 0x20) == 0) {
            func_00197780();
        }
        if ((u8)(*(StateFlags**)(object + 15))->bit(2) == 0) {
            func_00197cc0();
        }
    }
    if (func_00242ea8() != 0 && ((object[0] & 0x10) != 0 || (func_00242ee8() == 0 && D_00350379 == 0))) {
        u8 flag = 0;
        if ((*(s32*)(func_0014aba8() + 0xfc) ^ 4) == 0) {
            flag = *(u8*)(func_0014aba8() + 0xf4);
            if (flag == 1) {
                D_0032b9dd = flag;
            }
        }
        D_0032b9e0 = *(u8*)(func_001058e8() + 12);
        return func_0014a138(flag);
    }
    return func_0019f070(jumper, 0x80000000);
}
