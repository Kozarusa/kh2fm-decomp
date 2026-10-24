#include "../common/types.h"
extern "C" f32 D_003758ac;
extern "C" u32* func_002cba88(f32, f32, u32*, u32*, u32*, u32*);

u32* func_002cbca0(u32* output, u32* record, u32* first, u32* second)
{
    register f32* fallback asm("$15") = &D_003758ac; // why: original forms the global address in t7 then lwc1 0(t7)
    asm("" : "+r"(fallback)); // why: keeps lui+addiu instead of folding the low half into lwc1
    register f32 factor asm("$f13") = *fallback; // why: original loads the factor straight into f13
    u32* base = record;
    asm("" : "+r"(base) : "f"(factor)); // why: orders the factor load before the record argument load, as the original
    func_002cba88(*(f32*)(base + 9), factor, output, base, first, second);
    *(f32*)(output + 3) = *(f32*)(record + 5);
    return output;
}
