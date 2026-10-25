#include "../common/types.h"
extern "C" void func_002e7458(void*);
extern "C" s32 func_002e7568(u32, u32, u8*, f32);
extern "C" u8 D_00362190[];

s32 func_002d4868(u32 object) {
    func_002e7458((void*)(object + 3208));
              s32 result = func_002e7568(object, 2, D_00362190, 1.0f);
    *(u32*)(object + 2876) = 0;
    return result;
}
