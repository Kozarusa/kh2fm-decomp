// func_0024d4a0: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
#define CONCAT44(a, b) ((u64)(u32)(a) << 32 | (u32)(b))
#define CONCAT22(a, b) ((u32)(u16)(a) << 16 | (u16)(b))
#define CONCAT11(a, b) ((u16)(u8)(a) << 8 | (u8)(b))
#define CONCAT31(a, b) ((u32)(a) << 8 | (u8)(b))
#define CONCAT13(a, b) ((u32)(u8)(a) << 24 | ((u32)(b) & 0xffffff))
#define SUB84(x, n) ((u32)((u64)(x) >> ((n) * 8)))
#define SUB82(x, n) ((u16)((u64)(x) >> ((n) * 8)))
#define SUB81(x, n) ((u8)((u64)(x) >> ((n) * 8)))
#define SUB42(x, n) ((u16)((u32)(x) >> ((n) * 8)))
#define SUB41(x, n) ((u8)((u32)(x) >> ((n) * 8)))
#define SUB21(x, n) ((u8)((u16)(x) >> ((n) * 8)))
#define ZEXT48(x) ((u64)(u32)(x))
#define ZEXT14(x) ((u32)(u8)(x))
#define ZEXT24(x) ((u32)(u16)(x))
#define SEXT48(x) ((s64)(s32)(x))
#define SEXT14(x) ((s32)(s8)(x))
#define SEXT24(x) ((s32)(s16)(x))
typedef u32 code(...);
extern "C" u32 func_00139d78(...);
extern "C" void func_0023f070(...);
extern "C" u32 func_0023f0c0(...);
extern "C" u32 func_0024e008(...);
extern "C" u32 func_002891e8(...);
extern "C" void func_0028ab20(...);
extern "C" u32 func_0028acc8(...);
extern "C" u32 func_0028da70(...);
extern "C" s32 D_0035edcc;
extern "C" s32 D_0035edd4;
extern "C" s32 D_0035edd8;
extern "C" s32 D_0035eddc;
extern "C" s32 D_0035ede0;
extern "C" s32 D_0035ede4;

u32 func_0024d4a0(void)

{
    u32 result;
    s32 value1;
    int value2;
    s32 value3;
    int value4;
    value3 = func_00139d78(D_0035edd4);
    if (0 !=(value3 && (value3 = func_0023f0c0(D_0035edd4), 0x20 != value3)))
    {
        func_0023f070(D_0035edd4, 0x20, 0xffffffffffffffff);
    }
    value3 = func_0028acc8(D_0035edcc);
    if ((0 != value3))
    {
        func_0028ab20(D_0035edcc);
        value4 = func_002891e8(D_0035edcc);
        value2 = func_0024e008(value4);
        value3 = func_00139d78(D_0035eddc);
        if (value3 != 0)
        {
            value1 = (func_0023f0c0(D_0035eddc));
            if (value1 != *(s16 *)(4 + value2))
            {
                func_0023f070(D_0035eddc, *((s16 *)(value2 + 4)), 0xffffffffffffffff);
            }
        }
    }
    value3 = func_00139d78(D_0035edd8);
    if (value3 && (value3 = func_0023f0c0(D_0035edd8), value3 != 0x23))
    {
        func_0023f070(D_0035edd8, 0x23, 0xffffffffffffffff);
    }
    result = func_0028da70(D_0035ede0, 0x21);
    result = func_0028da70(D_0035ede4, 0x29);

    return result;
}
