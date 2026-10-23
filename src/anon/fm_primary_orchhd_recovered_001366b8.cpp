#include "../common/types.h"
extern "C" u8 D_0032bae0;
extern "C" s32 D_00347d20;
extern "C" s16* func_001aec40();
extern "C" void func_002b9ab8(s32);
extern "C" void func_002bc458(s32);
extern "C" void func_001369d0();
extern "C" void func_001369f0();
extern "C" u32 func_002b9ed0(void);
extern "C" void func_00136a60();
extern "C" void func_001363a0(s32);
extern "C" s32 func_00136560(s32);

s32 func_001366b8(s32 value) {
    s16* entry = func_001aec40();
    if (entry == 0) {
        return 0;
    }
    s32 id = entry[0];
    if (id == -1) {
        func_002b9ab8(20);
    } else {
        func_002b9ab8(id);
    }
    func_002bc458(entry[1]);
    if (D_0032bae0 != D_00347d20) {
        func_001369d0();
        func_001369f0();
        D_00347d20 = D_0032bae0;
        func_002b9ed0();
    }
    func_00136a60();
    func_001363a0(value);
    return func_00136560(value);
}
