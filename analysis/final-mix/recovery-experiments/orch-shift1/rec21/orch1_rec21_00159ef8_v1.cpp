#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad D_0034aa50[2];
extern "C" Quad* func_0016c028(s32);

void func_00159ef8(u8* object) {
    Quad* source = (Quad*)(object + 0x80);
    Quad* result = func_0016c028(*(s32*)(object + 0x44));
    if (source != &D_0034aa50[0]) {
        D_0034aa50[0] = *source;
    }
    if (result != &D_0034aa50[1]) {
        D_0034aa50[1] = *result;
    }
}
