#include "../common/types.h"
extern "C" void func_001666d0(void*,u16,u32,u16,u16);
void func_0014db78(u32 p,u16 a,u32 c,u16 d,u16 e,u16 f,u32 g) {
 func_001666d0((void*)p,a,c,d,e);
 *(u32*)(p+0x1d0)=g;
 *(volatile u16*)(p+0x1d4)=f;
}
