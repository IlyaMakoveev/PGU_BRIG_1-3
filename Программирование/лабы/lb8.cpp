#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[50];
} Client;

typedef struct {
    int num;
    char device[50];
    double cost;
    char status[15];
    Client client;
} Request;

void inputRequest(Request* req) {
    printf("-------------------------------\n");
    printf("Введите номер заявки: ");
    scanf("%d", &req->num);

    printf("Введите название устройства: ");
    scanf(" %49[^\n]", req->device);

    printf("Введите стоимость: ");
    scanf("%lf", &req->cost);

    printf("Введите статус: ");
    scanf(" %14[^\n]", req->status);

    printf("Введите имя клиента: ");
    scanf(" %49[^\n]", req->client.name);

    printf("Введите телефон клиента: ");
    scanf(" %49[^\n]", req->client.phone);

}

void printAllRequests(Request arr[], int count){
    for (int i = 0; i < count; i++) {
        printf("-------------------------------\n");
        printf("Заявка %d:\n", i + 1);
        printf("Номер заявки: %d\n", arr[i].num);
        printf("Название устройства: %s\n", arr[i].device);
        printf("Стоимость: %.2f\n", arr[i].cost);
        printf("Статус: %s\n", arr[i].status);
        printf("Имя клиента: %s\n", arr[i].client.name);
        printf("Телефон клиента: %s\n", arr[i].client.phone);
        printf("\n");
    }

}

void changeStatus(Request arr[], int n){
    for (int i = 0; i < n; i++){
        if (arr[i].cost > 0) {
            strcpy(arr[i].status, "В работе");
        }
        else {
            strcpy(arr[i].status, "Ожидает оплаты");
        }
    }
}

int main() {
    Request requests[5];
    int n;
    printf("Введите количество заявок: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        inputRequest(&requests[i]);
    }

    printAllRequests(requests, n);
    changeStatus(requests, n);
    printf("После изменений:\n");
    printAllRequests(requests, n);

    return 0;
}