#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int swap_num(int *arr,int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (0 != arr[i] % 2)
		{
			printf("%d ", arr[i]);
		}
	}
	for (i = 0; i < len; i++)
	{
		if (0 == arr[i] % 2)
		{
			printf("%d ",arr[i]);
		}
	}
}
int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	swap_num(arr, len);
	system("pause");
	return 0;
}

	int search(int arr[3][3], int k, int row, int col)
	{
		int x = 0;
		int y = col - 1;
		while ((x<row) && (y >= 0))//�������Ͼ������ԣ���kÿ�������Ͻǵ����Ƚϣ������±ƽ���������ƽ���ֱ�����ҵ����½ǵ��������������ȣ�ֱ�ӷ���0��˵��û�ҵ�
		{
			if (k > arr[x][y])
			{
				x++;
			}
			else if (k == arr[x][y])
			{
				return 1;
			}
			else
			{
				y--;
			}
		}
		return 0;
	}
	int main()
	{
		int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int key = 5;
		int ret = 0;
		ret = search(arr, key, 3, 3);//��װһ�����������ú����ķ���ֵ���ж��Ƿ��ҵ�
		if (1 == ret)
		{
			printf("�ҵ���\n");
		}
		else
		{
			printf("�Ҳ���\n");
		}

    system("pause");
	return 0;
} 