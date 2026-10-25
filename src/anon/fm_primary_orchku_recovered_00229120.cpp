#include "../common/types.h"
// why: no recovered call site uses these three; argument lists come from the registers set before each jal
extern "C" void func_00229430(u8*, s32);
extern "C" u32 func_00224860(void);
extern "C" u32 func_0022b720(void);
extern "C" u32 func_0022b9e0(...);
extern "C" void func_001386e0(...);
extern "C" u32 func_001396b0(u8*);
extern "C" u32 func_0031a260(u8*, s32);

// why: void per DEVIATIONS #36: both exits are stale-b (the original instructions of 001396b0 and 0031a260 never write v0 or $f0, so the final call on each path leaves nothing)

void func_00229120(u8* object) {
    func_00229430(object, 2800);
    *(u32*)(object + 2472) = func_00224860();
    u32 sqd = func_0022b9e0();
    u32 image = func_0022b720();
    u8* select = object + 24;
    func_001386e0(select, 2800, sqd, image, 21, 11);
    *(s32*)(select + 396) = 0;
    *(s32*)(select + 392) = 22;
    func_001396b0(select);
    if (*(s32*)(select + 396) != 0) {
        *(s32*)(select + 400) = 0;
        func_001396b0(select);
        if (*(s32*)(select + 400) != 0) {
            func_0031a260(select, 0);
        }
    }
}
