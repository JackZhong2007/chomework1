#include<stdio.h>
int factorial(int number) {
	int conclusion = 1;
	for (int i = 2; i <= number; i++) {
		conclusion = conclusion * i;
	}
	return conclusion;
}
int main() {
	int num;
	scanf_s("%d", &num);
	printf("%d", int(factorial(num)));
	return 0;
}