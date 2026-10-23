#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Matrix { Quad rows[4]; };
struct __attribute__((aligned(16))) Box { u8 bytes[32]; };
typedef f32 (*RadiusFn)(void*);
struct Shape { RadiusFn* table; };
extern "C" f32 D_0036b470;
extern "C" void func_00144450(Box*);
extern "C" void func_001447c0(Box*, f32, f32, f32, f32, f32, f32);
extern "C" void func_00144b38(Box*, u8*);
extern "C" void func_001605a0(u8*, Matrix*);

void func_001606e0(u8* object) {
    Box box;
    Matrix world;
    Matrix local;
    func_00144450(&box);
    register Quad* row1 asm("$14") = &world.rows[1]; // why: original keeps the second row pointer in t6
    register Quad* row2 asm("$12") = &world.rows[2]; // why: original keeps the third row pointer in t4
    register Quad* row3 asm("$13") = &world.rows[3]; // why: original keeps the fourth row pointer in t5
    Matrix* source = (Matrix*)(object + 16);
    if (&world != source) {
        // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(&world), "r"(source) : "$8", "$9", "$10", "$11", "memory");
    }
    const f32* scalePointer = &D_0036b470;
    asm("" : "+r"(scalePointer)); // why: original forms the full address before the lwc1
    f32 scale = *scalePointer;
    // why: VU macro scale by a float broadcast, pattern from accepted 00159d30
    asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(row1), "f"(scale) : "$8", "memory");
    // why: VU macro scale by a float broadcast, pattern from accepted 00159d30
    asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(row2), "f"(scale) : "$8", "memory");
    // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8
    asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                 : : "r"(&local), "r"(object + 272) : "$8", "$9", "$10", "$11", "memory");
    // why: VU0 macro matrix times matrix, four copies of the vector-times-matrix sequence of accepted 00140500/001605a0
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,16(%0); lqc2 $vf3,32(%0); lqc2 $vf4,48(%0); lqc2 $vf5,0(%1); lqc2 $vf6,16(%1); lqc2 $vf7,32(%1); lqc2 $vf8,48(%1); "
                 "vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; "
                 "vmulax.xyzw ACC,$vf1,$vf6x; vmadday.xyzw ACC,$vf2,$vf6y; vmaddaz.xyzw ACC,$vf3,$vf6z; vmaddw.xyzw $vf6,$vf4,$vf6w; "
                 "vmulax.xyzw ACC,$vf1,$vf7x; vmadday.xyzw ACC,$vf2,$vf7y; vmaddaz.xyzw ACC,$vf3,$vf7z; vmaddw.xyzw $vf7,$vf4,$vf7w; "
                 "vmulax.xyzw ACC,$vf1,$vf8x; vmadday.xyzw ACC,$vf2,$vf8y; vmaddaz.xyzw ACC,$vf3,$vf8z; vmaddw.xyzw $vf8,$vf4,$vf8w; "
                 "sqc2 $vf5,0(%0); sqc2 $vf6,16(%0); sqc2 $vf7,32(%0); sqc2 $vf8,48(%0)"
                 : : "r"(&world), "r"(&local) : "memory");
    Quad* position = (Quad*)(object + 640);
    if (position != row3) {
        // why: 16-byte vector copy, same lq/sq copy as accepted 001605a0 Vector operator=
        asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(position), "r"(row3) : "$8", "memory");
    }
    Shape* shape = *(Shape**)(object + 4);
    f32* bounds = (f32*)(object + 356);
    f32 radius = shape->table[3](shape);
    func_001447c0(&box, bounds[0] - radius, bounds[1] - radius, bounds[2] - radius,
                  bounds[3] + radius, bounds[4] + radius, bounds[5] + radius);
    func_00144b38(&box, object + 144);
    // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8
    asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                 : : "r"(&local), "r"(&world) : "$8", "$9", "$10", "$11", "memory");
    func_001605a0(object, &local);
}
