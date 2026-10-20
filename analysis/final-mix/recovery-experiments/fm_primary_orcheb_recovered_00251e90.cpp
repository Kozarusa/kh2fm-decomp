#include "../common/types.h"
extern "C" u32 D_0035ee60;
extern "C" u8 D_00372608[];
extern "C" u8 D_00372610[];
extern "C" u32 func_0028dbf8(u32,u8*,u8*);

u32 func_00251e90(s32 index) {
 return func_0028dbf8(D_0035ee60,D_00372608,index*8+D_00372610);
}
