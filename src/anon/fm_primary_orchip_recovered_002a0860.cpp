// func_002a0860: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
// func_002a0860: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
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
extern "C" void func_00139510(...);
extern "C" u32 func_00139d78(...);
extern "C" s32 D_0035f5d8;

void func_002a0860(void)

{
    s32 value1;
    if (D_0035f5d8 != 0)
    {
        value1 = func_00139d78(D_0035f5d8);
        if (value1 != 0)
        {
            func_00139510(D_0035f5d8);
        }
        value1 = func_00139d78(D_0035f5d8 + 0x198);
        if (value1 != 0)
        {
            func_00139510(D_0035f5d8 + 0x198);
        }
        value1 = func_00139d78(D_0035f5d8 + 0x330);
        if (value1 != 0)
        {
            func_00139510(D_0035f5d8 + 0x330);
        }
        value1 = func_00139d78(D_0035f5d8 + 0x4c8);
        if (value1 != 0)
        {
            func_00139510(D_0035f5d8 + 0x4c8);
        }
    }
}
