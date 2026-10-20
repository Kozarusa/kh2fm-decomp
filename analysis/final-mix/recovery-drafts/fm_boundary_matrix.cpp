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
    if (destination != source) {
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1);"
                     "sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(destination), "r"(source) : "$8", "$9", "$10", "$11", "memory");
        base = saved[11];
    }
    asm("" : "+r"(base));
    { register f32* target asm("$14") = (f32*)(base + offset);
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
