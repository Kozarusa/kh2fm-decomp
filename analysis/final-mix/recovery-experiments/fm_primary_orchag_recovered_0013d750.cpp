#include "../common/types.h"
struct Holder {
    u8 pad0[0x2a4];
    s32 field;
};
extern "C" Holder* D_003484a0;
extern "C" void func_001024a8(u32);
extern "C" void func_0013b128(u64);
extern "C" void func_0013d620();
extern "C" void func_0013d7c0();

void func_0013d750(u32 value) {
    func_0013d620();
    func_0013b128((u64)D_003484a0);
    D_003484a0->field = 0;
    func_0013d7c0();
    func_001024a8(value);
}
