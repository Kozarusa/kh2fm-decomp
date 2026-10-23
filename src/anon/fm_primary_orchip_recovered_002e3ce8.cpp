// func_002e3ce8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
// func_002e3ce8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_01e2be20;
extern "C" kn::FVector* func_002cb8b8(u8* input);

void func_002e3ce8(u8** object) {
    u8* pointer = *(u8**)(*object + 4);
    if (pointer != 0) {
        u8* input = *(u8**)(pointer + 0x508);
        if (input != 0) {
            kn::FVector* result = func_002cb8b8(input);
            D_01e2be20 = *result;
            *object = (u8*)&D_01e2be20;
        }
    }
}
