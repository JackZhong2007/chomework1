#include<stdio.h>
int Fabonacci(int subscript) {
	int subscript_1 = 1, subscript_2 = 1,temporary=1;
	for (int i = 1; i <= subscript-2; i++) {
		temporary = subscript_2+subscript_1;
		subscript_1 = subscript_2;
		subscript_2 = temporary;
	}
	return temporary;
}
int main() {
	int sub;
	printf("Which number_Fabonacii of the subscript do you wanna to get?\n");
	scanf_s("%d", &sub);
	printf("The number is %d", int(Fabonacci(sub)));
	return 0;
}