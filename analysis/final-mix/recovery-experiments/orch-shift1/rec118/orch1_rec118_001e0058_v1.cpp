#include "../common/types.h"
extern "C" void func_002bc358(s32, s32);
extern "C" void func_001dee10(s32);
extern "C" void func_001de978(s32);

void func_001e0058(s32 object) {
    s32 handle = *(s32*)(object + 0x54);
    if (handle >= 0) {
        func_002bc358(handle, 0x78);
    }
    if (object == 0) {
        return;
    }
    func_001dee10(object);
    func_001de978(object);
}
