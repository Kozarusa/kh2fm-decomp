#include "../common/types.h"
extern "C" void func_00225530(u8*);
extern "C" u32 func_00225280(u32,u32);
extern "C" u32 D_00370d88[];

u32 func_00225328(u8* object) {
 if (*(u16*)(object+6)) func_00225530(object);
 u16 value=*(u16*)(object+8);
 if (value==0) return func_00225280(object[11],12288);
 if (value==257) return func_00225280(object[11],6144);
 return func_00225280(object[11],D_00370d88[object[9]]);
}
