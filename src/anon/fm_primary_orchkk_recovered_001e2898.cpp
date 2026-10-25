#include "../common/types.h"
extern "C" u32 func_001e18d8(...);

// why: element type with a user-declared (empty) destructor, so the compiler emits the original's null-checked reverse member-array destruction loops
struct Element {
    u8 data[16];
    ~Element() {}
};

struct Holder {
    Element first[10];
    Element second[10];
    Element third[200];
    // why: the original runs func_001e18d8 first and then destroys the member arrays in reverse order, which is exactly an inline destructor body followed by member destruction
    ~Holder() { func_001e18d8(this); }
};

// why: void per DEVIATIONS #36: the single exit leaves func_001e18d8's leftover v0, which is the entry v0 when every field is null (entry), the result of a store-only kill chain (stale-b) or the indirect result of the last Free (direct); no float result

void func_001e2898(Holder* holder) {
    holder->~Holder();
}
