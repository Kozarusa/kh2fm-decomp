#include "../common/types.h"
extern "C" u8 D_0036dde8[];

void func_001c35a0(u8* state) {
    s32 row = 0;
    u8* table = D_0036dde8;
    do {
        s32 column = 4;
        do {
            u32 bit = table[column];
            if (((u32*)state)[bit >> 5] & (1 << (bit & 0x1f))) {
                *(u8*)(row + (s32)state + 0x20) = (u8)(column + 1);
                break;
            }
            column = column - 1;
        } while (column >= 0);
        row = row + 1;
        table = table + 5;
    } while (row < 5);
}

