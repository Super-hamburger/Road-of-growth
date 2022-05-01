#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int ch = 0;
	//Ctrl + zºóÍ£Ö¹
	while ((ch = getchar()) != EOF)//EOF--end of file=>-1
	{
		putchar(ch);
	}
	/*int ch = getchar();
	putchar(ch);
	printf("%c\n", ch);
	return 0;*/
}