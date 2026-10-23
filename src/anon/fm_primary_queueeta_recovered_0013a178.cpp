#include "../common/types.h"
struct __attribute__((aligned(16))) ProjectedVector { u32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { f32 columns[4][4]; };
extern "C" ProjectedVector D_003b8b40;
// Transform, divide by w, convert all lanes to integers, then apply viewport
// offsets in the shared output buffer and return that buffer.

ProjectedVector* func_0013a178(const f32* vector,const VUMatrix* matrix)
{
 register u8* high asm("$12");
 register ProjectedVector* result asm("$13");
 asm("lui %0,%%hi(D_003b8b40); addiu %1,%0,%%lo(D_003b8b40)" : "=r"(high),"=r"(result));
 asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,16(%1); lqc2 $vf6,32(%1); lqc2 $vf7,48(%1); lqc2 $vf8,0(%0); vmulax.xyzw ACC,$vf4,$vf8x; vmadday.xyzw ACC,$vf5,$vf8y; vmaddaz.xyzw ACC,$vf6,$vf8z; vmaddw.xyzw $vf12,$vf7,$vf8w; vdiv Q,$vf0w,$vf12w; vwaitq; vmulq.xyzw $vf12,$vf12,Q; vftoi0.xyzw $vf13,$vf12; sqc2 $vf13,0(%2)"
              : : "r"(vector),"r"(matrix),"r"(result) : "memory");
 register u32 x asm("$14")=*(u32*)(high-0x74c0);
 register u32 y asm("$15")=result->y;
 asm("" : "+r"(x),"+r"(y));
 *(u32*)(high-0x74c0)=x-1792;
 asm("" : "+r"(y) : : "memory");
 result->y=y-1840;
 return result;
}
