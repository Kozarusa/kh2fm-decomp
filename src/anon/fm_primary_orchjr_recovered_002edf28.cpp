#include "../common/types.h"

struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    void set(u8 red, u8 green, u8 blue, u8 alpha) {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
};

struct Object {
    const void* vtable;
    s32 field4;
    s32 field8;
    s32 fieldC;
    s32 field10;
    s32 field14;
    Color color;
    s32 field1C;
};

extern "C" u8 D_003637e0[];

void func_002edf28(Object* object) {
    object->field4 = 0;
    object->fieldC = 0;
    object->vtable = D_003637e0;
    object->field8 = 0;
    object->field10 = 0;
    object->field14 = 0;
    object->color.set(128, 128, 128, 128);
    object->field1C = 0;
}
