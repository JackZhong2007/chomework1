#include<stdio.h>
void Array_summation(int array[],int length) {
	int sum=0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	printf("%d", int(sum));
}
int main() {
	int Array[1001],subscript=0;
	while (1) {
		scanf_s("%d", &Array[subscript]);
		subscript++;
		if (getchar() == '\n') {
			break;
		}
	}
	Array_summation(Array,subscript);
	return 0;
}