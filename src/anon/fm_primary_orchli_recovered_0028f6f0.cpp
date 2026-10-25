#include "../common/types.h"
extern "C" s32 D_0035f480;
extern "C" s32 func_00139d78(u32);
extern "C" s16* func_0028f690(s32 index);
extern "C" u32 func_00138c10(s32, u32);
extern "C" void func_0028d5d0(u8*);

void func_0028f6f0(s32 index) {
    if (D_0035f480 != 0) {
        s32 offset = index * 884;
        if (func_00139d78((u32)(D_0035f480 + offset)) != 0) {
            s16* entry = func_0028f690(index);
            s32 object = D_0035f480 + offset;
            if (*(s32*)(object + 388) != entry[1]) {
                func_00138c10(object, entry[1]);
                *(s32*)(D_0035f480 + offset + 392) = -1;
                func_0028d5d0((u8*)(D_0035f480 + offset + 436));
            }
        }
    }
}
