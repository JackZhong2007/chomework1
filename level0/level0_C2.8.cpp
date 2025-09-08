#include<stdio.h>
int main() {
	int a[1001],n=0;
	while (1) {
		scanf_s("%d", &a[n]);
		n++;
		if (getchar() == '\n') {
			break;
		}
	}
	while (1) {
		n--;
		printf("%d ", int(a[n]));
		if (n == 0) {
			break;
		}
	}
	return 0;
}