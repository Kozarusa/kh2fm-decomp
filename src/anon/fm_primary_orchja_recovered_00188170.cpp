#include "../common/types.h"
struct StateBits {
    u32 busy : 1;
};
extern "C" u32 func_00187ab8(...);
extern "C" void func_00187f90(u32);
extern "C" void func_00187fd8(u32, u32);

// Preserve original registry aliases.
void func_00188170(u32 object, u32 name) asm("_ZN2YS3ACT9pri_startEPc");

void func_00188170(u32 object, u32 name) {
    u32 self = object;
    if ((u8)((StateBits*)(object + 156))->busy != 0) return;
    u32 entry = func_00187ab8(*(u32*)(object + 140), name);
    if (entry == 0) return;
    if (*(u16*)(entry + 4) < *(s32*)(self + 152)) return;
    func_00187f90(self);
    func_00187fd8(self, entry);
}
