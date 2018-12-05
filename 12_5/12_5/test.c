#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*int i = 0;
	int arr[] = { 0 };
	printf("Please Enter\n");
	scanf("%d",&arr);
	if (i % 2==0)
		printf("Å¼Êý",arr[i]);
	else
		printf("ÆæÊý",arr[i]);*/
	/*int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2)
		{
			printf("%d ", i);
		}
		
	}
*/
	int i = 0;
	 
		for (i = 100; i <= 200; i++)
		{
			int j = 0;
			for (j = 2; j <= i; j++)
			{
				if (i%j == 0)
				{
					break;
				}
			}
			if (i == j)
			{
			
				printf("%d ", i);
			}
		}
		
	system("pause");
	return 0;  
}

