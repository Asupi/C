#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned value)
{
	unsigned int sum = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		sum += ((value >> i) & 1) << (31 - i);
	}
	return sum;
}
int main()
{
	unsigned int num = 25;
	printf("��ת��%u\n", reverse_bit(num));
	system("pause");
	return 0;
}
int mean_n(int x, int y)
{
	int z = 0;
	//z = (x&y) + (x^y) / 2;
	z = (x + y) >> 1;
    return z;
}
int main()
{
	int a = 0;
	int b = 0;
	printf("������������ a b:\n");
	scanf("%d %d", &a, &b);
	printf("mean value:%d\n", mean_n(a, b));
	system("pause");
	return 0;
}
void check(int*arr, int sz)
{
	int i = 0;
	int a = 0;
	for (i = 0; i < sz; i++)
	{
		a = a^arr[i];
	}
	printf("���ɶԳ��ֵ�������:%d\n", a);
}
int main()
{
	int arr[] = { 1,2,3,4,5,4,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	check(arr, sz);
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
static int my_strlen(const char *str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}//���ַ�������
static void reverse_arr(char*left, char*right)
//��Ϊ�������ֻ������һ�������е��ã�����static�ı����������ԣ��ú�������ȫ
{
	while (left < right)
	{
		char temp = *right;
		*right = *left;
		*left = temp;
		left++;
		right--;
	}
}//����һ������
void reverse(char *str)
{
	assert(str != NULL);
	char *left = str;
	char *right = str + my_strlen(str) - 1;
	char *cur = str;
	reverse_arr(left, right);
	while(*cur)
	{
		char *start = cur;
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		reverse_arr(start, cur - 1);
		//�ҵ�ÿһ�����ʣ�Ȼ������
		if (*cur == ' ')
		{
			cur++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	reverse(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}