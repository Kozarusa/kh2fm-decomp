#include "../common/types.h"
typedef s32 (*Handler)(u8*, u8*);
extern "C" f32 D_0036db48;
extern "C" const void* D_0036db4c[9];
extern "C" void func_00102470(float value, void* object);
extern "C" s32 func_001991a8(s32, s32);
extern "C" u64 func_0014aba8();
extern "C" void func_0014aa58(u64,s32,s32);
extern "C" void func_0014aa80(u64,s32,s32);

s32 func_001b8520(u8* command, u8* context) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036db4c
    static const void* targets[9] asm("fm_switch_table_001b8520") = {
        &&fallback, &&fallback, &&setValue, &&clear, &&none,
        &&fadeOutNow, &&fadeInNow, &&fadeOutWait, &&fadeInWait};
    u32 index = *(u16*)command;
    if (index >= 9) goto fallback;
    goto *D_0036db4c[index];
setValue:
    func_00102470(*(f32*)(command + 4), *(void**)(context + 16));
    return 1;
fallback:
    return (*(Handler*)(context + 12))(command, context);
clear:
    func_001991a8(*(s32*)(command + 4), 0);
    return 1;
none:
    return 0;
fadeOutNow: {
    f32* scale = &D_0036db48;
    asm("" : "+r"(scale)); // why: the original materializes the scale address before loading it
    register f32 coefficient asm("$f1") = *scale; // why: the original loads the scale into $f1, pattern from accepted 0016df28
    s32 amount = (s32)(*(f32*)(command + 4) * coefficient);
    u64 receiver = func_0014aba8();
    func_0014aa58(receiver, amount, 0);
    return 1;
}
fadeInNow: {
    f32* scale = &D_0036db48;
    asm("" : "+r"(scale)); // why: the original materializes the scale address before loading it
    register f32 coefficient asm("$f1") = *scale; // why: the original loads the scale into $f1, pattern from accepted 0016df28
    s32 amount = (s32)(*(f32*)(command + 4) * coefficient);
    u64 receiver = func_0014aba8();
    func_0014aa80(receiver, amount, 0);
    return 1;
}
fadeOutWait: {
    f32* scale = &D_0036db48;
    asm("" : "+r"(scale)); // why: the original materializes the scale address before loading it
    register f32 coefficient asm("$f1") = *scale; // why: the original loads the scale into $f1, pattern from accepted 0016df28
    s32 amount = (s32)(*(f32*)(command + 4) * coefficient);
    u64 receiver = func_0014aba8();
    func_0014aa58(receiver, amount, 1);
    return 1;
}
fadeInWait: {
    f32* scale = &D_0036db48;
    asm("" : "+r"(scale)); // why: the original materializes the scale address before loading it
    register f32 coefficient asm("$f1") = *scale; // why: the original loads the scale into $f1, pattern from accepted 0016df28
    s32 amount = (s32)(*(f32*)(command + 4) * coefficient);
    u64 receiver = func_0014aba8();
    func_0014aa80(receiver, amount, 1);
    return 1;
}
}
