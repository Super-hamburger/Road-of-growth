#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int age = 11;
	if (age < 18)
		printf("未成年");
	else if (age >= 18 && age < 28)
		printf("青年");
	else if (age >= 28 && age < 50)
		printf("壮年");
	else if (age >= 50 && age < 90)
		printf("老年");
	else
		printf("活菩萨");
	return 0;
}