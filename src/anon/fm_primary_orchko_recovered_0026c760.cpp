#include "../common/types.h"
extern "C" u8* D_0035f01c;
extern "C" u8* D_0035f024;
// why: recovered call sites declare Tz::Select::GetCurrent only as varargs; the single parameter comes from a0, u32 result as at its use in fm_primary_orchiq_recovered_0024a048.cpp
extern "C" u32 func_002891e8(u8* select);
// why: the C++ definition s32 func_0028b1b8(void*) in misc_2.cpp failed the isolated link in v1; the probe linker script defines only the plain symbol
extern "C" s32 func_0028b1b8(void* self);
// why: Tz::Select::SetSelectDisable has no recovered call site; a0 is the select object, a1 the mask, its result is not used here
extern "C" void func_0028b1b0(u8* select, u32 mask);
// why: the recovered call site (fm_primary_orchio_recovered_00252020.cpp) declares u32(u32); the result is compared signed (slt) here, so it is s32 and the pointer is passed as the object
extern "C" s32 func_002892f8(u8* select);
// why: copied from the call in fm_primary_orchjf_recovered_0028afd0.cpp, with the object passed as u8* instead of its local Item type
extern "C" bool func_0028b1c0(u8* select, s32 index);
// why: the recovered call site (fm_primary_orchip_recovered_0027c2f8.cpp) declares it varargs; arguments come from a0..t0
extern "C" void func_002891f0(u8* select, s32 index, s32 first, s32 second, s32 third);
// why: the recovered call site (fm_primary_orcheg_recovered_0026ff30.cpp) declares it varargs; one parameter from a0. Its result is stale here: it crosses the later call
extern "C" u32 func_00287cc0(s32 state);
// why: only placeholder declarations exist; every exit of its original is a tail call into Tz::CMenuHelp::Create, whose accepted definition (fm_scalar_recovered_06.cpp) is void, so no value comes back
extern "C" void func_0026cb38();

void func_0026c760(void) {
    u32 current = func_002891e8(D_0035f01c);
    s32 value = (1 << current) | func_0028b1b8(D_0035f01c);
    func_0028b1b0(D_0035f024, value);
    value = current + 1;
    if (value >= func_002892f8(D_0035f024) || func_0028b1c0(D_0035f024, value)) {
        value = current - 1;
    }
    func_002891f0(D_0035f024, value, 0, -1, -1);
    func_00287cc0(0);
    func_0026cb38();
}
