#include "../common/types.h"
extern "C" u32 func_001dca30(s32, u32, u32);

void func_001c16a0(s32* object, u32 value) {
    switch (object[1]) {
    case 0:
        func_001dca30(object[0], object[12], value);
        break;
    case 1:
        func_001dca30(object[0], object[12], value);
        break;
    }
}
