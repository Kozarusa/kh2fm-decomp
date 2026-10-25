#include "../common/types.h"
extern "C" u32 D_0035f58c;
extern "C" u8 D_0035f590;
extern "C" u32 func_0023f900(u32);
extern "C" s64 func_00292630();
extern "C" u32 func_00276568(void);
extern "C" u32 func_00287bc0(void);
extern "C" int func_002953c8(...);
extern "C" u32 func_002941d8(s32);
extern "C" s32 func_00296f80(void);
extern "C" s32 func_00296f90(void);
extern "C" u64 func_00293db8(s32,const char*);
extern "C" void func_0023fa08(u32,u64);

void func_002969e0() {
    s8 kind;
    s32 index;

    func_0023f900(D_0035f58c);
    if (func_00292630() == 0) {
        kind = *(s8*)func_00276568();
        if (func_00287bc0() == 2) {
            if (kind == 1 && func_002941d8(func_002953c8(1)) != 0) {
                index = func_00296f90();
            } else {
                index = func_002953c8(kind) + 1;
            }
        } else {
            index = func_00296f80();
        }
        func_0023fa08(D_0035f58c, func_00293db8(2, (const char*)index));
        D_0035f590 = 1;
    } else {
        D_0035f590 = 0;
    }
}
