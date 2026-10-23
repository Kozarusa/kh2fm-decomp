#include "../common/types.h"
extern "C" u8 D_01e2a410[];
extern "C" u32 func_002b6adc(u32,u32);
extern "C" u32 func_002bcfe8(void*);
extern "C" u32 func_002bd030(void*);

u32 func_002ba040() {
    s32 index = 0;
    u32 result;
    func_002bcfe8(D_01e2a410);
    func_002bd030(D_01e2a410);
    do {
        s32 slot = index + 0x14;
        func_002b6adc(2, slot);
        index++;
        result = func_002b6adc(0, slot);
    } while (index < 2);
    return result;
}
