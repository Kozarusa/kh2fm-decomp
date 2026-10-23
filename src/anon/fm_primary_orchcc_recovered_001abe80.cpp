#include "../common/types.h"
extern "C" u32 func_001abbf0(...);
extern "C" u32 func_001ac728(u64);
extern "C" u32 func_002ba2e8(u64, u64);

void func_001abe80(s32* object, u64 value, u64* flags) {
    switch (*object) {
    case 0:
        break;
    case 1:
        if ((flags[1] & 0x40c) != 0) {
            func_002ba2e8(0x18, 0);
            func_001ac728(value);
            return;
        }
        break;
    case 2:
        func_001abbf0(object + 0x57);
        return;
    }
}
