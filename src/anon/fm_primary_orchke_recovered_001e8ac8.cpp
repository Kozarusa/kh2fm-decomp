#include "../common/types.h"
struct Manager {
    u8 pad0[0x58];
    s32 limit;
    u8 pad1[0x0c];
    s32 count;
    u8 pad2[0x14];
    u8* table;
};

extern "C" u8 D_0036ef58[];
extern "C" u8 D_0036efb8[];
extern "C" u8 D_0036ef98[];
extern "C" u8 D_0036ef88[];
extern "C" u32 func_002fdfc8(...);
extern "C" u8* func_001e7a98(Manager*, u8*);

void func_001e8ac8(Manager* manager) {
    s32 index = 0;
    if (index < manager->count) {
        do {
            u8* entry = manager->table + index * 16;
            if (entry == 0) {
                // why: string addresses are materialized in this order (original s7, s6, s5, s4 assignment)
                u8* expression = D_0036efb8;
                u8* file = D_0036ef88;
                u8* message = D_0036ef58;
                u8* format = D_0036ef98;
                func_002fdfc8(message, expression);
                func_002fdfc8(format, file, 964);
                asm volatile("break 0"); // why: original traps with break, __builtin_trap emits teq
            }
            if (manager->limit >= *(s32*)(entry + 8)) {
                *(s32*)(entry + 8) = 0x7fffffff;
                u8* result = func_001e7a98(manager, entry);
                *(u8**)(entry + 4) = result;
                result[0x9c] = 0;
            }
            index++;
        } while (index < manager->count);
    }
}
