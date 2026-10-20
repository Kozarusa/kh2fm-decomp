#include "../common/types.h"
extern "C" u8 D_00348d68[];
extern "C" u32 func_001050c8(void);
extern "C" u32 func_001492c8(u8*);
extern "C" u32 func_00149448(u8*);
extern "C" u32 func_0015eba8(u8*, u32, u8, u64);
extern "C" u64 func_0015c228(...);

u32 func_00149c40(u64 value) {
    func_00149448(D_00348d68);
    u32 first = func_001492c8(D_00348d68);
    func_0015c228(first);
    u32 second = func_001050c8();
    return func_0015eba8(D_00348d68, second, 1, value);
}
