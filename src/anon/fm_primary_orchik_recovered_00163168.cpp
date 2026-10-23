#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Sphere { Quad center; f32 radius; };
struct PointList { Quad* points[4]; s32 count; };

s32 func_00163168(Sphere* sphere, PointList* list, Quad* result) {
    f32 best = sphere->radius * sphere->radius;
    s32 found = 4;
    s32 index;
    s32 count = list->count;
    for (index = 0; index < count; index++) {
        register f32 distance asm("$f1"); // why: original moves the squared distance into f1
        // why: VU macro squared distance; lqc2/vsub/vmove/vmul.xyz/vaddy.x/vaddz.x/qmfc2 as in accepted 00163210, fm_fallback_vector and 002229a0
        asm volatile("lqc2 $vf6,0(%1); lqc2 $vf4,0(%2); vsub.xyzw $vf5,$vf6,$vf4; vmove.xyzw $vf4,$vf5; vmul.xyz $vf5,$vf4,$vf5; vaddy.x $vf5,$vf5,$vf5y; vaddz.x $vf5,$vf5,$vf5z; qmfc2 $2,$vf5; mtc1 $2,%0"
                     : "=f"(distance) : "r"(&sphere->center), "r"(list->points[index]) : "$2", "memory");
        if (distance <= best) {
            best = distance;
            found = index;
        }
    }
    if (found != 4) {
        Quad* source = list->points[found];
        if (result != source) {
            // why: 16-byte vector copy, same lq/sq copy as accepted 001605a0 Vector operator=
            asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(result), "r"(source) : "$8", "memory");
        }
        return 1;
    }
    return 0;
}
