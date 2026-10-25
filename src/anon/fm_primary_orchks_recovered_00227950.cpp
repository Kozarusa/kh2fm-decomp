#include "../common/types.h"
extern "C" u8* D_0035dcf0;
extern "C" void func_002278e0(u8*);
extern "C" void func_001024a8(u32);

void func_00227950(u8* request) {
    s32 offset = 0;
    s32 count = 127;
    s32 key = *(s32*)(request + 4);
    do {
        u8* object = (u8*)(offset + (u32)D_0035dcf0);
        offset += 84;
        if (*(s32*)(object + 12) == key && *(s32*)(object + 0) == 1 && *(s32*)(object + 4) == 4 && *(u8*)(object + 8) == 0) {
            func_002278e0(object);
        }
        --count;
    } while (count >= 0);
    func_001024a8((u32)request);
}
