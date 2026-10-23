#include "../common/types.h"
struct Entry { u16 id : 15; u16 flag : 1; };
extern "C" u32 func_001058e8(void);
extern "C" s32 func_00114620(...);
extern "C" u16 func_0016a070(...);
extern "C" int func_00188fe0(...);
extern "C" s32 func_001a35f8(...);

// Preserve original registry aliases.
s32 func_0010f7b0(u8* object, s32 ability, s32 item) asm("_Z16ctarget_0010f7b0jjjj");

s32 func_0010f7b0(u8* object, s32 ability, s32 item) {
    if (item < 0) item = func_00114620(ability);
    if (item == 0) return 0;
    if (func_001a35f8(item, func_0016a070(object)) <= 0) return 0;
    u32 base = func_001058e8() + 9456;
    s32 table = func_00188fe0(base, func_0016a070(object));
    u16 key = item;
    Entry* pointer = (Entry*)(table + 84);
    for (s32 index = 0; index < 80; index++) {
        Entry value = *pointer++;
        u32 flag = value.flag;
        if (value.id == key && flag != 0) return 1;
    }
    return 0;
}
