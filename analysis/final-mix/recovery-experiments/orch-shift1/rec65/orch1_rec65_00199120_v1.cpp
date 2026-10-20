#include "../common/types.h"
struct Entry {
    u8 data[88];
};
extern "C" Entry D_01c61b48[];
extern "C" void func_00198dc0(Entry*);

void func_00199120(s32 mode, s32 id) {
    if (id == 0xffff && mode == 1) {
        Entry* entry = D_01c61b48;
        s32 count = 15;
        do {
            count--;
            func_00198dc0(entry);
            entry++;
        } while (count != -1);
    }
}
