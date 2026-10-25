#include "../common/types.h"

struct Party {
    u8 pad0[2896];
    s32 state;
};

struct Object {
    u8 pad0[2528];
    Party* party;
};

extern "C" u8 D_0032bae0;
extern "C" u32 func_001818a0();
extern "C" s32 func_00177870(Party*);
extern "C" s32 func_001bc780(s32,u64,s32,u64);

s32 func_001be540(Object* object, s32 queue) {
    if (func_001818a0() == 0) {
        return func_001bc780(queue, 104, 0, 1);
    }
    if (D_0032bae0 == 9) {
        return func_001bc780(queue, 136, 0, 1);
    }
    Party* party = object->party;
    if (party->state == 2) {
        return func_001bc780(queue, 365, 0, 1);
    }
    if (func_00177870(party) != 0) {
        return func_001bc780(queue, 541, 0, 1);
    }
    return func_001bc780(queue, 1, 0, 1);
}
