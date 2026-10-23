#include "../common/types.h"
typedef void (*VoiceFn)(void*, s32, s32);

// Preserve original registry aliases.
void func_00171810(s32* object) asm("_ZN2YS14trap_obj_voiceEP8BD_VALUE");

void func_00171810(s32* object) {
    s32* voice = *(s32**)((u8*)*(s32**)object + 4);
    VoiceFn fn = *(VoiceFn*)(*(u8**)voice + 84);
    fn(voice, object[1], object[2]);
}
