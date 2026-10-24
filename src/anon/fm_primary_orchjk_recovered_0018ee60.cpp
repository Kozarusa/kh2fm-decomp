#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef void (*Method)(...);
extern "C" u32 func_001050d8(u64);
extern "C" u64 func_0018d238(...);
extern "C" u32 func_0018da18(u32, u32, u32, u32);
extern "C" u32 func_0018db38(u32, u32, u32, u32);
extern "C" u32 func_0018ca10(u32);
extern "C" u64 func_0018f028(...);

u32 func_0018ee60(u32 first, u32 second, u8* owner, kn::FVector* source, u8 mode) {
    u32 flag = 0;
    u8* work = (u8*)func_001050d8(208);
    func_0018d238(work, first, 0, second, 0, -1, -1);
    u8* result;
    if (mode != 0) {
        result = (u8*)func_0018da18((u32)work, (u32)owner, *(u32*)(work + 40), 0);
    } else {
        result = (u8*)func_0018db38((u32)work, (u32)owner, 0, 0);
    }
    if (result != 0) {
        flag = (*(u32*)(result + 24) & 1) ^ 1;
        *(kn::FVector*)result = *source;
        (*(Method*)(*(u8**)owner + 100))(owner, result);
        func_0018ca10((u32)result);
    }
    func_0018f028(work);
    return flag;
}
