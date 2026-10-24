#include "../common/types.h"
extern "C" void func_001963c8(u32);

void func_00196540(s32 id) {
    u32 value;
    switch (id) {
    case 0x8b8:
        value = 0x2f;
        break;
    case 0x1061:
        value = 0x1e;
        break;
    case 0x141f:
        value = 9;
        break;
    case 0x1822:
    case 0x1877:
        value = 0x1f;
        break;
    case 0x2023:
        value = 0x29;
        break;
    case 0x2822:
        value = 0x26;
        break;
    case 0x3012:
        value = 0x13;
        break;
    case 0x401e:
        value = 0x10;
        break;
    default:
        return;
    }
    func_001963c8(value);
}
