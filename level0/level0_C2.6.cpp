#include<stdio.h>
int main() {
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % 7 == 0 || i % 10 == 7) {
			printf("%d ", int(i));
			sum += i;
		}
	}
	printf("\nThe sum of these numbers is %d", int(sum));
}