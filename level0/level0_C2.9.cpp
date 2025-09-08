#include<stdio.h>
int main() {
	int a[5];
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("These are disappeared numbers:");
	for (int i = 0; i < 10; i++) {
		int judge_Appear = 0;
		for (int j = 0; j < 5; j++) {
			if (a[j] == i) {
				judge_Appear = 1;
			}
		}
		if (judge_Appear == 0) {
			printf("%d ", int(i));
		}
	}
}