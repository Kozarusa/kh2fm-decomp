#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    f32 v[4];
};
struct __attribute__((aligned(16))) Placement {
    s32 a;
    f32 b;
    s32 c;
    s32 d;
    Vector offset;
};
extern "C" u8* func_0016bc20(u8*, s32, s32);
extern "C" s32 func_0016bff0(u8*);
extern "C" s32 func_0018a550(Placement*, Placement*);
extern "C" void func_0018a818(Placement*, u8*, u8*);
extern "C" void func_0018bfa0(u8*, u8*, f32);
extern "C" u8* func_001b9bc8(u8*);

u8* func_0018be00(u8* object, s32 kind) {
    Placement first;
    Vector firstScaled;
    Placement second;
    Vector secondScaled;
    u8* entry = func_0016bc20(object, kind, -1);
    if (entry == 0) {
        return 0;
    }
    first.d = 0;
    func_0018a818(&first, object, entry);
    first.b += first.b;
    // why: lq/sq copy primitive through t0 (plain Quad copy loads into t7 directly), same as kn::FVector::operator=
    asm volatile("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&firstScaled), "r"(object + 0x850) : "$8", "memory");
    // why: VU macro scale by a float broadcast, pattern from accepted sibling func_0016d760
    asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&firstScaled), "f"(firstScaled.v[3]) : "$8", "memory");
    // why: VU macro vector add, pattern from accepted sibling func_0016d760
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&first.offset), "r"(&firstScaled) : "memory");
    second.d = 0;
    u8* other = 0;
    while ((other = func_001b9bc8(other)) != 0) {
        if (func_0016bff0(other) == func_0016bff0(object)) {
            continue;
        }
        u8* found = func_0016bc20(other, kind, -1);
        if (found == 0) {
            continue;
        }
        func_0018a818(&second, other, found);
        second.b += second.b;
        // why: lq/sq copy primitive through t0 (plain Quad copy loads into t7 directly), same as kn::FVector::operator=
        asm volatile("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&secondScaled), "r"(other + 0x850) : "$8", "memory");
        // why: VU macro scale by a float broadcast, pattern from accepted sibling func_0016d760
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&secondScaled), "f"(secondScaled.v[3]) : "$8", "memory");
        // why: VU macro vector add, pattern from accepted sibling func_0016d760
        asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&second.offset), "r"(&secondScaled) : "memory");
        if (func_0018a550(&first, &second) != 0) {
            func_0018bfa0(object, other, second.b);
            return other;
        }
    }
    return 0;
}
