#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8 D_001dbd38[];
extern "C" void func_001c1748(u8*, u32, Quad*, u8*);

void func_001dbc58(u8* object, u32 arg, Quad* vector, u8* source) {
    func_001c1748(object, arg, vector, D_001dbd38);
    Quad* dest = (Quad*)(object + 0x30);
    Quad value = *vector;
    *dest = value;
    *(u8**)(object + 0x5c) = source;
    *(u8*)(object + 0x50) = 0;
    *(s8*)(object + 0x16) = -1;
    *(u8*)(object + 0x51) = 0;
    *(u32*)(object + 0x54) = 0;
    *(u32*)(object + 0x58) = 0;
    *(u8*)(object + 0x14) = *source;
}
