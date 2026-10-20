#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_001e2660(u8* object, Quad* source) {
    s32 index;
    for (index = 0; index < 10; index++, object += 16) {
        if (object[172] == 0) {
            register Quad* destination asm("$15") = (Quad*)(object + 160); // why: original keeps the destination address in t7
            asm("" : "+r"(destination)); // why: keeps the address in one register for the compare and the store
            if (destination != source) {
                register Quad copy asm("$8") = *source; // why: original copies the quad through t0
                asm("" : "+r"(copy)); // why: keeps the quad in t0 until the store
                *destination = copy;
            }
            object[174] = 0;
            object[175] = 30;
            object[172] = 0x80;
            object[173] = 0;
            return;
        }
    }
}