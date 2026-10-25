#include "../common/types.h"
extern "C" u8 D_001cab08[];
extern "C" s32 func_001db888(...);
// why: types of the accepted definition fm_primary_workerbacklog_recovered_001ca988.cpp
extern "C" void func_001ca988(u32, u32, u32, u32, u32, u32);

s32 func_001cbc50(u8* object, void* first, void* second, void* third) {
    s32 out = 0;
    u8* pool = *(u8**)(object + 2548) + 20;
    if (*(u32*)(pool + 8)) {
        // why: the original passes its own return address (move a2,ra) as the third argument
        s32 entry = func_001db888(pool, 192, __builtin_return_address(0));
        func_001ca988(entry, (u32)object, (u32)first, (u32)second, (u32)D_001cab08, (u32)third);
        out = entry;
    }
    return out;
}
