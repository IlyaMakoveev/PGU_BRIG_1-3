#include <stdio.h>
#include <stdlib.h>

int main() {
    int experience[8][5];
    int* exp_ptr = &experience[0][0];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            *(exp_ptr + i * 5 + j) = (rand() % 91) + 10;
        }
    };
    
    int bonus[5];
    int* bon_ptr = &bonus[0];
    for (int i = 0; i < 5; i++) {
        *(bon_ptr + i) = (rand() % 20) + 1;
    }

    int itog[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int* itg_ptr = &itog[0];
    int prohi[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int* phr_ptr = &prohi[0];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            if (*(exp_ptr + i * 5 + j) < 20) {
                break;
            }
            else { 
                *(itg_ptr + i) += *(exp_ptr + i * 5 + j) + *(bon_ptr + j);
                (*(phr_ptr + i))++;
            }
        }
    }

    int max[2] = {-1, 0};
    int *max_ptr = &max[0];
    for (int i = 0; i < 8; i++) {
        if (*(itg_ptr + i) > *(max_ptr) && *(phr_ptr + i) == 5) {
            *(max_ptr) = *(itg_ptr + i);
            *(max_ptr + 1) = i + 1;
        }
    }

    printf("+--------------------------------------+\n");
    printf("| Таблица Результатов                  |\n");
    printf("|--------------------------------------|\n");
    if (*(max_ptr + 1) != 0) {
        printf("| Максимальный итог: %-4d ( Герой №%-2d) |\n", *(max_ptr), *(max_ptr + 1));
    }
    else {
        printf("| Победитель не определён              |\n");
    }
    printf("|--------------------------------------|\n");
    printf("| Итоговые значения по игрокам:        |\n");
    for (int i = 0; i < 8; i++) {
        printf("| Герой № %d, очки: %-19d |\n", i+1, *(itg_ptr + i));
    }
    printf("+--------------------------------------+\n");

    getchar();
    return 0;
}
