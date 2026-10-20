#include "../common/types.h"
extern "C" bool func_001a6d08(u32);
extern "C" u32 func_001a6c90(u32);
extern "C" u16 func_002891e8(...);
extern "C" u32 D_0035ee34;
extern "C" u8 D_00372438[];

u32 func_00250748() {
 u32 index=func_002891e8(D_0035ee34);
 u32 value=D_00372438[index];
 u32 result=func_001a6d08(value);
 if(!result) return func_001a6c90(value);
 return result;
}
