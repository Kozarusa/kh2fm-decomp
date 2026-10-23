#include "../common/types.h"
extern "C" u8 D_0036e538[];
extern "C" u32 func_001ba158(void);
extern "C" u32 func_00181178(...);

void func_001d5198(u8* object) {
    if (object[0] == 16) {
        u32* world = (u32*)func_001ba158();
        u8* entry = D_0036e538;
        u32 index = 0;
        do {
            if (entry[0] == object[1]) {
                *world = entry[1];
                func_00181178(*(u16*)(entry + 2));
                return;
            }
            index++;
            entry += 4;
        } while (index < 4);
    }
}
