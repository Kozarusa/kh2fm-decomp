#include "../common/types.h"
extern "C" s32 D_01d49960;
extern "C" s32 D_01d49968;
extern "C" u8 D_0036e068[];
// why: declaration copied from accepted caller fm_primary_addresspair_recovered_001a6c60.cpp
extern "C" u32 func_001050d8(u64);
// why: declaration copied from accepted callers that read the returned chara data pointer
extern "C" u8* func_0016e920(u32);
// why: types copied from the accepted definition in tiny_auto80_queue.cpp; extern "C" so the isolated probe links the plain symbol
extern "C" void func_00188120(u32 a0, u32 a1);
// why: no accepted declaration; types derived from a0, a1, a2 and f12 set before the jal
extern "C" void func_001c7fb8(u8*, u8*, u32, f32);
// why: types copied from the accepted declaration in auto80_199_queue_decls.hpp; extern "C" so the isolated probe links the plain symbol
extern "C" u32 func_001d6d88(u32);

u8* func_001c88a8(u32 value, f32 scale) {
    u8* summon = (u8*)func_001d6d88(value);
    if (D_01d49960 != 0) {
        return 0;
    }
    D_01d49968 = 2;
    u8* object = (u8*)func_001050d8(0xd00);
    u8* data = func_0016e920(*(u32*)(summon + 4));
    func_001c7fb8(object, data, value, scale);
    func_00188120((u32)(object + 0x300), (u32)D_0036e068);
    return object;
}
