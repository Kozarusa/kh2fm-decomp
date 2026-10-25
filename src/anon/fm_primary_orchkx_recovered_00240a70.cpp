#include "../common/types.h"
struct SaveBlock {
    u32 words[21];
};
struct SaveFlags {
    u64 low : 40;
    u64 named : 1;
    u64 high : 23;
};
extern "C" u8* D_0035ec90;
extern "C" SaveBlock D_0035ec30;
extern "C" u32 func_001058e8(void);
extern "C" u32 func_002fdd68(...);
// why: no recovered source declares or calls func_00241e18; its v0 is stored as a byte by the original, so it is declared with a u8 result and no arguments (none are set before the jal)
extern "C" u8 func_00241e18(void);
extern "C" s32 func_00241ed8(s32);
extern "C" u32 func_002409b8(u32*);

u32 func_00240a70(u8* object) {
    if (!object) object = D_0035ec90;
    func_002fdd68(object, func_001058e8(), 0x10fc0);
    *(object + 16796) = func_00241e18();
    ((SaveFlags*)(object + 16792))->named = func_00241ed8(object[12]) != 0;
    *(SaveBlock*)(object + 9284) = D_0035ec30;
    u32 result = func_002409b8((u32*)object);
    *(u32*)(object + 8) = result;
    return result;
}
