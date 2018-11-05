#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
//void left_remove(char*p, int n, int len)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		char tmp = p[0];
//		for (j = 0; j < len; j++)
//		{
//			p[j] = p[j + 1];
//		}
//		p[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int n;
//	int len = strlen(arr);
//	printf("旋转前:%s\n", arr);
//	printf("旋转几位:");
//	scanf("%d", &n);
//	while (n<1 || n>len - 1)
//	{
//		if (n == len)
//		{
//			printf("%s\n", arr);
//			system("pause");
//			return 0;
//	}
//	else
//	{
//		printf("输入错误\n");
//		scanf("%d", &n);
//	}
//}
//left_remove(arr, n, len);
//printf("旋转后:%s\n", arr);
//	system("pause");
//	return 0;
//}


#include <string.h>

int find_substring(char *msg, char *substring)
{
	int len = strlen(msg);
	char *tmp = (char*)malloc(2 * len + 1);  //申请2倍数组空间
	if (len == strlen(substring))  //保证要比较的两个字符串长度相同
	{
		strcpy(tmp, msg);  //原来的字符串拷贝到新空间里
		strcat(tmp, msg);  //字符串的拼接，实现复制
		if (strstr(tmp, substring) != NULL)
		{
			return 1;
		}
	}
	free(tmp);  //释放申请的新空间
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefba";
	printf("%d\n", find_substring(arr1, arr2));
	system("pause");
	return 0;
}
