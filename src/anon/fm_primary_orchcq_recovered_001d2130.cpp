#include "../common/types.h"
extern "C" u32 func_001d2110(s32, s32);
extern "C" u32 func_001d2248(s32, s32);

void func_001d2130(f32 value, s32 object, s32 offset) {
    func_001d2110(object, *(s32*)(object + 0x2c) + offset);
    func_001d2248(object, *(s32*)(object + 0x2c));
    *(f32*)(object + 0x3c) = value;
}
