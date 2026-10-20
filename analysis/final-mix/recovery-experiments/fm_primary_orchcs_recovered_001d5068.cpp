#include "../common/types.h"
struct Entry { s32 pad0; s32 count; };
extern "C" Entry* D_01d5ba68;
extern "C" s32 D_00352768;
extern "C" u8 D_00321790[];
extern "C" u8* func_002fd248(s64, void*, s32, s32, void*);
extern "C" u8* func_00168b38(s32, s32, s32);
extern "C" void func_0023cde8(s32);

void func_001d5068(s64 object) {
    Entry* entry = D_01d5ba68;
    u8* result = func_002fd248(object, (u8*)entry + 8, entry->count, 2, D_00321790);
    u8* second = func_00168b38(D_00352768, 47, result[1]);
    func_0023cde8(*(s32*)(second + 8));
}
