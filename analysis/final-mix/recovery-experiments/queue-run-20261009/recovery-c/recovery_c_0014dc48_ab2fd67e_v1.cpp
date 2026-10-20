#include "../common/types.h"
extern "C" u32 func_001666f0(void*,u16,u32,u16,u16);
void func_0014dc48(u32 p,u16 a,u32 b,u16 c,u16 d,u16 e,u32 f) {
func_001666f0((void*)p,a,b,c,d);
*(u32 *)(p+0x1d0)=f;asm volatile("" ::: "memory");*(u16 *)(p+0x1d4)=e;asm volatile("" ::: "memory");*(u8 *)(p+0x1d9)=0;asm volatile("" ::: "memory");*(u8 *)(p+0x1d6)=0;asm volatile("" ::: "memory");*(u8 *)(p+0x1d7)=0;asm volatile("" ::: "memory");*(u8 *)(p+0x1d8)=0;
}