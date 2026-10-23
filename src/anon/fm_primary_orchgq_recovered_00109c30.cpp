#include "../common/types.h"
struct Entry {
    void* state;
    void* owner;
    s32 pad08;
    s32 pad0c;
    s32 value10;
    s32 pad14[15];
    s32 value50;
    s32 value54;
};
extern "C" u32 D_0033cc68;
extern "C" void* D_0033cc60;
extern "C" Entry* D_0033cc6c;

Entry* func_00109c30() {
    u32 index;
    Entry* result = 0;
    for (index = 0; index < D_0033cc68; index++) {
        if (D_0033cc6c[index].state == 0 && D_0033cc6c[index].owner == D_0033cc60) break;
    }
    if (index < D_0033cc68) {
        result = &D_0033cc6c[index];
        result->state = 0;
        result->owner = 0;
        result->value10 = 0;
        result->value50 = 0;
        result->value54 = 0;
    }
    return result;
}
