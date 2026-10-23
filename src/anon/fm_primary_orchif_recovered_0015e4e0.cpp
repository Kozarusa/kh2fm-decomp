#include "../common/types.h"
extern "C" u8 D_0034c6e0[];
extern "C" u64 D_0036b448;
extern "C" u64 D_0036b450;
extern "C" void func_0014b7f0(u8*);
extern "C" void func_0014c050(u8*);
extern "C" void func_0014b610(u8*, u64);
extern "C" void func_0014b608(u8*, u64);
extern "C" void func_0014b5e0(u8*, u64);
extern "C" void func_0014b630(u8*, u64);
extern "C" void func_0014b618(u8*, u64);
extern "C" void func_0014b5e8(u8*, u64, u64);
extern "C" void func_0014b208(u8*, u32, u32);
extern "C" void func_0014b468(u8*, u32, u32);
extern "C" u32 func_0014b628(u8*, u64);

u32 func_0015e4e0(u8* object) {
    u8* first;
    u8* second;
    *(s32*)(object + 4) = 0;
    *(u8**)(object + 0) = D_0034c6e0;
    first = object + 144;
    func_0014b7f0(first);
    second = object + 416;
    func_0014c050(second);
    *(s32*)(object + 1200) = 0;
    func_0014b610(first, 0x131000070ULL);
    func_0014b608(first, D_0036b448);
    func_0014b5e0(first, 278);
    func_0014b630(first, 96);
    func_0014b618(first, 0x3cfe5);
    func_0014b5e8(first, 0x80008, 0x4080408);
    func_0014b610(second, 0x131000070ULL);
    func_0014b5e0(second, 342);
    func_0014b630(second, 96);
    func_0014b618(second, 0x3001d);
    func_0014b208(second, 512, 416);
    func_0014b468(second, 512, 416);
    return func_0014b628(second, D_0036b450);
}
