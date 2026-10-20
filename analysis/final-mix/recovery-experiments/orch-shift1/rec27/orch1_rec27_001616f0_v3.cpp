#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Block64 {
    Quad q[4];
};
extern "C" void func_001616d8(u8* object);

typedef s32 (*QueryFn)(u8* self, void* out);

void func_001616f0(u8* object) {
    u8* provider = *(u8**)(object + 0x48);
    if (provider != 0) {
        Block64 buffer;
        u8* table = *(u8**)provider;
        s32 result = (*(QueryFn*)(table + 0x18))(provider, &buffer);
        if (result != 0) {
            func_001616d8(object);
        } else {
            if (object != (u8*)&buffer) {
                *(Block64*)object = buffer;
            }
        }
    }
}
