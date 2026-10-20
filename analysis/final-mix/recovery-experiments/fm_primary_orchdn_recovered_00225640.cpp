#include "../common/types.h"
extern "C" u32 D_0035dae4;
extern "C" u32 func_00227818(u32, u32, u32);
extern "C" u32 func_00225eb8(u32, u32, u32);
extern "C" u32 func_00227858(u32, u32, u32);

u32 func_00225640(u32 object, u32 buffer, u32 work) {
    u32 result = func_00227818(object, buffer, work);
    result = func_00225eb8(D_0035dae4, result, work);
    return func_00227858(result, buffer, work);
}
