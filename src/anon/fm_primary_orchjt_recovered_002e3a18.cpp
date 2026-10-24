#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_01e2be20;
extern "C" u32 func_002cbed8(...);

void func_002e3a18(u8** object) {
    u8* pointer = *(u8**)(*object + 4);
    if (pointer != 0) {
        u8* input = *(u8**)(pointer + 0x508);
        if (input != 0) {
            kn::FVector result;
            func_002cbed8(&result, input);
            D_01e2be20 = result;
            *object = (u8*)&D_01e2be20;
        }
    }
}
