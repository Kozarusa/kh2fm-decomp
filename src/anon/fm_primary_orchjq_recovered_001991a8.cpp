#include "../common/types.h"
extern "C" const void* D_0036d0d0[120];
extern "C" s32 D_00350438;
extern "C" void func_001993a0(void);
extern "C" void func_00105de0(s32 value);
extern "C" void func_002430b0(u32);
extern "C" s32 func_0016b7a0(s32);
extern "C" void func_00196b28(u32 a0, u32 a1);
extern "C" void func_0016bb38(u64 a, u64 b);
extern "C" u32 func_00198cb8(s32, s32);

u32 func_001991a8(s32 id, s32 value) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036d0d0
    static const void* targets[120] asm("fm_switch_table_001991a8") = {
        &&direct, &&other, &&other, &&submenu, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&submenu, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&submenu, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&submenu, &&submenu, &&submenu, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&submenu,
        &&other, &&submenu, &&submenu, &&direct, &&direct, &&direct, &&direct, &&direct,
        &&direct, &&direct, &&direct, &&direct, &&direct, &&direct, &&direct, &&direct,
        &&direct, &&direct, &&direct, &&submenu, &&other, &&other, &&other, &&other,
        &&other, &&other, &&other, &&other, &&other, &&other, &&submenu, &&other,
        &&direct, &&direct, &&direct, &&other, &&other, &&other, &&other, &&direct};
    u32 result = 1;
    func_001993a0();
    u32 index = id - 0x13;
    if (index >= 120) goto other;
    goto *D_0036d0d0[index];
direct:
    func_00105de0(id);
    goto done;
submenu:
    func_002430b0(id);
    goto done;
other:
    if ((id == 8 || id == 0x82) && value != 0) {
        D_00350438 = func_0016b7a0(value);
    }
    func_00196b28(id, value);
    func_0016bb38(id, value);
    result = func_00198cb8(id, value);
done:
    return result;
}
