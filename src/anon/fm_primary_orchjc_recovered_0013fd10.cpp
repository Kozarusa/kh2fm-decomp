#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
    inline Vector() {}
    inline Vector(const Vector& rhs) {
        // why: lq/sq copy primitive through t0; the original copies the by-value argument with an unguarded 128-bit move in t0 (plain copy used t7)
        asm("lq $8, 0(%1);"
            "sq $8, 0(%0);"
            :
            : "r"(this), "r"(&rhs)
            : "$8");
    }
    inline Vector& operator=(const Vector& rhs) {
        if (this == &rhs) {
            return *this;
        }
        // why: lq/sq copy primitive through t0, same as kn::FVector assignment
        asm("lq $8, 0(%1);"
            "sq $8, 0(%0);"
            :
            : "r"(this), "r"(&rhs)
            : "$8");
        return *this;
    }
};
extern "C" Vector func_0016af58(s32);
extern "C" f32 func_0013fcd8(u8*, Vector);

f32 func_0013fd10(u8* object) {
    Vector value;
    value = func_0016af58(*(s32*)(object + 0x44));
    return func_0013fcd8(object, value);
}
