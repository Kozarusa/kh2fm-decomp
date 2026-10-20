#include "../common/types.h"
extern "C" u8* D_0035ec90;
extern "C" void func_00242408();
extern "C" u32 func_00242418(u8*, s32);

u32 func_00241670(u8* object) {
 func_00242408();
 u32 first=func_00242418(object,0x8a58);
 func_00242408();
 u32 second=func_00242418(D_0035ec90,0x8a58);
 return first==second;
}
