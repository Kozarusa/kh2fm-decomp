#include "../common/types.h"
struct Entry {
    s32 first;
    s32 second;
};
extern "C" s32 D_00340eac;
extern "C" Entry D_003a8ea0[];
extern "C" void func_00133c78(s32, s32, s32, s32, s32);

void func_00109360(s32 context, s32 index) {
    if (D_00340eac != index) {
        Entry* entry = &D_003a8ea0[index];
        if (entry->first != 0) {
            if (entry->second != 0) {
                func_00133c78(context, entry->first, entry->second, 0, 0);
            }
        }
        D_00340eac = index;
    }
}
