#include "../common/types.h"
struct Info;
struct Event {
    u16 kind;
    u16 pad2;
    union {
        u32 word;
        f32 real;
    } first;
    u32 second;
    u32 third;
    u16 count;
};
extern "C" s32 D_0034e948;
extern "C" const void* D_0036dc0c[14];
extern "C" bool func_0019ba60(s32); // copied from accepted caller fm_primary_orchcw_recovered_001dbcd0.cpp
extern "C" void func_001a1aa0(u8*, s32); // copied from accepted caller fm_primary_orchjk_recovered_001c0690.cpp
// why (each line below): the only accepted form is a C++ definition; its exact types are kept and
// C linkage is added because the probe link script defines only plain func_<address> symbols
extern "C" void func_001d4dc0(u32*, u32, u32, u32); // why: types of fm_primary_queuethetaprime_recovered_001d4dc0.cpp, C linkage for the probe link
extern "C" u32 func_001d5370(void*, u64, s32); // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" u32 func_001d5470(s32*, u64, Info*); // why: types of fm_primary_orchkc_recovered_001d5470.cpp, C linkage for the probe link
extern "C" u32 func_001d8248(u32, u32); // why: types of tiny_auto80_solver.cpp definition, C linkage for the probe link
extern "C" u32 func_001d8550(u32, u32); // why: types of tiny_auto80_solver.cpp definition, C linkage for the probe link
extern "C" void func_001d8b68(u32, u32); // why: types of auto80_199_queue.cpp definition, C linkage for the probe link
extern "C" u32 func_001d9028(u32, u32, u32, u32); // why: types of tiny_auto80_fptr4.cpp definition, C linkage for the probe link
extern "C" u32 func_001d93f0(u32, u32); // why: types of tiny_auto80_solver.cpp definition, C linkage for the probe link

// why: third and fourth are only forwarded: the original never writes a2/a3 and leaves them
// for func_001d9028, whose accepted definition takes four words

s32 func_001bb2c8(Event* event, u8* object, u32 third, u32 fourth) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036dc0c
    static const void* targets[14] asm("fm_switch_table_001bb2c8") = {
        &&done, &&slot_4c, &&slot_68, &&slot_a0, &&mode_8248, &&mode_8550, &&mode_8b68,
        &&mode_9028, &&counter, &&mode_93f0, &&store_word, &&store_real, &&target, &&slot_84};
    s32* slot;
    u64 owner;
    u32 kind = event->kind;
    if (kind >= 14) goto done;
    goto *D_0036dc0c[kind];
slot_4c:
    owner = *(s32*)(object + 72);
    slot = (s32*)(object + 76);
shared:
    func_001d5470(slot, owner, (Info*)event);
done:
    return 1;
slot_68:
    owner = *(s32*)(object + 72);
    slot = (s32*)(object + 104);
    goto shared;
slot_a0:
    owner = *(s32*)(object + 72);
    slot = (s32*)(object + 160);
    goto shared;
mode_8248:
    func_001d8248((u32)object, (u32)event);
    return 1;
mode_8550:
    func_001d8550((u32)object, (u32)event);
    return 1;
mode_8b68:
    func_001d8b68((u32)object, (u32)event);
    return 1;
mode_9028:
    func_001d9028((u32)object, (u32)event, third, fourth);
    return 1;
counter: {
    // why: computing the gauge address before the first call keeps it in s0 as the original does
    u32* gauge = (u32*)(object + 740);
    func_001d5370(object + 744, *(s32*)(object + 72), event->count - 1);
    func_001d4dc0(gauge, event->first.word, event->second, event->third);
    return 1;
}
mode_93f0:
    func_001d93f0((u32)object, (u32)event);
    return 1;
store_word:
    *(u32*)(object + 1324) = event->first.word;
    return 1;
store_real:
    *(f32*)(object + 1328) = event->first.real;
    return 1;
target: {
    s32 global = D_0034e948;
    func_0019ba60(global);
    u8* owner = *(u8**)(global + 1164);
    if (owner[431] == 1) {
        func_001a1aa0(owner, event->first.word);
    }
    return 1;
}
slot_84:
    owner = *(s32*)(object + 72);
    slot = (s32*)(object + 132);
    goto shared;
}
