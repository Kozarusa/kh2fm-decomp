#include "../common/types.h"

extern "C" u32 func_0016ced0(s32);
extern "C" u32 func_00188398(u8*, u16, s32*, s32);

void func_00187b90(u8* object) {
    if (*(s32*)(object + 148) != 0) {
        s32 data[1];
        u8* entry = *(u8**)(object + 144);
        s32 value = *(s32*)(object + 136);
        u16 id = *(u16*)(entry + 10);
        data[0] = value;
        func_00188398(object, id, data, 1);
        func_0016ced0(*(s32*)(object + 148));
        *(s32*)(object + 148) = 0;
        *(s32*)(object + 144) = 0;
    }
}
