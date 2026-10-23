#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

int main() {

    srand(time(NULL));
    int experience[8][5];

    int* p1 = &experience[0][0];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            *(p1 + i * 5 + j) = 10 + rand() % 91;
        }
    }
    
    int bonus[5];

    int* p2 = bonus;
    for (int j = 0; j < 5; j++){
        *(p2 + j) = 1 + rand() % 20;
    }

    int itog[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int prohi[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    int* p3 = itog;
    int* p4 = prohi;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            if (*(p1 + i*5 + j) < 20) {
                *(p3 + i) = 0;
                break;
            }
            else { 
                *(p3 + i) += *(p1 + i*5 + j) + bonus[j];
                (*(p4 + i))++;
            }
        }
    }


    int max[2] = {-1, 0};
    int *p5 = max;
    for (int i = 0; i < 8; i++) {
        if (*(p3 + i) > *p5 && *(p4 + i) == 5) {
            *p5 = *(p3 + i);
            *(p5 + 1) = i + 1;
        }
    }

    int min[2] = {1000, 0};
    int *p6 = min;
    for (int i = 0; i < 8; i++) {
        if (*(p3 + i) < *p6 && *(p4 + i) == 5) {
            *p6 = *(p3 + i);
            *(p6 + 1) = i + 1;
        }
    }




    printf("+--------------------------------------+\n");
    printf("| Таблица Результатов                  |\n");
    printf("|--------------------------------------|\n");
    if (*(p5 + 1) != 0) {
        printf("| Максимальный итог: %-4d ( Герой №%-2d) |\n", *p5, *(p5 + 1));
    }
    else {
        printf("| Победитель не определён              |\n");
    }
    printf("|--------------------------------------|\n");
    if (*(p6 + 1) != 0) {
        printf("| Минимальный итог: %-4d ( Герой №%-2d)  |\n", *p6, *(p6 + 1));
    }
    printf("|--------------------------------------|\n");
    printf("| Итоговые значения по игрокам:        |\n");
    for (int i = 0; i < 8; i++) {
        if (*(p3 + i) == 0){
            printf("| Герой № %d не прошел уровень          |\n", i+1);
        }
        else{
            printf("| Герой № %d, очки: %-19d |\n", i+1, *(p3 + i));
        }
    }
    printf("+--------------------------------------+\n");

    getchar();
    return 0;
}
