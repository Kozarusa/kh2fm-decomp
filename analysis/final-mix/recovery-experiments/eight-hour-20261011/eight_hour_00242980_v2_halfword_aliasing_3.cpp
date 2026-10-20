#include "../common/types.h"
union WordHalfCell { s32 word; s16 halves[2]; };
extern "C" WordHalfCell* func_001058e8();
void func_00242980(WordHalfCell* first,WordHalfCell* second)
{
 WordHalfCell* context=func_001058e8();
 ((volatile WordHalfCell*)first)->word=context[0x1068].halves[0];
 ((volatile WordHalfCell*)second)->word=context[0x1068].halves[1];
}
