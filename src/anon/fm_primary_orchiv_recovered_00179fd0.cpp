#include "../common/types.h"
extern "C" u32 func_001050d8(u32);
extern "C" s32 func_00167f18(s32);
extern "C" void func_001d0980(u32, u32*, s32, s32, s32, f32);
extern "C" void func_002d9730(u32, u32*, s32, s32, f32);
extern "C" void func_002d49c0(u32, u32*, s32, s32, f32);
extern "C" void func_001d1540(u32, u32*, s32, s32, f32);
extern "C" void func_001ced68(u32, u32*, s32, s32, f32);
extern "C" void func_001cf698(u32, u32*, s32, s32, f32);
extern "C" void func_002dd700(u32, u32*, s32, s32, f32);

u32 func_00179fd0(u32* object, s32 value, s32 flag, f32 scale) {
    s32 input = func_00167f18(0);
    u32 result;
    switch (object[0]) {
    default:
        result = func_001050d8(2944);
        func_001d0980(result, object, value, input, flag, scale);
        break;
    case 860:
        result = func_001050d8(3360);
        func_002d9730(result, object, input, flag, scale);
        break;
    case 859:
        result = func_001050d8(3136);
        func_002d49c0(result, object, input, flag, scale);
        break;
    case 958:
        result = func_001050d8(2928);
        func_001d1540(result, object, input, flag, scale);
        break;
    case 1525:
        result = func_001050d8(2944);
        func_001ced68(result, object, input, flag, scale);
        break;
    case 968:
        result = func_001050d8(2992);
        func_001cf698(result, object, input, flag, scale);
        break;
    case 861:
        result = func_001050d8(3088);
        func_002dd700(result, object, input, flag, scale);
        break;
    }
    return result;
}
