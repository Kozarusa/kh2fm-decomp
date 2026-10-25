#include "../common/types.h"
// why: accepted C++ declaration is u32 YS::PARTY::get_partram() (yasui/libys/party.hpp, this in a0); C linkage for the probe link
extern "C" u32 func_00177850(s32);
extern "C" u32 func_001a80c8(...);                 // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" u32 func_001bc778(...);                 // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" s32 func_001bc780(s32, u64, s32, u64);  // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" void func_001bce00(u8*);                // no accepted declaration: a0 is the menu; it and its tail callees never write v0

// Return contract (DEVIATIONS #36): the only exit is the tail call into func_001bce00, which writes
// neither v0 nor $f0 (stale-b), so void.

void func_001be9a0(u8* object) {
    u8* menu = object + 268;
    s32 index = 0;
    func_001bc778(menu);
    u8* party = (u8*)func_00177850(*(s32*)(object + 2528));
    if (party[18] != 0) {
        s32 size = 12; // why: entry stride kept in a preheader local; the original loads 12 into s4 before 6 into s5
        u8 mark = 6;   // why: stored mark kept in a preheader local; the original holds 6 in s5 across the loop
        do {
            u32 id = *(u16*)(party + index * 2 + 68);
            if (id == 0) {
                id = *(u16*)(party + index * 2 + 52);
                if (id == 0) {
                    goto next;
                }
            }
            {
                u8* info = (u8*)func_001a80c8(id);
                s32 entry;
                for (entry = 0; entry < *(s32*)(menu + 8); entry++) {
                    if (*(u16*)(menu + entry * 12 + 14) == *(u16*)(info + 16)) {
                        if (*(u16*)(party + index * 2 + 52) != 0) {
                            menu[entry * 12 + 16]++;
                        }
                        break;
                    }
                }
                if (entry >= *(s32*)(menu + 8)) {
                    func_001bc780((s32)menu, *(u16*)(info + 16), 0, 1);
                    if (*(u16*)(party + index * 2 + 52) == 0) {
                        // why: integer address sum, the original adds the menu after the scaled count (addu t,t,s1)
                        ((u8*)(*(s32*)(menu + 8) * size + (s32)menu))[4] = 0;
                        ((u8*)(*(s32*)(menu + 8) * size + (s32)menu))[5] = mark;
                    }
                }
            }
        next:
            index++;
        } while (index < party[18]);
    }
    func_001bce00(menu);
}
