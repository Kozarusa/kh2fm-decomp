#include "../common/types.h"
extern "C" u8 D_0034c6c8[];
extern "C" u8 D_004f3820[];
extern "C" u64 D_0036b458;
extern "C" void func_0014c050(u8*);
extern "C" void func_0014b610(u8*, u64);
extern "C" void func_0014b608(u8*, u64);
extern "C" void func_0014b5e0(u8*, u64);
extern "C" void func_0014b630(u8*, u64);
extern "C" void func_0014b618(u8*, u64);
extern "C" void func_0014b220(u8*, u8, u8, u8, u8);
extern "C" void func_0014b208(u8*, u32, u32);
extern "C" void func_0014b468(u8*, u32, u32);
extern "C" u32 func_0014b628(u8*, u64);

u32 func_0015e8c8(u8* object) {
    u8* second = object + 80;
    *(s32*)(object + 4) = 0;
    *(u8**)(object + 0) = D_0034c6c8;
    func_0014c050(second);
    *(s32*)(object + 864) = 0;
    func_0014b610(D_004f3820, 0x131000070ULL);
    func_0014b608(D_004f3820, 0x80140);
    func_0014b5e0(D_004f3820, 6);
    func_0014b220(D_004f3820, 0, 0, 0, 0);
    func_0014b208(D_004f3820, 512, 416);
    func_0014b610(second, 0x131000070ULL);
    func_0014b5e0(second, 342);
    func_0014b630(second, 96);
    func_0014b618(second, 0x3001d);
    func_0014b208(second, 512, 416);
    func_0014b468(second, 512, 416);
    return func_0014b628(second, D_0036b458);
}
