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
//	printf("��תǰ:%s\n", arr);
//	printf("��ת��λ:");
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
//		printf("�������\n");
//		scanf("%d", &n);
//	}
//}
//left_remove(arr, n, len);
//printf("��ת��:%s\n", arr);
//	system("pause");
//	return 0;
//}


#include <string.h>

int find_substring(char *msg, char *substring)
{
	int len = strlen(msg);
	char *tmp = (char*)malloc(2 * len + 1);  //����2������ռ�
	if (len == strlen(substring))  //��֤Ҫ�Ƚϵ������ַ���������ͬ
	{
		strcpy(tmp, msg);  //ԭ�����ַ����������¿ռ���
		strcat(tmp, msg);  //�ַ�����ƴ�ӣ�ʵ�ָ���
		if (strstr(tmp, substring) != NULL)
		{
			return 1;
		}
	}
	free(tmp);  //�ͷ�������¿ռ�
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
