#include "../common/types.h"
extern "C" u32 D_0035eb88;
extern "C" u32 D_0035eb8c;
extern "C" u8 D_0035eb84;

void func_0023edb0(u32 value) {
    u32 previous=D_0035eb88;
    if(previous!=value) {
        if(previous) D_0035eb8c=previous;
        D_0035eb88=value;
        return;
    }
    ++D_0035eb84;
}
