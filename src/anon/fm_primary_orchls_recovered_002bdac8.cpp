#include "../common/types.h"
extern "C" u32 D_003617fc;
extern "C" u8 D_003637e0[];
// why: accepted definition is worldmap::Libretto::leaveAllObj (void member, this in a0);
// the probe source may include only types.h, so it is declared with the object pointer as its argument
extern "C" void func_002be148(u8*);
// why: copied from the recovered call site fm_primary_orchbk_recovered_001922c8.cpp
extern "C" void func_00170950(s32);
// why: no recovered declaration; a0 is the word at object+4, result unused
extern "C" void func_001b86e0(s32);
// why: accepted definition fm_primary_orchiu_recovered_00170320.cpp is void(s32)
extern "C" void func_00170320(s32);

void func_002bdac8(u8* object) {
    func_002be148(object);
    u8* node = *(u8**)(object + 0x10);
    if (node != 0) {
        do {
            u8* next = *(u8**)(node + 0x20);
            if (node != 0) {
                (*(void (**)(u8*))(*(u8**)node + 4))(node);
            }
            node = next;
        } while (node != 0);
    }
    if (*(s32*)(object + 0x68) != 0) {
        func_00170950(*(s32*)(object + 0x68));
    }
    func_001b86e0(*(s32*)(object + 4));
    func_00170320(-200);
    D_003617fc = 0;
    *(u32*)(object + 8) = (u32)D_003637e0;
}
