#include "../common/types.h"
typedef void (*Method)(void*);
struct Slot {
    s32 state;
    s32 handle;
    void* object;
    u8 pad[28];
};
extern "C" Slot* D_0035dcfc;
extern "C" u32 func_001ba028(...);
extern "C" void func_00232db0(s32);

s32 func_0022f5e8() {
    s32 result = 0;
    if (D_0035dcfc == 0) return 0;
    for (s32 index = 0; index < 96; index++) {
        if (D_0035dcfc[index].object != 0) {
            func_001ba028(D_0035dcfc[index].object);
            void* object = D_0035dcfc[index].object;
            (*(Method**)object)[10](object);
            // why: original reloads the table pointer after this store, so the store is typed like the table pointer to let it alias
            *(Slot**)&D_0035dcfc[index].object = 0;
            func_00232db0(D_0035dcfc[index].handle);
            result = 1;
            D_0035dcfc[index].state = -1;
        }
    }
    return result;
}
