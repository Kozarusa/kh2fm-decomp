#include "../common/types.h"
struct TableEntry {
    s32 key;
    s32 kind;
    u8 pad[24];
    u8 first[16];
    u8 second[36];
};
extern "C" TableEntry* D_0035dcf0;
extern "C" s32 func_002ff1a4(void*, s32);

TableEntry* func_00227b00(s32 first, s32 key, s32 second) {
    s32 index;
    for (index = 0; index < 128; index++) {
        if (D_0035dcf0[index].key == key && D_0035dcf0[index].kind == 3 && (func_002ff1a4(D_0035dcf0[index].first, first) == 0) && (func_002ff1a4(D_0035dcf0[index].second, second) == 0)) {
            return &D_0035dcf0[index];
        }
    }
    return 0;
}
