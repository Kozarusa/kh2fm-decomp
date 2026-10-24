#include "../common/types.h"
extern "C" u8 D_003637e0[];

void func_002edf28(u32 object) {
    register u32 table asm("$15") = (u32)D_003637e0; // why: original forms the table address in t7 (002edf68 sibling pattern)
    *(volatile u32*)(object + 4) = 0;
    asm volatile("" : "+r"(table)); // why: keeps the table address formed before the first stores (002edf68 sibling pattern)
    *(volatile u32*)(object + 12) = 0;
    *(volatile u32*)(object + 0) = table;
    asm volatile("" ::: "memory"); // why: keeps store order (002edf68 sibling pattern)
    register u32 fill asm("$14") = 128; // why: original keeps the byte fill value in t6
    asm volatile("" : "+r"(fill)); // why: keeps the fill value materialized at this point (002edf68 sibling pattern)
    *(volatile u32*)(object + 8) = 0;
    *(volatile u32*)(object + 16) = 0;
    asm volatile("" ::: "memory"); // why: keeps store order (002edf68 sibling pattern)
    register u32 tail asm("$15") = object + 24; // why: original forms the tail base in t7
    asm volatile("" : "+r"(tail)); // why: keeps the tail base formed before the byte stores (002edf68 sibling pattern)
    *(volatile u32*)(object + 20) = 0;
    *(volatile u8*)(object + 24) = fill;
    *(volatile u8*)(tail + 3) = fill;
    *(volatile u8*)(tail + 1) = fill;
    *(volatile u8*)(tail + 2) = fill;
    *(volatile u32*)(object + 28) = 0;
}
