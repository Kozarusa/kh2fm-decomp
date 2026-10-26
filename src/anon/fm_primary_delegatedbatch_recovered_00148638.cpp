#include "../common/types.h"
struct Thresholds { u8 pad0[0x38]; f32 last; f32 middle; f32 next; f32 top; };
struct Object { u8 pad0[0x10d]; u8 state; u8 pad1[6]; Thresholds* thresholds; };

void func_00148638(f32 value,u64 unused,Object* object)
{
    Thresholds* base = object->thresholds;
    u8 previous = object->state;
    f32 last = base->last;
    f32 middle = base->middle;
    f32 next = base->next;
    u8 result;
    if (base->top < value) result = 2;
    else if (next < value) result = previous;
    else if (middle < value) result = 1;
    else if (last < value) result = previous;
    else result = 0;
    object->state = result;
}
