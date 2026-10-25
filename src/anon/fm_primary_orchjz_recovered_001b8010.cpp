#include "../common/types.h"
// why: GIF packet quadword viewed as a union; union member stores may alias any object, as the original's reloads show
union Pair {
    u64 dw[2];
    u8 b[16];
};
struct Builder {
    u8 pad0[8];
    // why: union view of the packet cursor; its stores may alias the argument reads, as the original store order shows
    union {
        Pair* cursor;
        u8* bytes;
    } current;
};

void func_001b8010(Builder* builder, s32 kind, ...) {
    // why: union view makes every argument-pointer access an aggregate reference that may alias the packet stores and the argument reads
    union {
        __builtin_va_list list;
        u8 bytes[4];
    } args;
    asm("" : "=m"(args.list)); // why: original keeps the argument pointer in its stack slot (lw/sw 0(sp) around every read)
    __builtin_stdarg_start(args.list, kind);
    Pair* start = builder->current.cursor;
    builder->current.cursor = start + 1;
    s64 value = __builtin_va_arg(args.list, s64);
    while (value != 0xffff) {
        builder->current.cursor->dw[0] = __builtin_va_arg(args.list, u64);
        builder->current.cursor->dw[1] = value;
        builder->current.cursor++;
        value = __builtin_va_arg(args.list, s64);
    }
    __builtin_va_end(args.list);
    // why: sign-extend kind to 64 bits, then shift unsigned (defined for any kind, same dsll)
    u64 tag = (s64)((builder->current.cursor - start) - 1) | ((u64)(s64)kind << 15) | (1ull << 60);
    start->dw[1] = 14;
    start->dw[0] = tag;
}
