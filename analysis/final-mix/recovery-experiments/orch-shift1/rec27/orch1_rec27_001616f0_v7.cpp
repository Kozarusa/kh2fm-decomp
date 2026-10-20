#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_001616d8(u8* object);

typedef s32 (*QueryFn)(u8* self, void* out);

void func_001616f0(u8* object) {
    u8* provider = *(u8**)(object + 0x48);
    if (provider != 0) {
        Quad buffer[4];
        u8* table = *(u8**)provider;
        s32 result = (*(QueryFn*)(table + 0x18))(provider, buffer);
        if (result != 0) {
            func_001616d8(object);
        } else {
            if (object != (u8*)buffer) {
                volatile Quad* dst = (volatile Quad*)object;
                volatile Quad* src = buffer;
                // why: keeps load order
                // why: original uses t0-t3 for the block copy`r`n                register Quad a asm("$8") = src[0];
                register Quad b asm("$9") = src[1];
                register Quad c asm("$10") = src[2];
                register Quad d asm("$11") = src[3];
                dst[0] = a;
                dst[1] = b;
                dst[2] = c;
                dst[3] = d;
            }
        }
    }
}

