#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
    inline Vector(const Vector& rhs) {
        // why: original copies each by-value vector with one lq/sq pair through t0
        asm("lq $8, 0(%1);"
            "sq $8, 0(%0);"
            :
            : "r"(this), "r"(&rhs)
            : "t0");
    }
};
struct Flags {
    u32 low : 7;
    u32 first : 1;
    u32 second : 1;
    u32 high : 23;
};
extern "C" u8 D_0034c720[];
extern "C" u32 func_001433c0(u32 a0, u32 a1);
extern "C" void func_0015f9c8(u8* object, s32 zero, s32 value, Vector first, Vector second, Vector third, s32 extra, s32 minus, s32 stack0, s32 stack1, s32 stack2);

u32 func_0015f8d8(u8* object, s32 value, Vector first, Vector second, Vector third, s32 extra, s32 flag) {
    func_0015f9c8(object, 0, value, first, second, third, extra, -1, 0, 0, 0);
    *(u8**)object = D_0034c720;
    if (flag == 0) {
        object[466] = 0x80;
        object[465] = 0x80;
        object[464] = 0x80;
        object[467] = 0xff;
        *(s32*)(object + 456) |= 2;
    }
    u32 result = func_001433c0((u32)(object + 448), flag);
    *(s32*)(object + 500) = 0;
    *(s32*)(object + 432) = 1;
    ((Flags*)(object + 696))->first = 0;
    ((Flags*)(object + 696))->second = 0;
    return result;
}
