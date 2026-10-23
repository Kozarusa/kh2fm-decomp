#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    inline Vector& operator=(const Vector& rhs) {
        if (this == &rhs) {
            return *this;
        }
        // why: same lq/sq copy as the accepted kn::FVector operator=
        asm("lq $8, 0(%1);"
            "sq $8, 0(%0);"
            :
            : "r"(this), "r"(&rhs)
            : "t0");
        return *this;
    }
};
extern "C" void func_001447e0(u8*, Vector*, Vector*);

void func_001605a0(u8* object, Vector* matrix) {
    Vector min;
    Vector max;
    Vector point;
    Vector temp;
    s32 index;
    Vector* points = (Vector*)(object + 144);
    for (index = 0; index < 8; index++) {
        Vector* source = &points[index];
        // why: VU0 macro vector times matrix, same sequence as accepted 00140500/0013a178/00139c90; trailing directives emit nothing and keep gas from moving sqc2 into the next delay slot
        asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0); .set noreorder; .set reorder"
                     : : "r"(&temp), "r"(source), "r"(matrix) : "memory");
        *source = temp;
        point = *source;
        if (index == 0) {
            min = max = point;
        } else {
            if (point.x < min.x) {
                min.x = point.x;
            } else if (max.x < point.x) {
                max.x = point.x;
            }
            if (point.y < min.y) {
                min.y = point.y;
            } else if (max.y < point.y) {
                max.y = point.y;
            }
            if (point.z < min.z) {
                min.z = point.z;
            } else if (max.z < point.z) {
                max.z = point.z;
            }
        }
    }
    func_001447e0(object + 656, &min, &max);
}
