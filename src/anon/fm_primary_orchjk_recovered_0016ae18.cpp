#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0016adc8(u8*, Quad*);
extern "C" u32 func_0016aeb8(u8*, f32);

u32 func_0016ae18(u8* object) {
    Quad* source = (Quad*)(object + 0x890);
    asm volatile("" : "+r"(source)); // why: keeps the address add separate from the lq offset and orders it after the parameter copy
    register Quad value asm("$8") = *source; // why: original moves the quad through t0
    Quad copy = value;
    asm volatile("" ::: "memory"); // why: keeps store order, sq before the argument setup
    func_0016adc8(object, &copy);
    return func_0016aeb8(object, *(f32*)(object + 0x89c));
}
