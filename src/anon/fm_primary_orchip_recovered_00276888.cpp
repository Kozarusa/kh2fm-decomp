// func_00276888: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
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
extern "C" u32 func_00276a90(...);
extern "C" u32 func_00276b90(...);
extern "C" s32 D_0035f21c;

u32 func_00276888(void)

{
    s32 value1;
    s32 value2;
    u32 value3;
    s32 value4;
    s32 value5;
    u32 value6;
    value6 = 1;
    value1 = func_00139d78(D_0035f21c);
    value3 = (value1 != 0);
    if (value3 == 0)
    {
        value1 = func_00139d78(D_0035f21c + 0x198);
        if (value1 != 0)
        {
            value3 = value6;
        }
        if (value3 == 0)
        {
            value1 = func_00139d78(D_0035f21c + 0x330);
            value3 = (value1 != 0);
            if (value3 == 0)
            {
                value1 = func_00139d78(D_0035f21c + 0x4c8);
                if (value1 != 0)
                {
                    value3 = value6;
                }
                if (value3 == 0)
                {
                    value1 = func_00139d78(D_0035f21c + 0x660);
                    value3 = (value1 != 0);
                    if (value3 == 0)
                    {
                        value1 = func_00139d78(D_0035f21c + 0x814);
                        if (value1 != 0)
                        {
                            value3 = value6;
                        }
                        if (value3 == 0)
                        {
                            value1 = func_00139d78(D_0035f21c + 0x9c8);
                            value3 = (value1 != 0);
                            if (value3 == 0)
                            {
                                value1 = func_00139d78(D_0035f21c + 0xb7c);
                                if (value1 != 0)
                                {
                                    value3 = value6;
                                }
                                if (value3 == 0)
                                {
                                    value1 = func_00139d78(D_0035f21c + 0xd30);
                                    value3 = (value1 != 0);
                                    if (value3 == 0)
                                    {
                                        value5 = 0;
                                        value4 = 0;
                                        do
                                        {
                                            value1 = func_00139d78(D_0035f21c + value4 + 0x1098);
                                            if (value1 != 0)
                                            {
                                                value3 = 1;
                                                break;
                                            }
                                            value2 = D_0035f21c + value4;
                                            value4 = value4 + 0x198;
                                            value1 = func_00139d78(value2 + 0x4398);
                                            if (value1 != 0)
                                            {
                                                value3 = 1;
                                                break;
                                            }
                                            value5 = value5 + 1;
                                        }
                                        while (value5 < 0x20);
                                        if ((value3 == 0) && (value3 = func_00276a90(), value3 == 0))
                                        {
                                            value3 = func_00276b90();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return value3;
}
