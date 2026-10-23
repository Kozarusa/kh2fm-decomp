// func_00291110: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
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
extern "C" void func_00290d68(...);
extern "C" void func_00290f78(...);
extern "C" u32 func_00291380(...);
extern "C" void func_00291510(...);
extern "C" void func_00291918(...);
extern "C" u32 func_00291de0(...);

u32 func_00291110(u64 arg1,u64 arg2,u64 arg3,u64 arg4,
                 u64 arg5,u64 arg6,u64 arg7)

{
    u32 result;
    u32 value8;
    int value9;
    func_00290d68(arg1, arg5);
    func_00290f78(arg1);
    __typeof__(func_00291380(arg1, arg3)) value_t1 = func_00291380(arg1, arg3);
    value8 = value_t1;
    value9 = func_00291380(arg1, arg4);
    value8 = 0xfffffffffffffeff &(value8 | value9);
    func_00291510(arg1, arg2, arg3, value8);
    func_00291918(arg1, arg2, arg3, arg4, value8);
    result = func_00291de0(arg1, arg2, arg3, arg4, arg6, arg7, value8);

    return result;
}
