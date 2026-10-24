#include "../common/types.h"
extern "C" f32 D_0036c8c0[];
extern "C" void func_002cb708(u32);
extern "C" void func_00105110(void*);
extern "C" s32 func_0019b328(s32, s32);
extern "C" s32 func_00182e08(s32);
extern "C" s32 func_0016c028(u8*);
extern "C" s32 func_002cd018(u8*, s32, s32, f32);

s32 func_00184eb8(u8* object, s32 value, s32 handle) {
    if (handle == 0) {
        handle = *(s32*)(object + 2072);
    }
    s32 previous = *(s32*)(object + 1288);
    if (previous != 0) {
        func_002cb708(previous);
        func_00105110((void*)previous);
        *(s32*)(object + 1288) = 0;
    }
    s32 result = 0;
    if (handle != 0) {
        result = func_0019b328(handle, value);
    }
    if (result == 0) {
        if (*(u32*)(object + 1416) & 0x80) {
            result = func_00182e08(value);
        }
        if (result == 0) {
            return 0;
        }
    }
    s32 extra = func_0016c028(object);
    f32* pointer = D_0036c8c0;
    asm("" : "+r"(pointer)); // why: original forms the table address with addiu before the lwc1
    *(s32*)(object + 1288) = func_002cd018(object, result, extra, *pointer);
    return 1;
}
