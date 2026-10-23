// func_00303698: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
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

u32 func_00303698(s32 arg1,code *arg2)

{
    u32 value3;
    s32 value4;
    s32 value5;
    s32 * value6;
    u32 value7;
    value6 = (s32 *)(arg1 + 0x1d8);
    value7 = 0;
    if ((value6 !=(s32 *) 0x0))
    {
        value5 = *(s32 *)(arg1 + 0x1dc);
        while (true)
        {
            value5 = value6 [1];
            value4 = value6 [2];
            while (value5 = value5 + - 1, - 1 < value5)
            {
                if (*(s16 *)(0xc + value4) != 0)
                {
                    value3 = (* arg2)(value4);
                    value7 = value3 | value7;
                }
                value4 = value4 + 0x58;
            }
            value6 = (s32 *) * value6;
            if (value6 ==(s32 *) 0x0)
                break;
        }
    }
    return value7;
}
