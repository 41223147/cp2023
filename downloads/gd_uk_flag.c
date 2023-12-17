#include <stdio.h>

void drawUnionJack() {
    // 繪製英國國旗
    printf("\n");

    // 繪製上半部分
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if ((i < 2 || i > 3) && (j < 2 || j > 3)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // 繪製中間橫條
    for (int i = 0; i < 6; i++) {
        printf("*");
    }
    printf("\n");

    // 繪製下半部分
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i < 2 || i > 3) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    // 調用繪製英國國旗的函數
    drawUnionJack();

    return 0;
}