#include "../common/types.h"
extern "C" u32 D_00352738[];
extern "C" u8* D_01d5ba28;
// why: no accepted declaration (only a placeholder definition); the original passes the entry pointer in a0 and the result is never used
extern "C" void func_001d3c18(u8*);

void func_001d4078(s32 id) {
    s32 i;
    if (id == 609) {
        u32* key = D_00352738;
        for (i = 0; i < 4; i++, key++) {
            for (s32 j = 0; j < *(s32*)(D_01d5ba28 + 4); j++) {
                u8* entry = D_01d5ba28 + j * 64 + 8;
                if (*(u16*)(entry + 0x28) == *key) {
                    func_001d3c18(entry);
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < *(s32*)(D_01d5ba28 + 4); i++) {
            u8* entry = D_01d5ba28 + i * 64 + 8;
            if (*(u16*)(entry + 0x28) == id) {
                func_001d3c18(entry);
                return;
            }
        }
    }
}
