#include "../common/types.h"
extern "C" s32 func_001bc780(s32, u64, s32, u64);
extern "C" u8* func_001bd570(s32, s32);
extern "C" u32 func_001bc778(...);

void func_001be890(s32 object, s32 menu) {
    s32 index = 0;
    func_001bc778(menu);
    do {
        u8* entry = func_001bd570(object, index + 3);
        index++;
        func_001bc780(menu, *(u16*)(entry + 2), (s32)(entry + 12), *(u8*)(entry + 4));
    } while (index < 4);
}
