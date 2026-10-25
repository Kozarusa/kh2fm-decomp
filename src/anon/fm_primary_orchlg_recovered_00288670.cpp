#include "../common/types.h"
// Shape follows the accepted twin Tz::MenuBasic::EndFade (tozawa/cmenu_slbase.cpp).
extern u32 D_0035f338 asm("D_0035f338");
extern u32 D_0035f33c asm("D_0035f33c");
extern u32 D_0035f340 asm("D_0035f340");
extern u32 D_0035f344 asm("D_0035f344");
extern "C" u32 func_00139d78(u32);
extern "C" u32 func_00258cd8(...);
// why: accepted definition is Tz::Pause::StartFade(void (*)()) returning void; the asm-label form failed the isolated link (v1) because the probe linker script defines only the plain symbol
extern "C" void func_00258b38(u32);
extern "C" s32 func_00236ca8(s32, s32);
// why: no recovered caller; YI::LAYOUT::GetSequenceUnit(int) takes the layout object in a0 and the index in a1, result passed on as a word
extern "C" u32 func_0023c4b8(u32, s32);
extern "C" u32 func_001386e0(...);

void func_00288670(void (*cb)()) {
    u32 s3 = (u32)cb;
    if (func_00258cd8(s3) != 0) {
        func_00258b38(s3);
        return;
    }

    register u32 one asm("$18") = 1; // why: original keeps the constant 1 in s2 across the calls
    asm("" : "+r"(one)); // why: original loads the constant 1 once into a saved register before the calls and reuses it for all three stores
    func_00139d78(D_0035f338);
    u32 unit = func_0023c4b8(D_0035f340, 0);
    s32 image = func_00236ca8(D_0035f33c, 0);
    *(u8*)(image + 400) = one;
    func_001386e0(D_0035f338, 30036, unit, image, 5, 0);
    *(u32*)(D_0035f338 + 392) = one;
    u32 t6 = D_0035f338 + 24;
    *(u32*)(t6 + 184) |= 8u;
    *(u8*)(D_0035f338 + 405) = one;
    D_0035f344 = s3;
}
