#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001e2660(u8* object, Quad* source) {
    s32 index;
    for (index = 0; index < 10; index++, object += 16) {
        if (object[172] == 0) {
            Quad* destination = (Quad*)(object + 160);
            if (destination != source) {
                *destination = *source;
            }
            object[173] = 0;
            object[175] = 30;
            object[172] = 0x80;
            object[174] = 0;
            return;
        }
    }
}
