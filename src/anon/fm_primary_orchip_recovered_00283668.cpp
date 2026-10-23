// func_00283668: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
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
extern "C" s32 D_0035f2b8;

bool func_00283668(void)

{
    s32 value1;
    bool value2;
    value2 = true;
    value1 = func_00139d78(D_0035f2b8 + 0x354);
    if (value1 != 0)
    {
        value2 = *(s32 *)(D_0035f2b8 + 0x4d8) == 0x13;
    }
    if (value2 != false)
    {
        value1 = func_00139d78(D_0035f2b8 + 0x1a0);
        if (value1 && (*(s32 *)(D_0035f2b8 + 0x324) != 0x10))
        {
            value2 = false;
        }
        if (value2 != false)
        {
            value1 = func_00139d78(D_0035f2b8 + 0x508);
            if (value1 && (*(s32 *)(D_0035f2b8 + 0x68c) != 2))
            {
                value2 = false;
            }
            if (((value2 != false) && (value1 = func_00139d78(D_0035f2b8 + 0x6a0), value1)) && (*(s32 *)(D_0035f2b8 + 0x824) != 5))
            {
                value2 = false;
            }
        }
    }
    return value2;
}
