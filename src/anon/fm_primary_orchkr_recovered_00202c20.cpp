#include "../common/types.h"

void func_00202c20(u8* object, s32* offset, s32* width, s32* step, s32* height) {
    s32 base = 0;
    s32 sizeX = 0x1000;
    s32 sizeY = 0x1000;

    switch (object[0x10]) {
    case 1:
        sizeX = 0x800;
        break;
    case 2:
        sizeX = 0x400;
        break;
    }
    switch (object[0x11]) {
    case 1:
        sizeY = 0x800;
        break;
    case 2:
        sizeY = 0x400;
        break;
    }
    switch (object[0x12]) {
    case 1:
        base = 0x400;
        sizeX += 0x400;
        break;
    case 2:
        base = 0x800;
        sizeX += 0x800;
        break;
    case 3:
        base = 0xc00;
        sizeX += 0xc00;
        break;
    }
    *offset = base + 0x10;
    *width = sizeX - 0x10;
    *step = 0x10;
    *height = sizeY - 0x10;
}
