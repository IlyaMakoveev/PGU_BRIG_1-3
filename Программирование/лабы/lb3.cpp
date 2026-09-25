#include <stdio.h>
#include <math.h>

int main() {
    int s1, s2, s3, s4;
    int k1, k2;
    int count = 0;
    int highest = 0;

    printf("Введите результаты сессии 4 студентов через пробел: ");
    scanf("%d %d %d %d", &s1, &s2, &s3, &s4);

    printf("Введите проходной и максимамальный баллы через пробел: ");
    scanf("%d %d", &k1, &k2);

    if (s1 >= k1){count ++;}
    if (s2 >= k1){count ++;}
    if (s3 >= k1){count ++;}
    if (s4 >= k1){count ++;}

    printf("Количество студентов, сдавших сессию: %d\n", count);

    if (s1 >= k2){highest ++;}
    if (s2 >= k2){highest ++;}
    if (s3 >= k2){highest ++;}
    if (s4 >= k2){highest ++;}

    printf("Количество студентов, набравших максимальный балл: %d\n", highest);

    int max = s1;
    int min = s1;

    int raznitsa = max - min;

    if (s2 > max){max = s2;}
    if (s3 > max){max = s3;}
    if (s4 > max){max = s4;}

    if (s2 < min){min = s2;}
    if (s3 < min){min = s3;}
    if (s4 < min){min = s4;}

    if (raznitsa > 30) {printf("Высокий разброс знаний \n");}

    if (s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0) {printf("Неявка на экзамен \n");}

    int ave_grade = ceil((s1 + s2 + s3 + s4) / 4.0 / 20.0);

    switch (ave_grade){
        case 5:
            printf("Отличная группа \n");
            break;
        case 4:
            printf("Хорошая группа \n");
            break;
        case 3:
            printf("Удовлетворительная группа \n");
            break;
        case 1:
        case 2:
            printf("Слабая группа \n");
            break;
        default:
            printf("Ошибка вычислений \n");
            break;
    }
    return 0;
}