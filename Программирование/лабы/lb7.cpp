#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *words[50];
    int count = 0;

    if (fgets(input, sizeof input, stdin) == NULL)
        return 1;

    for (char *w = strtok(input, " \n"); w != NULL && count < 50; w = strtok(NULL, " \n"))
        words[count++] = w;
    
    printf("%s", input);

    for (int i = 0; i < count; i++)
        printf("[%s]\n", words[i]);

    return 0;
}