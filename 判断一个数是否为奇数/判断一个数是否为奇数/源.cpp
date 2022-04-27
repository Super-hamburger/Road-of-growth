#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a;
	printf("输入一个整数：\n");
	scanf("%d", &a);
	if (a % 2 == 0)
		printf("%d偶数", a);
	else if (a % 2 == 1)
		printf("%d奇数", a);
	else
		printf("输入错误");
	return 0;
}