#include<stdio.h>
int main()
{
	int i = 0;
	//   ��ʼ�����жϣ�����
	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			//break;
			continue;
		printf("%2d\n", i);
	}
	return 0;
}