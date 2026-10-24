#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00257770(...);
extern "C" u32 func_0028acc8(u32);
extern "C" s32 D_0035f01c;
extern "C" s32 D_0035f020;
extern "C" s32 D_0035f024;

u32 func_00262e30(void) {
    s32 base;
    s32 cursor;
    s32 index;
    u32 result;

    base = func_00257770();
    result = func_00139d78(base);
    if (result == 0) {
        result = func_00139d78(base + 0x660);
        if (result == 0) {
            result = func_00139d78(base + 0xb350);
            if (result == 0) {
                result = func_0028acc8(D_0035f01c);
                if (result == 0) {
                    result = func_0028acc8(D_0035f020);
                    if (result == 0) {
                        result = func_0028acc8(D_0035f024);
                        if (result == 0) {
                            index = 0;
                            cursor = base;
                            do {
                                result = func_00139d78(cursor + 0xd30);
                                if (result != 0) {
                                    goto done;
                                }
                                result = func_00139d78(cursor + 0x5ef0);
                                if (result != 0) {
                                    goto done;
                                }
                                index = index + 1;
                                cursor = cursor + 0x1b4;
                            } while (index < 0x18);
                            result = func_00139d78(base + 0x330);
                        }
                    }
                }
            }
        }
    }
done:
    return result;
}
