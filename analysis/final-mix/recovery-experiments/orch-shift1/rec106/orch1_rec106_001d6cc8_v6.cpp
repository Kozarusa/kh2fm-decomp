#include "../common/types.h"
struct Entry { u8 bytes[64]; };
struct Table { s32 pad0; s32 count; Entry entries[1]; };
extern "C" Table* D_01d5ba98;

Entry* func_001d6cc8(Entry* current) {
    if (current == 0) {
        return D_01d5ba98->entries;
    }
    Entry* next = current + 1;
    if (next >= D_01d5ba98->entries + D_01d5ba98->count) {
        next = 0;
    }
    return next;
}
