#include "../common/types.h"
extern "C" u8 D_0022cba0[];
extern "C" u8 D_0022cc08[];
extern "C" bool func_002282f0(...);
// why: type of the accepted definition fm_primary_oneword_recovered_00225b00.cpp (u32 with one int argument); no recovered call site uses its result
extern "C" u32 func_00225b00(s32 value);
extern "C" u32 func_002282d8(void);
extern "C" u8* func_00102c18(s32, s32, u8*);
extern "C" u32* func_001050c8();
extern "C" s32 func_001063c0(u32, u32);
// why: YI::VIBRATION default constructor; no accepted source calls it, so it is called as a plain symbol with the object pointer in a0 as the original passes it
extern "C" void func_0023cd68(s32 object);
// why: the call site in fm_primary_orchcs_recovered_001d5068.cpp declares it void and discards the result, but the original body sets v0 = 1 on its only exit, so this tail call returns that word
extern "C" s32 func_0023cde8(u8* object);

s32 func_0022cae8(u8* object) {
    s32 result = func_002282f0(*(s16*)(object + 4));
    if (result != 0) return result;
    result = func_00225b00(*(s16*)(object + 4));
    if (result != 0) return result;
    u8* task = func_00102c18(1, func_002282d8(), D_0022cba0);
    *(u8**)(task + 48) = D_0022cc08;
    s32 vibration = func_001063c0(4, (u32)func_001050c8());
    func_0023cd68(vibration);
    *(s32*)(task + 8) = vibration;
    return func_0023cde8(object + 8);
}
