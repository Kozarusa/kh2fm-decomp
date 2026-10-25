#include "../common/types.h"
// why: single pointer argument in a0, as at the accepted call site in fm_primary_orcheh_recovered_00276b10.cpp, written without varargs
extern "C" u32 func_00139d78(u8*);
extern "C" void func_00276a18();
// Copied from the accepted definition fm_primary_orcheh_recovered_00276b10.cpp.
extern "C" u32 func_00276b10();
extern "C" u8* D_0035f604;
typedef void (*Callback)(u8*);

// why: the only exit is the tail call to 00276b10, whose accepted definition returns u32, so its result is returned

u32 func_002a8258() {
    s32 group = 0;
    do {
        s32 offset = group * 872;
        s32 count = 1;
        do {
            if (func_00139d78((u8*)(offset + (u32)D_0035f604))) {
                u8* object = (u8*)(offset + (u32)D_0035f604);
                Callback* table = *(Callback**)object;
                table[5](object);
            }
            count--;
            offset += 436;
        } while (count >= 0);
        group++;
    } while (group < 10);
    func_00276a18();
    return func_00276b10();
}
