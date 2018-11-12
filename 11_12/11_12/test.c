#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[] = { 1, 3, 5, 7, 1, 3, 5, 8 };
	int sz = sizeof(a) / sizeof(a[0]);
	int num1 = 0, num2 = 0;
	find_num(a, sz, &num1, &num2);
	printf("%d %d\n", num1, num2);
	system("pause");
	return 0;
}
int find_num(int a[], int n, int *pNum1, int *pNum2)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < n; i++)
		ret ^= a[i];//ret为两个不同数字异或结果 

	int pos = 0;
	while (((ret >> pos) & 1) != 1)
		pos++;

	for (i = 0; i < n; i++) {
		if ((a[i] >> pos) & 1 == 1)//分组条件
			*pNum1 ^= a[i];
		//		else
		//			*pNum2 ^= a[i];
	}
	*pNum2 = ret ^ *pNum1;//ret = *pNum1 ^ *pNum2所以*pNum2 = (*pNum1 ^ *pNum2) ^ *pNum1
}

#define P 1 //汽水的单价
#define N 2 //换一瓶汽水所需的空瓶个数
//SodaConvert函数返回用空瓶换来的汽水个数
int SodaConvert(int x)
{
	int ret = x / N;//空瓶兑换的汽水个数
	int empty = x / N + x % N;//兑换的汽水和剩下的空瓶个数之和
	if (empty > 1)
		return ret + SodaConvert(empty);
	else
		return ret;
}
int main()
{
	int p = 0;
	int n = 0;
	printf("请输入金额：");
	scanf("%d", &p);
	n = p / P;
	int bottle = n + SodaConvert(n);//最终喝到的汽水个数
	printf("%d瓶\n", bottle);
	system("pause");
	return 0;
}
#include<assert.h>
char* my_strcpy(char *dest, char *str)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(str != NULL);
	while (*str++ = *dest++){
		;
	}
	return ret;
}
int main()
{
	char buf1[20]= "abcdefghijk";
	char buf2[] = "mnopq";
		my_strcpy(buf1, buf2);
	printf("%s\n", buf1);
	system("pause");
}

#include<assert.h>
char *my_strcat(char *dest, const char *sour)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(sour != NULL);//断言
	while (*dest)
	{
		dest++;
	}//找到目标字符串的'\0'，从'\0'开始copy
	while (*dest++ = *sour++)
	{
		;
	}//strcpy函数
	return ret;
}
int main()
{
	char s1[] = "hello ";
	char s2[] = "world";
	char *ret = my_strcat(s1, s2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}
