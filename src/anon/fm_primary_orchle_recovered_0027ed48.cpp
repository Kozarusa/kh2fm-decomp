#include "../common/types.h"
struct KeyedValue {
    s16 value;
    s16 key;
};
struct KeyedValueTable {
    KeyedValue entries[15];
};
extern "C" KeyedValueTable D_00374008;

s16 func_0027ed48(s32 key) {
    KeyedValueTable table = D_00374008;
    s16 result = -1;
    s32 index;
    for (index = 0; table.entries[index].key >= 0; index++) {
        if (table.entries[index].key == key) {
            result = table.entries[index].value;
            break;
        }
    }
    return result;
}
