#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Block {
    Quad row[4];
};
extern "C" u32 func_002d0bd8(...);

void func_002dc140(u8* object, Block* source) {
    Block* saved = (Block*)(object + 2912);
    Block* current = (Block*)(object + 2848);
    if (saved != current) {
        // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8; plain Quad and struct copies interleave (v1, v2)
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(saved), "r"(current) : "$8", "$9", "$10", "$11", "memory");
    }
    if (current != source) {
        // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8; plain Quad and struct copies interleave (v1, v2)
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(current), "r"(source) : "$8", "$9", "$10", "$11", "memory");
    }
    func_002d0bd8(object, source);
}
