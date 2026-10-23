#include "../common/types.h"
extern "C" s32 D_003a84d0[];

// Preserve original registry aliases.
s32 func_00109450(s32 start, s32 count, s32 value) asm("_Z16wtarget_00109450jjjj");

s32 func_00109450(s32 start, s32 count, s32 value) {
    s32 result = 1;
    if (value == 0) {
        start = 0;
        s32* pointer = D_003a84d0;
        do {
            *pointer = 0;
            start++;
            pointer++;
        } while (start < 512);
    } else {
        s32 end = start + count;
        if (start < end && start < 512) {
            s32* pointer = &D_003a84d0[start];
            s32 current = *pointer;
            while (1) {
                if (current != value) {
                    *pointer = value;
                    result = 0;
                }
                start++;
                pointer++;
                if (start >= end) break;
                if (start >= 512) break;
                current = *pointer;
            }
        }
    }
    return result;
}
