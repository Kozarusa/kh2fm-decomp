#include "../common/types.h"
extern "C" u8* D_01d5ba10[];
extern "C" u8 D_003216b8[];
extern "C" u8* func_002fd248(u32, u8*, u32, u32, u8*);

u8* func_001d3408(u32 object) {
    u8** table = D_01d5ba10;
    for (s32 index = 0; index < 3; index++) {
        u8* entry = *table++;
        if (entry != 0) {
            u8* result = func_002fd248(object, entry + 8, *(u32*)(entry + 4), 96, D_003216b8);
            if (result != 0) {
                return result;
            }
        }
    }
    return 0;
}
