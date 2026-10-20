#include "../common/types.h"

// VU macro-mode instructions have no scalar C++ equivalent. Lane masks and
// unusual register choices are retained from the original instruction stream.
struct __attribute__((aligned(16))) FmVector { u32 x,y,z,w; };

void func_002226a0(FmVector* target,const FmVector* source) {
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vmove.xy $vf1,$vf2; sqc2 $vf31,0(%0); nop" : : "r"(target),"r"(source) : "memory");
}
void func_002226b8(FmVector* target,const FmVector* source) {
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vmove.xyz $vf1,$vf2; sqc2 $vf1,0(%0); nop" : : "r"(target),"r"(source) : "memory");
}
void func_00222710(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); lqc2 $vf3,0(%0); vadd.xy $vf3,$vf1,$vf2; sqc2 $vf3,0(%0); nop" : : "r"(target),"r"(first),"r"(second) : "memory");
}
void func_00222730(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); lqc2 $vf3,0(%0); vsub.xyz $vf3,$vf1,$vf2; sqc2 $vf3,0(%0); nop" : : "r"(target),"r"(first),"r"(second) : "memory");
}
void func_00222750(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); lqc2 $vf3,0(%0); vadd.xyz $vf3,$vf1,$vf2; sqc2 $vf3,0(%0); nop" : : "r"(target),"r"(first),"r"(second) : "memory");
}
void func_00222770(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); lqc2 $vf3,0(%0); vsub.xy $vf3,$vf1,$vf2; sqc2 $vf3,0(%0); nop" : : "r"(target),"r"(first),"r"(second) : "memory");
}
void func_002f3ef8(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,0(%2); vadd.xyzw $vf6,$vf4,$vf5" : : "r"(target),"r"(first),"r"(second) : "memory");
    asm("sqc2 $vf6,%0" : "=m"(*target));
}

void func_002f3d50(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,0(%2); vopmula.xyz ACC,$vf4,$vf5; vopmsub.xyz $vf6,$vf5,$vf4; vsub.w $vf6,$vf6,$vf6; sqc2 $vf6,0(%0)" : : "r"(target),"r"(first),"r"(second) : "memory");
}

void func_002f3f10(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,0(%2); vsub.xyzw $vf6,$vf4,$vf5; sqc2 $vf6,0(%0)" : : "r"(target),"r"(first),"r"(second) : "memory");
}

void func_002f3f28(FmVector* target,const FmVector* first,const FmVector* second) {
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,0(%2); vmul.xyzw $vf6,$vf4,$vf5; sqc2 $vf6,0(%0)" : : "r"(target),"r"(first),"r"(second) : "memory");
}

void func_002f3fc0(FmVector* target,const FmVector* source) {
    asm volatile("lqc2 $vf4,0(%1); vftoi4.xyzw $vf5,$vf4; sqc2 $vf5,0(%0)" : : "r"(target),"r"(source) : "memory");
}

void func_002f3fd0(FmVector* target,const FmVector* source) {
    asm volatile("lqc2 $vf4,0(%1); vftoi0.xyzw $vf5,$vf4; sqc2 $vf5,0(%0)" : : "r"(target),"r"(source) : "memory");
}

void func_0017fdf8(u8* object) {
    register u8* target asm("$4")=object+0xa0;
    asm("" : "+r"(target));
    asm volatile("vsub.xyzw $vf1,$vf0,$vf0; sqc2 $vf1,0(%0); nop" : : "r"(target) : "memory");
}

void func_002f3e90(FmVector* target,const FmVector* source,f32 divisor) {
    asm volatile("lqc2 $vf4,0(%1); mfc1 $8,%2; qmtc2 $8,$vf5; vdiv Q,$vf0w,$vf5x; vwaitq; vmulq.xyzw $vf4,$vf4,Q; sqc2 $vf4,0(%0)" : : "r"(target),"r"(source),"f"(divisor) : "$8","memory");
}

void func_002f3f40(FmVector* target,const FmVector* source,f32 multiplier) {
    asm volatile("lqc2 $vf4,0(%1); mfc1 $8,%2; qmtc2 $8,$vf5; vmulx.xyzw $vf6,$vf4,$vf5x; sqc2 $vf6,0(%0)" : : "r"(target),"r"(source),"f"(multiplier) : "$8","memory");
}

void func_002f4870(FmVector* target,const FmVector* source,f32 multiplier) {
    asm volatile("lqc2 $vf4,0(%1); mfc1 $8,%2; qmtc2 $8,$vf5; vmulx.xyz $vf4,$vf4,$vf5x; sqc2 $vf4,0(%0)" : : "r"(target),"r"(source),"f"(multiplier) : "$8","memory");
}

void func_002f3d98(FmVector* target,const FmVector* source) {
    asm volatile("lqc2 $vf4,0(%1); vmul.xyz $vf5,$vf4,$vf4; vaddy.x $vf5,$vf5,$vf5y; vaddz.x $vf5,$vf5,$vf5z; vsqrt Q,$vf5x; vwaitq; vaddq.x $vf5,$vf0,Q; vnop; vnop; vdiv Q,$vf0w,$vf5x; vsub.xyzw $vf6,$vf0,$vf0; vwaitq; vmulq.xyz $vf6,$vf4,Q; sqc2 $vf6,0(%0)" : : "r"(target),"r"(source) : "memory");
}

void func_002f3ed0(FmVector* target,const FmVector* first,const FmVector* second,f32 weight) {
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,0(%2); mfc1 $8,%3; qmtc2 $8,$vf6; vaddw.x $vf7,$vf0,$vf0w; vsub.x $vf8,$vf7,$vf6; vmulax.xyzw ACC,$vf4,$vf6x; vmaddx.xyzw $vf9,$vf5,$vf8x; sqc2 $vf9,0(%0)" : : "r"(target),"r"(first),"r"(second),"f"(weight) : "$8","memory");
}

void func_002f3f58(FmVector* target,const FmVector* matrix,const FmVector* translation) {
    asm volatile("lqc2 $vf4,0(%2); lqc2 $vf5,48(%1); lq $7,0(%1); lq $8,16(%1); lq $9,32(%1); vadd.xyz $vf5,$vf5,$vf4; sq $7,0(%0); sq $8,16(%0); sq $9,32(%0); sqc2 $vf5,48(%0)" : : "r"(target),"r"(matrix),"r"(translation) : "$7","$8","$9","memory");
}

void func_002f3f98(FmVector* target,const FmVector* source) {
    asm volatile("lq $6,0(%1); lq $7,16(%1); lq $8,32(%1); lq $9,48(%1); sq $6,0(%0); sq $7,16(%0); sq $8,32(%0); sq $9,48(%0)" : : "r"(target),"r"(source) : "$6","$7","$8","$9","memory");
}

void func_002f3dd8(FmVector* target,const FmVector* source) {
    asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); pextlw $12,$9,$8; pextuw $13,$9,$8; pextlw $14,$11,$10; pextuw $15,$11,$10; pcpyld $8,$14,$12; pcpyud $9,$12,$14; pcpyld $10,$15,$13; pcpyud $11,$13,$15; sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)" : : "r"(target),"r"(source) : "$8","$9","$10","$11","$12","$13","$14","$15","memory");
}

void func_002f3e20(FmVector* target,const FmVector* source) {
    asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lqc2 $vf4,48(%1); vmove.xyzw $vf5,$vf4; vsub.xyz $vf4,$vf4,$vf4; vmove.xyzw $vf9,$vf4; qmfc2 $11,$vf4; pextlw $12,$9,$8; pextuw $13,$9,$8; pextlw $14,$11,$10; pextuw $15,$11,$10; pcpyld $8,$14,$12; pcpyud $9,$12,$14; pcpyld $10,$15,$13; qmtc2 $8,$vf6; qmtc2 $9,$vf7; qmtc2 $10,$vf8; vmulax.xyz ACC,$vf6,$vf5x; vmadday.xyz ACC,$vf7,$vf5y; vmaddz.xyz $vf4,$vf8,$vf5z; vsub.xyz $vf4,$vf9,$vf4; sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sqc2 $vf4,48(%0)" : : "r"(target),"r"(source) : "$8","$9","$10","$11","$12","$13","$14","$15","memory");
}

f32 func_002f3d70(const FmVector* first,const FmVector* second) {
    f32 result;
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,0(%2); vmul.xyz $vf5,$vf4,$vf5; vaddy.x $vf5,$vf5,$vf5y; vaddz.x $vf5,$vf5,$vf5z; qmfc2 $2,$vf5; mtc1 $2,%0; nop" : "=f"(result) : "r"(first),"r"(second) : "$2","memory");
    return result;
}
