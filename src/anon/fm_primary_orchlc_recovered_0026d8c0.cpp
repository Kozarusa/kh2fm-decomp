#include "../common/types.h"
extern "C" s32 D_0035f0fc;
extern "C" u8 func_001a8bf8(s32,s32);
// why: Tz::ChgMember::GetMember() (static void*, tozawa/chg_member.hpp) failed the isolated link in v1;
// the probe linker script defines only the plain symbol func_00293bc0
extern "C" void* func_00293bc0();

s32 func_0026d8c0(s32 value) {
    s32 index = 0;
    s32 result = -1;
    void* member = func_00293bc0();
    do {
        u8 slot = func_001a8bf8(D_0035f0fc, index);
        if (slot == func_001a8bf8((s32)member, value)) {
            result = index;
            break;
        }
        index++;
    } while (index < 4);
    return result;
}
