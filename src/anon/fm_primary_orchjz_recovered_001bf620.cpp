#include "../common/types.h"
struct CharaEntry {
    u32 id;
    f32 scale;
};
extern "C" CharaEntry D_0036dcf8[];
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001050d8(u64);
extern "C" u32 func_0016e920(u32);
extern "C" void func_001bf270(u32, u32, u32, u32, f32);

u32 func_001bf620(u32 first, u32 second) {
    u8* info = (u8*)func_001a80c8(first);
    CharaEntry* entry = &D_0036dcf8[info[22]];
    u32 object = func_001050d8(0x9f0);
    func_001bf270(object, func_0016e920(entry->id), second, first, entry->scale);
    return object;
}
