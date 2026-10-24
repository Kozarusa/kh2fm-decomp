#include "../common/types.h"
#include "../kn/fvector.hpp"

struct Entry {
    s32 data;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x1c - 0x10];
    u8 kind;
    u8 type;
    u16 id;
    u8 pad20[0x2a - 0x20];
    u16 delay;
    u8 pad2c[0x2e - 0x2c];
    u16 scale;
    u8 level;
    u8 pad31[0x40 - 0x31];
};

struct Table {
    u8 pad0[4];
    u16 count;
    u8 pad6[0x2c - 6];
    Entry entries[1];
};

struct Unit {
    u8 pad0[8];
    Table* table;
    u8 padc[0x14 - 0xc];
    f32 timer;
    u8 pad18[0x20 - 0x18];
    u8 level;
};

union VectorPun {
    u32 words[4];
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } f;
};

extern "C" u8 D_0034f250[];
extern "C" s32 func_0016b7a0(s32);
extern "C" u32 func_00195700(u8*, s32);
extern "C" kn::FVector func_0019afd8(s32);
extern "C" kn::FVector func_0019b0e8(f32, f32, s32, kn::FVector*);
extern "C" s32 func_00199890(Entry*, Unit*, kn::FVector*);
extern "C" s32 func_00199938(Entry*, Unit*);
extern "C" s32 func_0019ac80(Unit*);

void func_0019a808(Unit* unit) {
    for (;;) {
        for (s32 index = 0; index < unit->table->count; index++) {
            if (unit->timer > 0.0f) {
                return;
            }
            u8 kind = unit->table->entries[index].kind;
            u16 id = unit->table->entries[index].id;
            if (kind == 2) {
                if (func_0016b7a0(id) == 0 && func_00195700(D_0034f250, id) == 0) {
                    if (unit->table->entries[index].level <= unit->level) {
                        kn::FVector vector;
                        s32 result;
                        switch (unit->table->entries[index].type) {
                        case 1:
                            vector = func_0019afd8(unit->table->entries[index].data);
                            result = func_00199890(&unit->table->entries[index], unit, &vector);
                            break;
                        case 2:
                            ((VectorPun*)&vector)->f.x = unit->table->entries[index].x;
                            ((VectorPun*)&vector)->f.y = unit->table->entries[index].y;
                            ((VectorPun*)&vector)->f.z = unit->table->entries[index].z;
                            vector = func_0019b0e8((f32)unit->table->entries[index].scale, 0.0f, unit->table->entries[index].data, &vector);
                            result = func_00199890(&unit->table->entries[index], unit, &vector);
                            break;
                        case 0:
                        default:
                            result = func_00199938(&unit->table->entries[index], unit);
                            break;
                        }
                        if (result != 0) {
                            unit->timer = (f32)unit->table->entries[index].delay;
                        }
                    }
                }
            }
        }
        if (unit->timer <= 0.0f) {
            if (func_0019ac80(unit) == 0) {
                return;
            }
        }
    }
}
