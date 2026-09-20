#include <iostream>

int main() {
    int thrust_i;
    int angle_i;
    int fuel_i;

    scanf("%d", &thrust_i);
    scanf("%d", &angle_i);
    scanf("%d", &fuel_i);

    double thrust = (double)thrust_i;
    double angle = (double)angle_i;
    double fuel = (double)fuel_i;

    double x = angle * 3.14159 / 180.0;

    double vertical = thrust * (x - x * x * x / 6.0);

    double time = fuel * 1.5;

    double speed = (vertical / 10.0) * time;

    printf("%f\n", speed);
}