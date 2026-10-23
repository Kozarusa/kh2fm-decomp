#include "../common/types.h"

extern const void* D_0036ead0[5];
extern const void* D_0036eae4[5];

// Preserve original-address references and emit separate compiler-generated
// label tables for independent data verification.
void func_001e34e0(u8* object, u32 index) {
    static const void* targets[5] asm("fm_switch_table_001e34e0") = {&&case0, &&case1, &&case2, &&case3, &&case4};

    u8 value;
    if (index >= 5) goto fallback;
    goto *D_0036ead0[index];
case0: value = 1; goto done;
case1: value = 3; goto done;
case2: value = 5; goto done;
case3: value = 7; goto done;
case4: value = 9; goto done;
fallback: value = 11;
done:
    object[0xa8] = value;
}
void func_001e3538(u8* object, u32 index) {
    static const void* targets[5] asm("fm_switch_table_001e3538") = {&&case0, &&case1, &&case2, &&case3, &&case4};

    u8 value;
    if (index >= 5) goto fallback;
    goto *D_0036eae4[index];
case0: value = 2; goto done;
case1: value = 4; goto done;
case2: value = 6; goto done;
case3: value = 8; goto done;
case4: value = 10; goto done;
fallback: value = 12;
done:
    object[0xa8] = value;
}
