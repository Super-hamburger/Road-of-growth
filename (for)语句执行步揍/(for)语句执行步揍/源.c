#include<stdio.h>
int main()
{
	int i = 0;
	//   初始化；判断；调整
	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			//break;
			continue;
		printf("%2d\n", i);
	}
	return 0;
}