#include "../common/types.h"
extern "C" u8 func_001bc2a8(u16*, u32, u32);

void func_001bc6a8(u8* object_in, u16* source, u32 arg2, u32 arg3, u32 flag) {
    register u8* object asm("$16") = object_in; // why: original keeps the object pointer in s0
    *(u16*)(object + 2) = *source;
    asm volatile("" : "+r"(object) : : "memory"); // why: keeps store order and transports the initialized s0 pointer to the byte store
    object[4] = flag;
    u8 result = func_001bc2a8(source, arg2, arg3);
    *(u32*)(object + 8) = arg3;
    object[5] = result;
    *(u16*)object = 0;
}
