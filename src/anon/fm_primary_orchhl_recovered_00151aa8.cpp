#include "../common/types.h"
extern "C" u32 func_00138c40(...);
extern "C" u32 func_00139d78(...);
extern "C" void func_0014fcd8(u8* object);
extern "C" u32 func_001519f8(u8* object);
extern "C" u32 func_00151c70(u8* object);

u32 func_00151aa8(u8* object) {
    u32 result;
    func_0014fcd8(object);
    if (*(s32*)(object + 2896) == 1) {
        result = func_00139d78(object + 840);
        if (result == 0) {
            return func_00151c70(object);
        }
    } else {
        result = func_00138c40(object + 840, *(s32*)(object + 32), *(s32*)(object + 36));
        f32 value = **(f32**)(object + 2884);
        *(f32*)(object + 2888) = value;
        if (*(f32*)(object + 2892) != value) {
            result = func_001519f8(object);
        }
        *(f32*)(object + 2892) = *(f32*)(object + 2888);
    }
    return result;
}
