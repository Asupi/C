#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

	/*int  (int n)
	{
		int result = 1;
		while (n > 1)
		{
			result *= n;
			n -= 1;
		}
		return result;
	}*/
int fib(int n)
{
	int result;
	int pre_result;
	int next_older_result;
	result = pre_result = 1;
	while (n > 2)
	{
		n -= 1;
		next_older_result = pre_result;
		pre_result = result;
		result = pre_result + next_older_result;
	}
	return result;
}
	int main()
	{
		/*int i= 0;
		int k = 0;
		for (i = 0, k = 0; k = 0; i++,k++)
		k++;*/
		int n = 0;
		printf("Please Enter:>\n");
		scanf("%d", &n);
		printf("%d\n",fib(n));
		system("pause");
		return 0;
	}
	
	

