#include<stdio.h>
void Judge_LeapYear(int a) {
	if (a % 100 == 0) {
		if (a % 400 == 0) {
			printf("This year is a leap year!");
		}
		else {
			printf("This year is not a leap year!");
		}
	}
	else if(a%4==0){
		printf("This year is a leap year!");
	}
	else {
		printf("This year is not a leap year!");
	}
}
int main() {
	int year;
	scanf_s("%d", &year);
	Judge_LeapYear(year);
	return 0;
}