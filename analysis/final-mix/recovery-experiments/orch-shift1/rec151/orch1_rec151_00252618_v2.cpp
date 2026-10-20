#include "../common/types.h"
extern "C" u16 func_002891e8(...);
extern "C" s32 func_00252110(u32);
extern "C" u32 func_0028dac8(...);
extern "C" u32 D_0035ee58;
extern "C" u32 D_0035ee7c;
struct Entry { s16 field[3]; };
extern "C" Entry D_00372650[];
u32 func_00252618() {
 s32 index=func_00252110(func_002891e8(D_0035ee58));
 return func_0028dac8(D_0035ee7c,D_00372650[index].field[1]);
}

