#define _CRT_SECURE_NO_WARNINGS //#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	int i = 0;
//	printf("please enter a num:\n");
//	scanf("%d", &num);
//	printf("��������Ϊ��\n");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", (num >> i) & 1);//ÿ����������λ���
//		if ((i + 7) % 8 == 0)//ÿ�ĸ���ӡһ���ո񷽱�۲�
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
//	printf("ż������Ϊ��\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (num >> i) & 1);//ÿ������ż��λ���
//		if ((i + 8) % 8 == 0)//ÿ�ĸ���ӡһ���ո񷽱�۲�
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0, n = 0;
//	printf("����������:");
//	scanf("%d", &i);
//	while (i)
//	{
//		n = i % 10;
//		i = i / 10;
//		printf("%d ", n);
//	}
//	system("pause");
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//void fun(int m, int n)
//{
//	int t = 0;
//	int count = 0;
//	t = m^n;//�õ���ͬ�ı���λ��
//	while (t)
//	{
//		t = t&(t - 1);//�õ�����λΪһ�ĸ���
//		count++;
//	}
//	printf("count=%d\n", count);
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int count = 0;
//	printf("��������������");
//	scanf("%d%d", &m, &n);
//	fun(m, n);
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a < 6; a++)
	{
		for (b = 1; b < 6; b++)
		{
			for (c = 1; c < 6; c++)
			{
				for (d = 1; d < 6; d++)
				{
					for (e = 1; e < 6; e++)
					{
						if ((((b == 2) || (a == 3)) &&
							((b == 2) || (e == 4)) &&
							((c == 1) || (d == 2)) &&
							((c == 5) || (d == 3)) &&
							((e == 4) || (a == 1))) == 1)
						{
							while ((a != b) && (a != c) && (a != d) && (a != e) &&
								(b != c) && (b != d) && (b != e) && (c != d) && (c != e))
							{
								printf("A=%d B=%d C=%d D=%d E=%d\n", a, b, c, d, e);
								break;
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		int killer = 65 + i;
		j = ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D'));
		if (j == 3)
		{
			printf("ɱ��������%c\n", killer);
			break;
		}
	}
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (0 == j) //ÿһ�еĵ�һ������Ϊ0
				arr[i][j] = 1;
			if (i == j) //ÿ�����һ������Ϊ0
				arr[i][j] = 1;
			if (i > 1 && j>0)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			printf("%-3d ", arr[i][j]); //'-'���������
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

