#include "../common/types.h"
extern "C" const void* D_0036e950[8];
extern "C" f32 D_00349e10;
// copied from fm_primary_fiveword_recovered_0016fa58.cpp
extern "C" bool func_0019ba60(u64);
// why: type from the accepted definition fm_primary_twowordnext_recovered_001e1ce0.cpp; extern "C" because
// C++-linkage declarations failed the isolated link in lg348 001d7218 v1
extern "C" void func_001e1ce0(int object);
// why: no accepted declaration; a0 is the only argument register set before the jal
extern "C" void func_001e1d20(u8* object);
// why: registry name _Z13func_001e1df0Pv gives void* (no accepted declaration); extern "C" because C++-linkage
// declarations failed the isolated link in lg348 001d7218 v1
extern "C" void func_001e1df0(void* object);
// why: type from the accepted definition fm_last_window_recovered.cpp; extern "C" for the isolated link
extern "C" void func_001e1df8(u8* object);
// why: no accepted declaration; a0 is the only argument register set before the jal
extern "C" void func_001e1e40(u8* object);
// why: no accepted declaration; a0 is the only argument register set before the jal
extern "C" void func_001e2130(u8* object);
// why: registry name _Z13func_001e21f0Pv gives void* (no accepted declaration); extern "C" for the isolated link
extern "C" void func_001e21f0(void* object);
// why: no accepted declaration (only a tiny_auto80 placeholder); a0 is the only argument register set
extern "C" void func_001e21f8(u8* object);
// why: type from the accepted definition fm_scalar_recovered_05.cpp; extern "C" for the isolated link
extern "C" void func_001e2238(int object);
// why: no accepted declaration (only a tiny_wrappers placeholder); a0 is the only argument register set
extern "C" void func_001e2620(u8* object);
// why: no accepted declaration (only a tiny_wrappers placeholder u32); its tail into 001e2450 leaves v0 = an
// address computed there, which is the v0 at this function's only exit (direct result)
extern "C" u32 func_001e2640(u8* object);

// why: u32 return under clarification (iv): the only exit leaves the direct v0 of func_001e2640 -> func_001e2450
// (unaccepted; its v0 is the 00106a60 result or that +16 scratch pointer); $f0 holds this function's own sum.
// The only call site (auto80_199_queue.cpp, a placeholder) discards the result.

u32 func_001e2298(u8* object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036e950
    // (computed-goto pattern of fm_primary_orchiy_recovered_001815d0.cpp)
    static const void* targets[8] asm("fm_switch_table_001e2298") = {
        &&state0, &&state1, &&state2, &&state3, &&state4, &&state5, &&state6, &&state7};
    if (!func_0019ba60(*(s32*)(object + 0xdd0))) {
        *(s32*)(object + 0xdc0) = 7;
    }
    {
        u32 index = *(u32*)(object + 0xdc0);
        if (index >= 8) goto done;
        goto *D_0036e950[index];
    }
state0:
    func_001e1ce0((int)object);
done:
    {
        func_001e2238((int)object);
        func_001e2620(object);
        u32 result = func_001e2640(object);
        *(f32*)(object + 0xde4) = *(f32*)(object + 0xde4) + D_00349e10;
        *(f32*)(object + 0xde8) = *(f32*)(object + 0xde8) + D_00349e10;
        return result;
    }
state1:
    func_001e1d20(object);
    goto done;
state2:
    func_001e1df0(object);
    goto done;
state3:
    func_001e1df8(object);
    goto done;
state4:
    func_001e1e40(object);
    goto done;
state5:
    func_001e2130(object);
    goto done;
state6:
    func_001e21f0(object);
    goto done;
state7:
    func_001e21f8(object);
    goto done;
}
