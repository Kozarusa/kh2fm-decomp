#include "../common/types.h"
struct Vec4 {
    u32 x, y, z, w;
} __attribute__((aligned(16)));

void func_001e2660(u8* object, Vec4* source) {
    s32 index;
    for (index = 0; index < 10; index++, object += 16) {
        if (object[172] == 0) {
            Vec4* destination = (Vec4*)(object + 160);
            if (destination != source) {
                *destination = *source;
            }
            object[174] = 0;
            object[175] = 30;
            object[172] = 0x80;
            object[173] = 0;
            return;
        }
    }
}
