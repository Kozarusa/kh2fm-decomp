#include "../common/types.h"
extern "C" s32 D_00349e40;
extern "C" u8 D_00349e7c[];
extern "C" s32 func_00305660(s32);
extern "C" s32 func_00305640(s32);
extern "C" s32 func_00305690(s32, void*);

struct SemaStatus {
    s32 a;
    s32 b;
    s32 c;
    s32 waiting;
    s32 e;
    s32 f;
    s32 g;
    s32 h;
};

void func_0014d478() {
    SemaStatus status;
    s32 entry;
    s32 end;
    func_00305660(D_00349e40);
    entry = (s32)D_00349e7c;
    end = entry + 176;
    do {
        func_00305690(*(s32*)(entry + 24), &status);
        if (status.waiting != 0) {
            func_00305640(*(s32*)(entry + 24));
        }
        entry += 88;
    } while (entry < end);
}
