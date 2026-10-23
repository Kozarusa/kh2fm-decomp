// func_0023c5f0: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
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
extern "C" u32 func_00239b50(...);

s32 func_0023c5f0(s32 arg1,s32 arg2)

{
    s32 value3;
    u16 * value4;
    s32 value5;
    s32 value6;
    s32 value7;
    value7 = 0;
    value6 = 0;
    value4 = (u16 *)(*(s32 *)(arg1 + 0x14) + arg2 * 0x14);
    value5 = *(s32 *)(arg1 + 0x10) + * value4 * 0x18;
    if (0 != value4 [1])
    {
        do
        {
            value7 = value7 + 1;
            value3 = func_00239b50(*(s32 *)(arg1 + 0x2c) + *(s32 *)(value5 + 4) * 0x158, *(u32 *)(value5 + 8));
            value3 = value3 + *(s32 *)(value5 + 0xc);
            value5 = value5 + 0x18;
            if (value6 < value3)
            {
                value6 = value3;
            }
        }
        while ((value7 < value4 [1]) != 0);
    }
    return value6;
}
