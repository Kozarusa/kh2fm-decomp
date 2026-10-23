#include "../common/types.h"
extern "C" s32 D_0035dae4;
extern "C" void func_00225fa0(s32,s32);
extern "C" u32 func_00227930(u8*);

u32 func_00225690(u8* object) {
 func_00225fa0(D_0035dae4,*(s32*)(object+24));
 return func_00227930(object);
}
