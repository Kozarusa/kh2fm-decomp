#include "../common/types.h"
struct Config {
    u8 pad[2528];
    u32 mask;
};
struct Owner {
    Config* config;
};
struct Command {
    Owner* owner;
    u8 pad04[32];
    s32 limit;
    u8 pad28[40];
    s32 level;
};
struct Entry {
    u16 id;
};
struct Target {
    u32 handle;
};
extern "C" u32 func_00190140(...);
extern "C" u32 func_0019c4f8(...);
extern "C" u32 func_0019da68(...);
extern "C" u32 func_001b8e88(...);
extern "C" bool func_001b90f0(...);
extern "C" u32 func_001c11e0(...);

s32 func_0019dbc0(Command* command, u32 key, Target* target, s32 level, s32 limit) {
    if (level < command->level || (level == command->level && !(limit < command->limit))) {
        return 0;
    } else {
        Entry* entry = (Entry*)func_001b8e88(key);
        if (level != 201) {
            register Owner* owner asm("$14") = command->owner; // why: original loads the owner pointer into t6
            if (!func_001b90f0(entry, owner->config->mask)) {
                return 0;
            }
            if (entry->id == 30 || entry->id == 604) {
                if (func_001c11e0()) {
                    return 0;
                }
            }
            if (entry->id != 456) {
                s32 valid = 0;
                if (func_00190140(target)) {
                    valid = target->handle != 0;
                }
                if ((u8)valid && func_0019c4f8(target->handle)) {
                    return 0;
                }
            }
        }
        func_0019da68(command, entry, target, level, limit);
        return 1;
    }
}
