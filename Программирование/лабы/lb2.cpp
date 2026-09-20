#include <stdio.h>

int main() {
    printf("+--------------------------------------+\n");
    printf("|   КОД ДОСТУПА К СЕКРЕТНОМУ БУНКЕРУ   |\n");
    printf("|--------------------------------------|\n");
    printf("| Вариант № 3                          |\n");
    printf("| Бригада № 3                          |\n");
    printf("| Состав: Маковеев И.С., Свищев И.С.   |\n");
    printf("+--------------------------------------+\n");

    char initial;
    char fullname[100];
    int level;
    int errorcode;
    double x,y;
    unsigned int number;

    printf("Введите инициал сотрудника:");
    scanf(" %c", &initial);

    printf("Введите имя и фамилию сотрудника:");
    scanf(" %99[^\n]", fullname);

    printf("Введите уровень доступа сотрудника (+):");
    scanf("%d", &level);

    printf("Введите код ошибки (-):");
    scanf("%d", &errorcode);

    printf("Введите координаты входа через пробел:");
    scanf("%lf %lf", &x, &y);

    printf("Введите номер терминала:");
    scanf("%u", &number);

    printf("+--------------------------------------+\n");
    printf("|         КАРТОЧКА СОТРУДНИКА          |\n");
    printf("|--------------------------------------|\n");
    printf("| Инициал: %-28c|\n", initial);
    printf("| Имя и фамилия: %-22s|\n", fullname);
    printf("| Уровень доступа: %-20d|\n", level);
    printf("| Код ошибки: %-25d|\n", errorcode);
    printf("| Координаты входа: %-8.2f %-8.2f  |\n", x, y);
    printf("| Номер терминала: %-20.5u|\n", number);
    printf("+--------------------------------------+\n");
    getchar();
    return 0;
}
