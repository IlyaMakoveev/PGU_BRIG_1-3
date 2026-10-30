#include <stdio.h>
#include <string.h>

int main() {
    char st[50];
    printf("Введите команду: ");
    fgets(st, sizeof(st), stdin);

    printf("%s", st);

    char* words = strtok(st, " ");

    char deystv[10] = "";

    char* params[10];
    char result[256]; 
    
    result[0] = '\0'; 

    short len_params = 0;

    short c = 0;

    while (words != NULL) {
        if (strcmp(deystv, "") == 0){
            strcpy(deystv, words);
        }
        else {
            params[c] = words;
            c++;
        }
        words = strtok(NULL, " ");
    }
    if (strcmp(deystv, "move") == 0 || strcmp(deystv, "open") == 0 || strcmp(deystv, "close") == 0 || strcmp(deystv, "stop") == 0) {
        printf("Действие: %s\n", deystv);
        if (c > 0) {
            for (int i = 0; i < c; i++) {
                strcat(result, params[i]); 
                len_params += strlen(params[i]);
                if (i < c - 1) {
                    strcat(result, " ");
                }
            }
            printf("Параметры:%s\n", result);
            printf("Длина параметров: %d\n", len_params-1);
            printf("Колличество параметров: %d\n", c);
            printf("Команда выполнена успешно\n"); 
        }        
    }
    else {
        printf("Ошибка: неизвестное действие\n");
    }


    getchar();
    return 0;
}