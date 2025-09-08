#include<stdio.h>
static int size_Compare(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {
	int number[1001];
	int subscript_number = 1;
	while (1) {
		scanf_s("%d", &number[subscript_number]);
		subscript_number++;
		if (getchar() == '\n') {
			break;
		}
	}
	for (int i = 1; i < subscript_number; i++) {
		number[i + 1] = size_Compare(number[i], number[i + 1]);
	}
	printf("%d",int( number[subscript_number]));
}