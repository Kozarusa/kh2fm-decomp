#include "../common/types.h"
extern "C" u32* D_0035ec90;
extern "C" u32 func_00105870(...);
extern "C" u32 func_002409b8(u32*);

u32 func_00240a08(u32* object) {
    if (!object) object = D_0035ec90;
    u32 result = func_002409b8(object);
    if (result != object[2]) return 0;
    result = func_00105870();
    if (object[0] != result) return 0;
    return object[1] == 0x3a;
}
