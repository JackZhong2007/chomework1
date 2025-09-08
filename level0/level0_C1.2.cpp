#include<stdio.h>
int main() {
    int number;
    scanf_s("%d", &number);
    if (number % 13 == 0) {
        printf("This number is a multiple of 13");
    }
    else {
        printf("This number is not a multiple if 13");
    }
    return 0;
}