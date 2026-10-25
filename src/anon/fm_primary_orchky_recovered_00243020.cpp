#include "../common/types.h"
extern "C" u8 D_0032bad8;
extern "C" s32 func_00103b38();
// why: no recovered source calls func_00103550; it takes no argument registers and its v0 is passed straight to func_00103428 as a word
extern "C" s32 func_00103550(void);
// why: extern "C" because the isolated probe linker script defines only the plain func_00103428 symbol (v1 with the C++ declaration gave an unresolved reference)
extern "C" s32 func_00103428(s32 value);
// why: extern "C" because the isolated probe linker script defines only the plain func_00243150 symbol (v1 with the C++ declaration gave an unresolved reference)
extern "C" s16* func_00243150(s32 value);
// why: extern "C" because the isolated probe linker script defines only the plain func_00103500 symbol (v1 with the C++ declaration of the accepted void definition gave an unresolved reference)
extern "C" void func_00103500(s32 value);
// why: extern "C" because the isolated probe linker script defines only the plain func_00253538 symbol (v1 with the asm-label form gave an unresolved reference); kept void as in the accepted definition (fm_primary_oneword_recovered_00253538.cpp), with the s32 parameter because this original loads a0 with lh before the tail jump
extern "C" void func_00253538(s32 value);

void func_00243020(s32 value) {
    if (D_0032bad8 == 0) return;
    if (func_00103b38() != 0) {
        if (func_00103428(func_00103550()) == 0) return;
        func_00103500(func_00243150(value)[1]);
        return;
    }
    func_00253538(func_00243150(value)[1]);
}
