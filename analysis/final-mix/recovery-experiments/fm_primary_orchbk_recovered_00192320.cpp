#include "../common/types.h"
struct Entry { s32 pointer; s32 other; };
extern "C" Entry D_01c61970[];
extern "C" s32 D_0033caf4;
extern "C" u8 D_0036cda0[];
extern "C" void func_002fee78(void*, u8*, s32);
extern "C" s32 func_001b1490(void*);
extern "C" void func_00191f78(s32, s32);

void func_00192320() {
    u8 buffer[48];
    s32 count = 2;
    Entry* entry = D_01c61970;
    do {
        entry->pointer = 0;
        count--;
        entry++;
    } while (count >= 0);
    func_002fee78(buffer, D_0036cda0, D_0033caf4);
    s32 result = func_001b1490(buffer);
    func_00191f78(1, result);
}
