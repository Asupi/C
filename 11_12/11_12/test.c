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
		ret ^= a[i];//retΪ������ͬ��������� 

	int pos = 0;
	while (((ret >> pos) & 1) != 1)
		pos++;

	for (i = 0; i < n; i++) {
		if ((a[i] >> pos) & 1 == 1)//��������
			*pNum1 ^= a[i];
		//		else
		//			*pNum2 ^= a[i];
	}
	*pNum2 = ret ^ *pNum1;//ret = *pNum1 ^ *pNum2����*pNum2 = (*pNum1 ^ *pNum2) ^ *pNum1
}

#define P 1 //��ˮ�ĵ���
#define N 2 //��һƿ��ˮ����Ŀ�ƿ����
//SodaConvert���������ÿ�ƿ��������ˮ����
int SodaConvert(int x)
{
	int ret = x / N;//��ƿ�һ�����ˮ����
	int empty = x / N + x % N;//�һ�����ˮ��ʣ�µĿ�ƿ����֮��
	if (empty > 1)
		return ret + SodaConvert(empty);
	else
		return ret;
}
int main()
{
	int p = 0;
	int n = 0;
	printf("�������");
	scanf("%d", &p);
	n = p / P;
	int bottle = n + SodaConvert(n);//���պȵ�����ˮ����
	printf("%dƿ\n", bottle);
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
	assert(sour != NULL);//����
	while (*dest)
	{
		dest++;
	}//�ҵ�Ŀ���ַ�����'\0'����'\0'��ʼcopy
	while (*dest++ = *sour++)
	{
		;
	}//strcpy����
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
