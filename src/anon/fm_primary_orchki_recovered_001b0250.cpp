#include "../common/types.h"
struct SoundObject;
typedef s32 (*SoundMethod)(SoundObject*, s32, s32);
struct SoundObject {
    SoundMethod* vtable;
    s32 unknown4;
    s32 index;
    s32 unknownc;
    s32 sound;
    s32 unknown14;
    s32 entry;
};
extern "C" s32 func_0016c028(s32);
extern "C" bool func_0019ba60(u64);
extern "C" u64 func_001b0320(...);
extern "C" void func_001b0330(u32*);
extern "C" void func_002bc398(u32, u32);  // accepted definition fm_width_recovered_15.cpp (void); why: extern "C" because the C++ declaration fails the isolated probe link
extern "C" u64 func_002bc420(...);

void func_001b0250(SoundObject* object) {
    s32 index = object->index;
    if (index >= 0) {
        func_001b0330((u32*)object);
        object->sound = object->vtable[2](object, index, func_0016c028(object->entry));
        return;
    }
    if (func_001b0320(object) == 0) {
        return;
    }
    if (func_002bc420(object->sound) != 0) {
        s32 entry = object->entry;
        if (entry != 0 && func_0019ba60(entry)) {
            s32 value = func_0016c028(object->entry);
            func_002bc398(object->sound, value);
            return;
        }
        object->entry = 0;
    } else {
        object->sound = 0;
        object->entry = 0;
    }
}
