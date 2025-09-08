#include<stdio.h>
int main() {
	int subscript[10] = { 0 };
	int number[5];
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &number[i]);
		subscript[number[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < subscript[i]; j++) {
			printf("%d ", int(i));
		}
	}
	return 0;
}