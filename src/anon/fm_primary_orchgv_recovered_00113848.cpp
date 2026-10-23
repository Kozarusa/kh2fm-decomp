#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

union Buffer {
    Quad value;
    s32 word[4];
};

extern "C" s32 func_0010cc70(s32);
extern "C" s32 func_0010cc80(s32);
extern "C" u32 func_0010ef48(s32);
extern "C" void func_0010f880(s32, f32, f32);
extern "C" f32 func_0010f8a8(s32);
extern "C" u32 func_0010f8c0(s32);
extern "C" u32 func_0010f8e0(s32);
extern "C" s32 func_0010f9e0(s32, s32);
extern "C" u32 func_0010f9f0(s32, Buffer*, s32);
extern "C" u32 func_0016af58(Buffer*, s32);
extern "C" u32 func_0016b010(s32, Buffer*);

u8 func_00113848(u8* owner, s32 value, s32* destination, s32* result, u8 flag) {
    if (flag != 0) {
        *result = 0;
        s32 object = *(s32*)(owner + 4);
        destination[0] = *(s32*)(object + 2548);
        destination[1] = *(s32*)(object + 2552);
        destination[2] = *(s32*)(object + 2556);
        destination[3] = *(s32*)(object + 2560);
        destination[4] = *(s32*)(object + 2564);
        if (func_0010f8c0(*(s32*)(owner + 4)) != 0) {
            if (func_0010f8e0(*(s32*)(owner + 4)) != 0) {
                return 0;
            }
            if (func_0010f8a8(*(s32*)(owner + 4)) <= 0.0f) {
                return 0;
            }
        } else {
            if (func_0010f9e0(*(s32*)(owner + 4), value) != 0) {
                return 0;
            }
        }
        return (u8)(func_0010ef48(*(s32*)(owner + 4)) ^ 1);
    }
    if (func_0010f8c0(*(s32*)(owner + 4)) == 0) {
        u8* position = *(u8**)(owner + 8);
        func_0010f880(*(s32*)(owner + 4), *(f32*)(position + 112), *(f32*)(position + 116));
    }
    Buffer buffer;
    if (func_0010cc80(*(s32*)(owner + 4)) != 0) {
        Quad* source = (Quad*)(func_0010cc70(*(s32*)(owner + 4)) + 32);
        asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&buffer), "r"(source) : "$8", "memory"); // why: original copies the quad through t0 (lq/sq copy primitive, plain Quad copy schedules differently)
        func_0016b010(*(s32*)(owner + 4), &buffer);
    }
    func_0016af58(&buffer, *(s32*)(owner + 4));
    buffer.word[3] = 0;
    func_0010f9f0(*(s32*)(owner + 4), &buffer, 0);
    return 1;
}
