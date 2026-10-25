#include "../common/types.h"
extern "C" u32 D_0035ee04;
extern "C" u32 D_0035ee08;
extern "C" u32 D_0035ee10;
// why: return type of the definition in fm_global_recovered_09.cpp
extern "C" void func_00287d68(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00139d78(...);
// why: return type of the accepted definition fm_primary_orchea_recovered_0024eb50.cpp
extern "C" void func_0024eb50(void);
// why: no recovered source calls or defines this function; no argument registers are set before the call and its result is not used
extern "C" void func_0024f2d0(void);
extern "C" u32 func_001039f8(void);
// why: no recovered source calls or defines this function; no argument registers are set before the call and its result is not used
extern "C" void func_0024ec50(void);

s32 func_0024ebc0(void) {
    func_00287d68();
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035ee04)) {
            if (!func_00139d78(D_0035ee08)) {
                if (!func_00139d78(D_0035ee10)) {
                    func_0024eb50();
                    func_0024f2d0();
                    func_001039f8();
                    return 1;
                }
            }
        }
    } else {
        func_0024ec50();
    }
    return 0;
}
