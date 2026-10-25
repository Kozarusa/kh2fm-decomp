#include "../common/types.h"
extern "C" s32 D_0035f2d4;
extern "C" u8 D_0035f2d0;
extern "C" u32 func_00287d68(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" u8* func_0014aba8();
extern "C" u32 func_00287bc0(void);
// why: no argument registers are set before the call; v0 is tested by the caller
extern "C" s32 func_00284538(void);
// why: no argument registers are set before these calls; their v0 is not read here
extern "C" s32 func_002843e8(void);
extern "C" s32 func_00284fd8(void);
extern "C" s32 func_00285070(void);

s32 func_00284ef0(void) {
    register s32 result asm("$13"); // why: original keeps the result in t5 and copies it to v0 in the epilogue
    func_00287d68();
    if (func_00287db0() != 0) {
        if (D_0035f2d4 == 2 && func_00284538() != 0) {
            if ((*(s32*)(func_0014aba8() + 0xfc) ^ 4) == 0) {
                func_002843e8();
            }
            result = 0;
        } else if (func_00284538() != 0) {
            result = 0;
        } else {
            func_001039f8();
            result = 1;
        }
    } else if (D_0035f2d0 == 0) {
        switch ((s32)func_00287bc0()) {
        case 0:
            func_00284fd8();
            break;
        case 1:
        case 2:
            func_00285070();
            break;
        }
        result = 0;
    } else {
        result = 0;
    }
    return result;
}
