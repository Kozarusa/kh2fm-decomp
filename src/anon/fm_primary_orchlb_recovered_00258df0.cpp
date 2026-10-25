#include "../common/types.h"
extern "C" u16 D_0035f090;
extern "C" u16 D_0035f094;
// why: Munny::Get (munny.cpp) returns u32; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" u32 func_002424a0(void);
// why: accepted definition in fm_primary_argument_recovered.cpp is void func_0028e560(u64, const s16*, s32, u64); extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" void func_0028e560(u64, const s16*, s32, u64);

// Preserve original registry aliases.
void func_00258df0(s32 object) asm("_Z13func_00258df0i");

void func_00258df0(s32 object) {
    s16 digits[6];
    s32 index;
    for (index = 0; index < 6; index++) {
        digits[index] = D_0035f090;
    }
    u32 money = func_002424a0();
    for (index = 0; index < 6; index++) {
        u32 digit = money % 10;
        u32 quotient = money / 10;
        if (index != 0 && digit == 0 && quotient == 0) {
            break;
        }
        digits[index] = digit + D_0035f094;
        money = quotient;
    }
    func_0028e560(object, digits, 6, (u64)-1);
}
