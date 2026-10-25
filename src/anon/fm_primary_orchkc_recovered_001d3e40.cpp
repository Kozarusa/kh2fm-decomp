#include "../common/types.h"
// why: types of the accepted definition u32 func_001d3f98(u32) in fm_primary_workerbacklog_recovered_001d3f98.cpp, with C linkage for the probe link
extern "C" u32 func_001d3f98(u32);
extern "C" s32 func_00170978(char*);
extern "C" bool func_001a9758(...);
extern "C" u32 func_0017df58(s32);
extern "C" bool func_0019ba60(...);
extern "C" u64 func_0017e280(...);
extern "C" s32 func_00176b58(...);
extern "C" bool func_0017e310(...);

s32 func_001d3e40(u8* object) {
    if (func_00170978((char*)func_001d3f98((u32)object)) != 2) {
        return 0;
    }
    if (*(u32*)(object + 36) != 0) {
        if (!func_001a9758(*(u32*)(object + 36), 0)) {
            return 0;
        }
    }
    s32 index = 0;
    do {
        u32 member = func_0017df58(index);
        index++;
        if (func_0019ba60(member)) {
            if (func_0017e280(member) == 0) {
                return 0;
            }
        }
    } while (index < 2);
    s32 slot = 0;
    do {
        register u8* cursor asm("$14") = object + slot; // why: original forms the slot address in t6
        u8 id = cursor[1];
        slot++;
        if (id != 0) {
            u8* entry = (u8*)func_00176b58(id);
            if (*(u32*)(entry + 1416) & 0x4000) {
                if (!func_0017e310(entry)) {
                    return 0;
                }
            }
        }
    } while (slot < 3);
    return 1;
}
