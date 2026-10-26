#include "../common/types.h"
// why: the outputs are word/halfword cells; with plain s32* the compiler loads both halves before the first store (measured, 4 words off)
union Cell { s32 word; s16 half[2]; };
struct Context { u8 pad[0x41a0]; s16 low; s16 high; };
extern "C" Context* func_001058e8();

void func_00242980(Cell* first, Cell* second)
{
    Context* context = func_001058e8();
    first->word = context->low;
    second->word = context->high;
}
