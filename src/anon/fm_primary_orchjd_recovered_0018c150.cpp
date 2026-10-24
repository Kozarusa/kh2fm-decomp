#include "../common/types.h"
#include "../kn/fvector.hpp"
struct ActionHead {
    s32 type;
    u32 second;
    u32 third;
    u32 fourth;
};
struct ActionState {
    ActionHead head;
    kn::FVector first_vector;
    u32 value;
    u8 flag;
    f32 rate;
    f32 scale;
    u8 mode;
    u8 step;
    kn::FVector second_vector;
    f32 timer;
};
extern "C" u32 func_0018c438(...);
extern "C" u32 func_0018c480(s32, u8);

u32 func_0018c150(u8* object) {
    ActionState* current = (ActionState*)(object + 0xa40);
    *(ActionState*)(object + 0xaa0) = *current;
    func_0018c480((s32)current, 0);
    u32 result = func_0018c438(current);
    f32 value;
    if (current->head.type != 4) {
        if (current->head.type != 5) {
            value = *(f32*)(object + 0xb30);
        } else {
            value = *(f32*)(object + 0xb24);
        }
    } else {
        value = *(f32*)(object + 0xb18);
    }
    *(f32*)(object + 0xb00) = value;
    return result;
}
