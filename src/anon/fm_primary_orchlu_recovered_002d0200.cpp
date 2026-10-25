#include "../common/types.h"
struct Entry {
    s32 id;
    u8 kind;
    u8 subtype;
};

bool func_002d0200(Entry* entry) {
    if (entry->kind != 16) {
        return true;
    }
    if (entry->id == 1566) {
        return false;
    }
    switch (entry->subtype) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 15:
    case 16:
    case 17:
    case 25:
    case 27:
    case 200:
    case 201:
        return true;
    default:
        return false;
    }
}
