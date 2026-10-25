#include "../common/types.h"
#include "../kn/fvector.hpp"
// why: the argument register a0 holds the object at the call and is not reloaded; accepted call sites declare it as bool func_00197920(...)
extern "C" bool func_00197920(u8*);
extern "C" s32 func_0016c028(u8*);
// why: parameters derived from the registers set before the jal (a0 object, a1 vector, a2 object+0x120, a3 object+0x130); the original of func_002e2a30 is not recovered
extern "C" void func_002e2a30(u8*, kn::FVector*, u8*, u8*);

// why: void per ruling #36: the IsExec exits leave its own result (direct, exits 1-3), the last exit leaves whatever func_002e2a30 left, and that function's own instructions never write v0 (stale-b, clarification iii); no float is live at any exit

void func_002e2940(u8* object, u8* actor, kn::FVector* offset, kn::FVector* velocity) {
    if (!func_00197920(object) && *(u8*)(object + 0x58) != 0 && (*(u32*)(actor + 0x588) & 0x80) != 0) {
        kn::FVector sum;
        kn::FVector moved;
        kn::FVector next;
        kn::FVector delta;
        kn::FVector* base = (kn::FVector*)func_0016c028(actor);
        // why: VU0 macro vector add, the same asm text as accepted 00140500/0016d340
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&moved), "r"(base), "r"(offset) : "memory");
        // why: VU0 macro vector add, the same asm text as accepted 00140500/0016d340
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&sum), "r"(&moved), "r"(velocity) : "memory");
        // why: lq/sq copy without the self-check beq the original lacks; plain operator= (v3) differed by 43 words and a kn::V4 struct copy (v4) by 5; same lq/sq text as accepted 0015d058 but with clobber "$8" instead of "t0"
        asm volatile("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&moved), "r"(&sum) : "$8", "memory");
        func_002e2a30(object, &moved, object + 0x120, object + 0x130);
        // why: VU0 macro vector subtract, the same asm text as accepted 0018e8f0 except that one omits its trailing .set noreorder/.set reorder directives
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&delta), "r"(&moved), "r"(&sum) : "memory");
        // why: VU0 macro vector add, the same asm text as accepted 00140500/0016d340
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&next), "r"(&delta), "r"(velocity) : "memory");
        *velocity = next;
    }
}
