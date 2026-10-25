#include "../common/types.h"

void func_00201ca0(u8* object, s32* left, s32* right, s32* top, s32* bottom) {
    s32 offset = 0;
    s32 width = 4096;
    s32 height = 4096;
    switch (object[22]) {
    case 1:
        width = 2048;
        break;
    case 2:
        width = 1024;
        break;
    }
    switch (object[23]) {
    case 1:
        height = 2048;
        break;
    case 2:
        height = 1024;
        break;
    }
    switch (object[24]) {
    case 1:
        offset = 1024;
        width += 1024;
        break;
    case 2:
        offset = 2048;
        width += 2048;
        break;
    case 3:
        offset = 3072;
        width += 3072;
        break;
    }
    *left = offset + 16;
    *right = width - 16;
    *top = 16;
    *bottom = height - 16;
}
