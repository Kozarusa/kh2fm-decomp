#include "../common/types.h"

void func_0031bae0(void* target, const void* source) {
    // why: a plain Quad copy fails (s2-rec13 v1-v4, 10 words: reordered lq/sq, sq in the jr delay slot); copy primitive from accepted func_0011b6a8, noreorder keeps the last sq out of the delay slot
    asm volatile(".set push; .set noreorder; lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1);"
                 "sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0); .set pop;"
                 :: "r"(target), "r"(source) : "$8", "$9", "$10", "$11", "memory");
}
