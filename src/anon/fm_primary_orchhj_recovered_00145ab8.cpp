#include "../common/types.h"
typedef void (*Method)(u8*);
extern "C" u8 D_0034c6e0[];
extern "C" u8 D_00349dc0[];
extern "C" u8 D_00348d58[];
extern "C" u32 func_0031bab8(u8*);
extern "C" u32 func_0031baa8(u8*);
extern "C" void func_001070e8(u8*);
extern "C" void func_00106ac8(u8*);

void func_00145ab8(u8* object) {
    u8* entry;
    u8* group;
    u8* base;
    u8* item;
    if (object + 3168 == 0) goto first_done;
    entry = object + 17248;
first_loop:
    if (object + 3168 == entry) goto first_done;
    entry -= 880;
    (*(Method**)entry)[0](entry);
    goto first_loop;
first_done:
    *(u8**)(object + 1936) = D_0034c6e0;
    func_0031bab8(object + 2352);
    *(u8**)(object + 2080) = D_00349dc0;
    func_0031baa8(object + 2080);
    *(u8**)(object + 1936) = D_00348d58;
    if (object + 624 == 0) goto second_done;
    group = object + 1904;
second_loop:
    if (object + 624 == group) goto second_done;
    base = group - 80;
    group = base;
    if (base == 0) goto second_loop;
    item = base + 80;
inner_loop:
    if (base == item) goto second_loop;
    item -= 16;
    goto inner_loop;
second_done:
    func_001070e8(object + 288);
    func_00106ac8(object + 32);
    asm volatile("" ::: "memory"); // why: original calls with jal and returns itself instead of a tail jump
}
