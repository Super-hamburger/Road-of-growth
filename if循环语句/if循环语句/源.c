#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int age = 11;
	if (age < 18)
		printf("δ����");
	else if (age >= 18 && age < 28)
		printf("����");
	else if (age >= 28 && age < 50)
		printf("׳��");
	else if (age >= 50 && age < 90)
		printf("����");
	else
		printf("������");
	return 0;
}