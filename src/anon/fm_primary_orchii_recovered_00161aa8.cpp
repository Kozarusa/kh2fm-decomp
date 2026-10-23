#include "../common/types.h"
extern "C" s8 D_004f3b50;
extern "C" s8 D_004f3b58;
extern "C" u8 D_004f3b60[];
extern "C" u8 D_004f3e70[];
extern "C" u8 D_001623d8[];
extern "C" u8 D_001623f0[];
extern "C" u64 D_0036b478;
extern "C" u64 D_0036b480;
extern "C" u8 D_0034c76c;
extern "C" u8 D_0034c768;
extern "C" void func_0014c050(u8*);
extern "C" void func_002fd188(u8*);
extern "C" void func_0014b5e0(u8*, u64);
extern "C" void func_0014b630(u8*, u64);
extern "C" void func_0014b208(u8*, u32, u32);
extern "C" void func_0014b5e8(u8*, u64, u64);
extern "C" u32 func_0014b628(u8*, u64);
extern "C" void func_0014b220(u8*, u8, u8, u8, u8);
extern "C" s32 func_0014c350(u8*);
extern "C" u64 func_0014e098(...);

// Preserve original registry aliases.
s32 func_00161aa8() asm("_ZN2dk6Camera11draw2CameraEv");

s32 func_00161aa8() {
    if (D_004f3b50 == 0) {
        func_0014c050(D_004f3b60);
        D_004f3b50 = 1;
        func_002fd188(D_001623d8);
    }
    if (D_004f3b58 == 0) {
        func_0014c050(D_004f3e70);
        D_004f3b58 = 1;
        func_002fd188(D_001623f0);
    }
    func_0014b5e0(D_004f3b60, 342);
    func_0014b630(D_004f3b60, 0);
    func_0014b208(D_004f3b60, 512, 416);
    func_0014b5e8(D_004f3b60, 0x80008, 0x1a082008);
    func_0014b628(D_004f3b60, D_0036b478);
    func_0014b220(D_004f3b60, 128, 128, 128, D_0034c76c);
    func_0014c350(D_004f3b60);
    func_0014e098(320);
    func_0014b5e0(D_004f3e70, 342);
    func_0014b630(D_004f3e70, 0);
    func_0014b208(D_004f3e70, 512, 416);
    func_0014b5e8(D_004f3e70, 0x80008, 0x1a082008);
    func_0014b628(D_004f3e70, D_0036b480);
    func_0014b220(D_004f3e70, 128, 128, 128, D_0034c768);
    return func_0014c350(D_004f3e70);
}
