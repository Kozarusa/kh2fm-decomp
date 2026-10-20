#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023f5b8(...);
extern "C" u8* D_0035ee0c;
extern "C" u32 D_003723a0[];
void func_0024eff8(s32 index) {
 if(D_0035ee0c) {
 if(func_00139d78(D_0035ee0c)) { func_0023f5b8(D_0035ee0c,D_003723a0[index],0); return; }
 }
}
