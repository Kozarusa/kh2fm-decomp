#include "../common/types.h"

s32 func_00304468(void* left, void* right) {
    u32 leftCount = *(u32*)((u8*)left + 16);
    u32 rightCount = *(u32*)((u8*)right + 16);
    u32 countDifference = leftCount - rightCount;
    if (countDifference != 0) {
        return (s32)countDifference;
    }

    u32* leftBase = (u32*)((u8*)left + 20);
    u32* rightBase = (u32*)((u8*)right + 20);
    u32* leftCursor = leftBase + rightCount;
    u32* rightCursor = rightBase + rightCount;
    do {
        --leftCursor;
        --rightCursor;
        u32 leftValue = *leftCursor;
        u32 rightValue = *rightCursor;
        if (leftValue != rightValue) {
            return leftValue < rightValue ? -1 : 1;
        }
    } while (leftBase < leftCursor);
    return 0;
}
