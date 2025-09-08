#include<stdio.h>
int main() {
    int number;
    scanf_s("%d", &number);
    if (number > 0) {
        printf("This is a postive number\n");
    }
    else if (number < 0) {
        printf("This is a negative number\n");
    }
    else {
        printf("I remember that I just need to jugde whether the num greater than '0'\n");
    }
    if (number % 2 == 0) {
        printf("This is a even number");
    }
    else {
        printf("This is a odd number");
    }
    return 0;
}