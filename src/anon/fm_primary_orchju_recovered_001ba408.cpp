#include "../common/types.h"
struct GoalEvent {
    f32 timer;
    s32 id;
    u8 pad[8];
    s32 target;
};
struct EventWork {
    s32 words[8];
};
extern "C" f32 D_0036dbe8;
extern "C" f32 D_00349e10;
extern "C" void func_001ba340(GoalEvent*);
extern "C" u32 func_001a80c8(...);
extern "C" void func_001ba528(GoalEvent*, u32, u32);
extern "C" u32 func_001ba598(...);
extern "C" u32 func_00176b20(...);
extern "C" bool func_0019ba60(...);
extern "C" u16 func_0016a070(...);

s32 func_001ba408(GoalEvent* event) {
    // why: reproduces the original's unused 32-byte local (frame 80) and its sw zero,12(sp) in the bc1f delay slot; callee func_001ba340 has the same store
    EventWork work;
    work.words[3] = 0;
    f32* threshold = &D_0036dbe8;
    asm("" : "+r"(threshold)); // why: original forms the full address (lui+addiu) before the load
    if (*threshold <= event->timer) {
        func_001ba340(event);
    }
    f32 timer = event->timer - D_00349e10;
    event->timer = timer;
    if (timer <= 0.0f) {
        u8* entry = (u8*)func_001a80c8(event->id);
        if (event->target != 0) {
            func_001ba528(event, *(u16*)(entry + 6), event->target);
        } else {
            for (s32 index = 0; index < 3; index++) {
                u32 member = func_00176b20(index);
                if (func_0019ba60(member) && (*(u32*)(member + 0x588) & 0x400000) == 0) {
                    func_001ba528(event, *(u16*)(entry + 6), func_0016a070(member));
                }
            }
        }
        func_001ba598(event);
        return 0;
    }
    return 1;
}
