#include "../common/types.h"
extern "C" s32 D_004f63a8;
extern "C" s32 D_004f63ac;
extern "C" s32 func_0016f930(s32);

void func_0016f8d0(s32 value) {
    s32 result = func_0016f930(value);
    if (result == 2400) {
        result = func_0016f930(0);
    }
    switch (result) {
    case 2410:
        D_004f63a8 = value;
        break;
    case 2420:
        D_004f63ac = value;
        break;
    }
}
