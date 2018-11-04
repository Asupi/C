#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int count_one_bit(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
			count++;
		n = n / 2;
	}
	return count;
}
int main()
{
	int num = 0;
	printf("ÇëÊäÈë:>");
	scanf("%d,&num");
	int ret = count_one_bit(num);
		printf("ret=%d\n,ret");
	system("pause");
	return 0;
}
