#include <stdio.h>

int main() {
    double summa;
    int popoln, n, r;
    short c = 0;
    short mecyacy = 0;
    double procents = 0;

    printf("Введите начальную сумму вклада: ");
    scanf("%lf", &summa);
    printf("Введите сумму ежемесячного пополнения: ");
    scanf("%d", &popoln);
    printf("Введите стоимость путешествия: ");
    scanf("%d", &n);
    printf("Введите годовую процентную ставку: ");
    scanf("%d", &r);

    printf("+-------+-------------+-----------+-----------+\n");
    printf("| Месяц | Пополнение  | Начислено | Сумма     |\n");
    printf("|-------|-------------|-----------|-----------|\n");
    while (summa < n && mecyacy < 120){
        mecyacy++;
        summa += popoln;
        procents =   summa * r / 1200.0;
        summa += procents;
        if (procents >= 1) {
            c++;
        }
        printf("| %-5d | %-11d | %-9.2f | %-9.2f |\n",
           mecyacy, popoln, procents, summa);
    }

    
    printf("+-------+-------------+-----------+-----------+\n");
    printf("\nВсего месяцев: %d\n", mecyacy);
    printf("Итоговая сумма: %.2f\n", summa);
    printf("Месяцев с начислением >= 1 руб.: %d\n", c);

    getchar();
    return 0;
}