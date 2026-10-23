#include "../common/types.h"
extern "C" u64 func_001a1de0(u32);
extern "C" u64 func_00138c10(u32, u32);

u64 func_00157aa0(u8* object) {
    if (func_001a1de0(*(u32*)(*(u32*)(object + 0x34) + 0x48c)) == 0) {
        return func_00138c10((u32)(object + 10000), 0x75);
    }
    return func_00138c10((u32)(object + 10000), 0x6f);
}
