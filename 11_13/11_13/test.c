#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#pragma waring(disable:4996)
#define NUM 8
typedef unsigned int u_int_t;
//version 2
unsigned int CounBits(unsigned int x_)
{
	//10000000000000
	int count = 0;
	int count_ = 0;
	while (x_)
	{
		x_ = x_&(x_ - 1);
		count++;
	}
	return count_;
}
	//}
	////version 1
	//int CountBits(unsigned int x_)
	//{
	//	unsigend int flag_ = 1;
	//	int top_ = sizeof(x_)*NUM;
	//	int count_ = 0;
	//	while (top_)
	//	{
	//		if (x_&flag_)
	//		{
	//			count++;
	//		}
	//		flag_ <<= 1;
	//		top--;
	//	}
	//	return count_;
	//
	//}
	//void PrintBit(u_int_t_data_)
	//{
	//	u_int_y flag_ = 0x80000000;//1000 0000 0000 0000 0000 0000 0000 0000
	//}
	//printf("Plase Enter : ");
	//while (flag_)
	//{
	//	if (data_&flag_)
	//	{
	//		printf("1 ");
	//	}
	//	else
	//	{
	//		printf("0 ");
	//
	//	}
	//	flag_ >>= 2;
	//}
	//printf("\n");
	//printf("Plase Enter : ");
	//while (flag_)
	//{
	//	if (data_&flag_)
	//	{
	//		printf("1 ");
	//	}
	//	else
	//	{
	//		printf("0 ");
	//
	//	}
	//	flag_ >>= 2;//flag<<=2;
	//}
	//printf("\n");
	//void PrintBinData(u_int_t_x)
	//{
	//	u_int_t_flag = 0x80000000;
	//	while (flag_)
	//	{
	//		if (flag_&x_)
	//		{
	//			printf("1 ");
	//		}
	//		else
	//		{
	//			printf("0 ");
	//		} 
	//		flag_ >>= 1;
	//
	//	}
	//	printf("\n");
	//}
	static int Diffbit(u_int_t x_, u_int_t y_)
	{
		u_int_t res_ = x_^y_;
		return CountBits(res_);
	}
	void PlayerNo()
	{
		int a = 1;
		int b = 1;
		int c = 1;
		int d = 1;
		int e = 1;
		unsigned flag = 0;
		for (; a <= 5; a++)
		{
			//flag=0;
			for (b = 1; b <= 5; b++)
			{
				for (c = 1; c <= 5; c++)
				{
					for (d = 1; d <= 5; d++)
					{
						for (e = 1; e <= 5; e++)
						{
							flag = 0;
							if ((b == 2) + (a == 3) == 1 && \
								(b == 2) + (e == 4) == 1 && \
								(c == 1) + (d == 2) == 1 && \
								(c == 5) + (d == 3) == 1 && \
								(e == 4) + (a == 1) == 1)
								flag |= (1 << (a - 1));
							flag |= (1 << (c - 1));
							flag |= (1 << (d - 1));
							flag |= (1 << (b - 1));
							flag |= (1 << (e - 1));
							if (flag == 1 || flag == 3 || flag == 7 ||  flag == 15 || flag || 31)
							{
								printf("a,b,c,e:%d %d %d %d %d\n", a, b, c, d, e);
							}
							//while(flag)
							//{
							//if(!(flag&1))
							{
								//break
								//}
								//flag>>=1;
								//}
								//flag(flag==0){
								//printf("a,b,c,e:%d %d %d %d %d\n", a, b, c, d, e);


								//}
							}
						}
					}
				}
			}
		}
	}
	void FindKiller()
	{
		char killer_ = 'A';
		for (; killer_ <= 'D'; killer_++)
		{
			if ((killer_ != 'A') + (killer_ == 'C') + (killer_ == 'D') + (killer_ != 'D') == 3)
			{
				printf("killer:%c\n", killer_);
			}
		}
	}
	int Avg(int x_, int y_)
	{
		return (x_&y_) + ((x_^y_) >> 1);
	}
	int main()
	{
		printf("%d\n", Avg(10, 20));
		/*FindKiller();
		PlayerNo();
		u_int_t x_, y_;
		printf("Please Enter<x,y>:");
		scanf("%u%u", &x_, &y_);

		int count_ = DiffBit(x_, y_);
		printf("%u : %u diff:%d\n", x_, y_, count_);
		PrintBinData(data);
		PrintBit(data);
		print("%d bit 1 num is : %d\n", data, count_);*/
		system("pause");
		return 0;
	}

							
							

