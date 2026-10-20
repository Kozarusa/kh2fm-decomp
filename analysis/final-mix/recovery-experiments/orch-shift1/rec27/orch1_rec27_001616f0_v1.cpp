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
        if (result == 0) {
            if (object != (u8*)buffer) {
                Quad* dst = (Quad*)object;
                dst[0] = buffer[0];
                dst[1] = buffer[1];
                dst[2] = buffer[2];
                dst[3] = buffer[3];
            }
        } else {
            func_001616d8(object);
        }
    }
}
