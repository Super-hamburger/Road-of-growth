#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a;
	printf("����һ��������\n");
	scanf("%d", &a);
	if (a % 2 == 0)
		printf("%dż��", a);
	else if (a % 2 == 1)
		printf("%d����", a);
	else
		printf("�������");
	return 0;
}