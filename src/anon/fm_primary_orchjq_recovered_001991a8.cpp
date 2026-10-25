#include "../common/types.h"
extern "C" s32 D_00350438;
extern "C" void func_001993a0(void);
extern "C" void func_00105de0(s32 value);
extern "C" void func_002430b0(u32);
extern "C" s32 func_0016b7a0(s32);
extern "C" void func_00196b28(u32 a0, u32 a1);
extern "C" void func_0016bb38(u64 a, u64 b);
extern "C" u32 func_00198cb8(s32, s32);

u32 func_001991a8(s32 id, s32 value) {
    u32 result = 1;
    func_001993a0();
    switch (id) {
    case 0x13:
    case 0x66: case 0x67: case 0x68: case 0x69: case 0x6a: case 0x6b:
    case 0x6c: case 0x6d: case 0x6e: case 0x6f: case 0x70: case 0x71:
    case 0x72: case 0x73: case 0x74: case 0x75:
    case 0x83: case 0x84: case 0x85: case 0x8a:
        func_00105de0(id);
        break;
    case 0x16: case 0x46: case 0x4f: case 0x57: case 0x58: case 0x59:
    case 0x62: case 0x64: case 0x65: case 0x76: case 0x81:
        func_002430b0(id);
        break;
    default:
        if ((id == 8 || id == 0x82) && value != 0) {
            D_00350438 = func_0016b7a0(value);
        }
        func_00196b28(id, value);
        func_0016bb38(id, value);
        result = func_00198cb8(id, value);
        break;
    }
    return result;
}
