#include "../common/types.h"
struct Item;
extern "C" s16* D_0035f200;
extern "C" s32* D_0035f600;
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_00276568(void);
extern "C" s32 func_0028afa8(s16* object);
extern "C" void func_0028afd0(Item* item, s32 value);

void func_002a7d10() {
    s32 index;
    if (func_00287bc0() == 36) {
        index = 0;
    } else {
        s32 count = *D_0035f600;
        s8 key = *(s8*)func_00276568();
        s32 scan = 0;
        if (count > 0) {
            s16* entry = (s16*)D_0035f600;
            do {
                if (key == entry[2] && entry[3] < 0) break;
                scan++;
                entry += 2;
            } while (scan < count);
        }
        index = scan;
        if (index >= func_0028afa8(D_0035f200)) {
            index = func_0028afa8(D_0035f200) - 1;
        }
    }
    func_0028afd0((Item*)D_0035f200, index);
}
