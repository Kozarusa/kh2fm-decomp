#include "../common/types.h"
extern "C" s32 D_00349e40;
extern "C" u8 D_00349e7c[];
extern "C" s32 WaitSema(s32);
extern "C" s32 SignalSema(s32);
extern "C" s32 ReferSemaStatus(s32, void*);

struct SemaStatus {
    s32 a;
    s32 b;
    s32 c;
    s32 waiting;
};

void func_0014d478() {
    SemaStatus status;
    u8* entry;
    u8* end;
    WaitSema(D_00349e40);
    entry = D_00349e7c;
    end = entry + 176;
    do {
        ReferSemaStatus(*(s32*)(entry + 24), &status);
        if (status.waiting != 0) {
            SignalSema(*(s32*)(entry + 24));
        }
        entry += 88;
    } while (entry < end);
}
