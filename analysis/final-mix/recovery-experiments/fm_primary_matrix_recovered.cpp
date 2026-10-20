#include "../common/types.h"

// Four-vector copy followed by sign changes in matrix columns. Hardware copy
// width and self-assignment guard derive from the original native instructions.
struct __attribute__((aligned(16))) FmMatrix4 { f32 elements[16]; };

void func_0011d500(u32* object, s32 index, const FmMatrix4* source) {
    register u32 base asm("$14") = object[11];
    register u32* saved asm("$13") = object;
    register u32 offset asm("$4") = index * 0x40;
    register FmMatrix4* destination asm("$15") = (FmMatrix4*)(base + offset);
    asm volatile("" : : "r"(saved), "r"(offset), "r"(base), "r"(index));
    // The self-copy branch conditionally computes the first element address.
    // The copy path reloads the base after stores, preserving possible aliasing.
    asm volatile(".set push\n\t.set noreorder\n\t"
                 "beql %1,%4,1f\n\taddu %0,%0,%2\n\t"
                 "lq $8,0(%4)\n\tlq $9,16(%4)\n\tlq $10,32(%4)\n\tlq $11,48(%4)\n\t"
                 "sq $8,0(%1)\n\tsq $9,16(%1)\n\tsq $10,32(%1)\n\tsq $11,48(%1)\n\t"
                 "lw %0,44(%3)\n\taddu %0,%0,%2\n1:\n\t.set pop"
                 : "+r"(base) : "r"(destination), "r"(offset), "r"(saved), "r"(source)
                 : "$8", "$9", "$10", "$11", "memory");
    { register f32* target asm("$14") = (f32*)base;
      asm("" : "+r"(target)); target[1] = -target[1]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$15") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[5] = -target[5]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$14") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[9] = -target[9]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$15") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[13] = -target[13]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$14") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[2] = -target[2]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$15") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[6] = -target[6]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$14") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[10] = -target[10]; }
    asm volatile("" ::: "memory");
    { register f32* target asm("$15") = (f32*)(saved[11] + offset);
      asm("" : "+r"(target)); target[14] = -target[14]; }
}
