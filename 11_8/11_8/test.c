#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);
	printf("&arr =%p\n", &arr);

	printf("arr+1 = %p\n", arr+1);
	printf("&arr+1 = %p\n", &arr+1);
	/*char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3 = "hello bit.";
	char *str4 = "hello bit.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str3)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");*/
	system("pause");
	return 0;
}

