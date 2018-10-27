1.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	int a1 = 1;
	int a2 = 1;
	int a3 = 0;
	if (n <= 2)
		return 1;
	else
	{
		while (n > 2)
		{
			a3 = a1 + a2;
			a1 = a2;
			a2 = a3;
			n--;
		}
	}
	return a3;
}
int main()
{
	int n = 0;
	printf("请输入一个第n个数，第n个数的斐波那契数:\n");
	scanf("%d", &n);
	printf("%d", fib(n));
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n = 0;
	printf("请输入一个第n个数，第n个数的斐波那契数:\n");
	scanf("%d", &n);
		printf("%d", fib(n));
		system("pause");
		return 0;
}

2.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

int nPowersofk(int n, int k)
{
	if (k<= 0)
	
		return 1;
	else
	    return n*nPowersofk(n, k - 1);
	
}
int main()
{
	int n = 3;
	int k = 2;
	scanf("%d%d", &n, &k);
	int ret = nPowersofk(n, k);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

3.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m =n%10;
		n = n / 10;
		sum = m + DigitSum(n);
	}
	return sum;
}
int main()
{
	int a;
	printf("请输入一个整数: ");
	scanf("%d", &a);
	printf("各位数之和为:%d\n", DigitSum(a));
	system("pause");
	return 0;
}

4.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
void reverse_string(char* string)
{
	if (*string == '\0')
	{
		return 0;
	}
	reverse_string(string + 1);
	printf("%c", *string);
}
int main()
{
	char string[] = "abcdefghijk";
	reverse_string(string);
	printf("\n");
	system("pause");
	return 0;
}

5.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
非递归
int my_strlen(char *str)
{
	int count = 0;
	while ('\0' != *str)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char *str = "abcdef";
	int len = my_strlen(str);
	printf("%d\n", len);
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
//递归
int my_strlen(char *str)
{
	if ('\0' == *str)
		return 0;
	else
		return 1 + (my_strlen(str + 1));
}
int main()
{
	char*str = "abcdef";
	int len = my_strlen(str);
	printf("%d\n", len);
	system("pause");
	return 0;
}

6.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int Factorial_r(int num) 
{
	//非递归实现
	int k = 1;
	while (num > 0)
		k *= num - 1;
	return k;
}

int Factorial(int num)
{
	//递归实现
	return num > 0 ? num*Factorial(num - 1) : 1;
}
int main()
{
	int n = 0;
	printf("请输入一个数,求他的阶乘:\n");
	scanf_s("%d", &n);
	printf("%d\n", Factorial(n));
	printf("%d\n", Factorial_r(n));
	system("pause");
	return 0;

7.#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int _print(int num)
{
	if (num < 10)
		printf("%d ", num);
	else
	{
		_print(num / 10);
		printf("%d ", num % 10);
	}
}
int main()
{
	int num = 1234;
	_print(num);
	system("pause");
	return 0;
}

