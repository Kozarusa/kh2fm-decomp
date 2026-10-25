#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8* D_00352050;
extern "C" Quad* func_0016c028(s32);
extern "C" u8* func_001c16f0(u32, u8*);
extern "C" void func_001ccac0(u32, u32);

u8* func_001cc9c8(s32 object, f32 range) {
    // why: original keeps the position copy at sp+0 and the difference at sp+16; one two-slot array fixes that layout
    Quad slots[2];
    register Quad copy asm("$8") = *func_0016c028(object); // why: original copies the quad through t0, as in accepted fm_primary_orchcw_recovered_001dbcd0.cpp
    slots[0] = copy;
    asm volatile("" ::: "memory"); // why: scheduling barrier; original sets up the loop registers only after the quad copy
    u8* cursor = 0;
    while ((cursor = func_001c16f0(*(u32*)(D_00352050 + 0x9f4), cursor)) != 0) {
        if (*(s32*)(cursor + 0x48) == 0) {
            f32* difference = (f32*)&slots[1];
            // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjp_recovered_001a4ff8.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
            asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                         : : "r"(difference), "r"(cursor), "r"(&slots[0]) : "memory");
            ((f32*)&slots[1])[1] = 0.0f;
            f32 length;
            // why: VU macro xyz length, same sequence as accepted fm_primary_orchjp_recovered_001a4ff8.cpp
            asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                         : "=f"(length) : "r"(difference) : "$8", "memory");
            if (length < range) {
                func_001ccac0((u32)cursor, object);
            }
        }
    }
    return cursor;
}
