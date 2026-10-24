#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_0031e208(s32 unused, u8* object, u32* flags, u32 value, Quad* source) {
    // why: original preserves the source pointer in t5 across object advancement
    register Quad* sourceCopy asm("$13") = source;
    if ((*reinterpret_cast<u64*>(object + 112) & 0x78) != 0) {
        return;
    }
    u32 flag = *flags;
    if ((flag & 0x800) != 0) {
        *reinterpret_cast<u16*>(object + 98) = value;
        Quad* destination = reinterpret_cast<Quad*>(object + 64);
        if (destination != sourceCopy) {
            asm("" : "+r"(destination)); // why: original stores through the compared t7 pointer instead of folding 64 into the store
            asm("" : "+r"(sourceCopy)); // why: original loads the first quad through the t5 copy, not the t0 parameter
            register Quad copied asm("$8") = *sourceCopy; // why: original loads quad into t0
            *destination = copied;
        }
        flag = *reinterpret_cast<volatile u32*>(flags);
    }
    if ((flag & 0x1000) != 0) {
        *reinterpret_cast<u16*>(object + 100) = value;
        object += 80;
        if (reinterpret_cast<Quad*>(object) != sourceCopy) {
            register Quad copied asm("$8") = *sourceCopy; // why: original loads quad into t0
            *reinterpret_cast<Quad*>(object) = copied;
        }
    }
}
