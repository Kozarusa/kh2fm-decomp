#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 D_0035ee80;
extern "C" u32 D_0035ee5c;

u32 func_002519d0() {
 u32 result=func_00139d78(D_0035ee80);
 if(!result) result=func_0028acc8(D_0035ee5c);
 return result;
}
