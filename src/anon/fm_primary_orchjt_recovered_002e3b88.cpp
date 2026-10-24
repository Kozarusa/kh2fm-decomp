#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Quad { u32 words[4]; };
extern "C" kn::FVector D_01e2be20;
extern "C" Quad* func_002cb7c8(Quad* output,u64 second,u64 third);

void func_002e3b88(u8** object) {
    u8* pointer = *(u8**)(*object + 4);
    if (pointer != 0) {
        u8* input = *(u8**)(pointer + 0x508);
        if (input != 0) {
            kn::FVector result;
            func_002cb7c8((Quad*)&result, (u64)input, *(s32*)(object + 1));
            D_01e2be20 = result;
            *object = (u8*)&D_01e2be20;
        }
    }
}
