#include "../common/types.h"
extern "C" u8 D_0036da70[];
// why: copied from the accepted call site in fm_primary_orchbi_recovered_0018b200.cpp
extern "C" bool func_001883d8(...);
// why: copied from the accepted call site in fm_primary_orchbi_recovered_0018b200.cpp
extern "C" u32 func_001880b0(...);
// why: copied from the accepted call site in fm_scalar_recovered_04.cpp
extern "C" u64 func_0016c2b0(...);
// why: copied from the accepted call site in fm_scalar_extra_recovered_12.cpp
extern "C" u64 func_001b4198(...);
// why: copied from the accepted call site in fm_scalar_extra_recovered_12.cpp
extern "C" u64 func_0016be00(...);
// why: void with one pointer parameter as in its accepted definition in tiny.cpp (BD_VALUE* there, u8* here since that type is not declared in this file); extern "C" because the C++-linkage definition is not in the isolated probe link
extern "C" void func_00187850(u8* object);

void func_001b40e0(u8* object) {
    u8 buffer[16];
    if (func_001883d8(object + 0x300, D_0036da70)) {
        func_001880b0(object + 0x300, D_0036da70);
    }
    if (*(s32*)(object + 0x48c) != 0 && *(s32*)(*(s32*)(object + 0x48c) + 0x264) != 0) {
        func_0016c2b0(buffer, object);
        func_001b4198(*(s32*)(*(s32*)(object + 0x48c) + 0x264), *(s32*)(object + 0xae4), buffer);
        u16 kind = *(u16*)(*(s32*)(*(s32*)(object + 0x48c) + 0x264) + 0x58);
        if (kind != 0) {
            func_0016be00(object, kind);
        }
    }
    func_00187850(object);
}
