#include "../common/types.h"

struct Inner {
    u8 pad[4];
    s32 offset;
};

struct Outer {
    u8 pad[12];
    Inner* inner;
};

extern "C" u8* D_01d9e6e8;
extern "C" u8 D_01d9e730[];
extern "C" u8 D_01d9e8c0[];
extern "C" void func_002f3d08(u8*, u8*, u8*);

void func_00200638(u8* base, u32 unused, Outer* outer) {
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e730, base + outer->inner->offset + 160);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e6e8 + 80, D_01d9e6e8 + 16);
}
