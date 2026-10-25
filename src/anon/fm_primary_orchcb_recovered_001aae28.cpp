#include "../common/types.h"

struct Record {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
    u32 i;
    u32 j;
};

void func_001aae28(Record* record, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j) {
    record->a = a;
    record->b = b;
    record->c = c;
    record->d = d;
    record->e = e;
    record->f = f;
    record->g = g;
    record->h = h;
    record->i = i;
    record->j = j;
}
