#include "../common/types.h"
extern "C" int func_00132f98(...);

s32 func_00133078(u8* object, s32* pairs, s32 unused, u32 count, s32 flag) {
    s32 buffer[8];
    s32* out = pairs + count * 2;
    u32 index = 0;
    s32 total = 0;
    if (count != 0) {
        s32* cursor = pairs;
        do {
            s32 found = func_00132f98(object, index, buffer, 8, flag);
            cursor[0] = found;
            cursor[1] = (count * 2 + total) * 4;
            total += found;
            if (found > 0) {
                s32* pointer = buffer;
                do {
                    found--;
                    *out = *pointer;
                    pointer++;
                    out++;
                } while (found != 0);
            }
            index++;
            cursor += 2;
        } while (index < count);
    }
    return total;
}
