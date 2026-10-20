#include "../common/types.h"
// Apply the supplied mask to four 64-bit fields, reset status, and clear vectors.
void func_00167658(u8* object,u64 mask)
{
 u64* fields=(u64*)object;
 register u32 first asm("$11")=(u32)object+32;
 register u64 a asm("$14")=fields[0]&mask;
 register u64 b asm("$13")=fields[1]&mask;
 register u64 c asm("$12")=fields[2]&mask;
 register u64 d asm("$15")=fields[3];
 asm("" : "+r"(a),"+r"(b),"+r"(c),"+r"(d));
 fields[0]=a;
 asm("" : "+r"(d) : : "memory");
 d&=mask;
 fields[1]=b; fields[2]=c; fields[3]=d;
 asm("" : : : "memory");
 *(u32*)(object+64)=0;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(first) : "memory");
 register u32 second asm("$4")=(u32)object+48;
 asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0); nop" : : "r"(second) : "memory");
}
