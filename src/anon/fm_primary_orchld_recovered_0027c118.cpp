#include "../common/types.h"
// why: the original updates only the top bit of the halfword (andi 0x7fff then or), a one-bit field store
struct Flags {
    u16 low : 15;
    u16 high : 1;
};
extern "C" u32 D_0035f010;
extern "C" u8* D_0035f230;
// why: accepted call sites declare this with a variadic list; the original passes one word in a0, so the list is written out
extern "C" s32 func_002570a0(s32);
// why: extern "C" because the accepted C++ declaration failed the isolated link (v1): the probe linker script defines only the plain symbol
extern "C" void func_0027aed8(s32 value, u32* flag, s32* output);
// why: accepted call sites declare this with a variadic list; the original passes two words in a0 and a1, so the list is written out
extern "C" u32 func_00281180(u32, s32);

// why: u32 return per DEVIATIONS #36 (iv): the only exit leaves func_00281180's result untouched in v0 (direct)

u32 func_0027c118(s32 index, u8 value) {
    u32 flag;
    s32 slot;
    u32 sheet;
    u32 table;
    Flags* entry;

    func_0027aed8(func_002570a0(15), &flag, &slot);
    sheet = func_00281180(D_0035f010, flag != 0 ? 0 : slot);
    table = *(u32*)(sheet + 580);
    D_0035f230[index * 8 + 14] = value;
    entry = (Flags*)(((s8)D_0035f230[index * 8 + 15]) * 2 + table + 80);
    entry[2].high = value != 0;
    return sheet;
}
