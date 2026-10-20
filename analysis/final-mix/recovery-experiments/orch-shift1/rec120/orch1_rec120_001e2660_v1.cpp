#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001e2660(u8* object, Quad* source) {
    s32 index = 0;
    do {
        index = index + 1;
        if (object[172] == 0) {
            if ((Quad*)(object + 160) != source) {
                *(Quad*)(object + 160) = *source;
            }
            object[173] = 0;
            object[175] = 30;
            object[172] = 0x80;
            object[174] = 0;
            return;
        }
        object = object + 16;
    } while (index < 10);
}
