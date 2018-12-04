#define _CRT_SECURE_NO_WARNINGS 1
////#define MAX(a,b) ((a)>(b)?(a):(b))
#define M 10
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//int x, y, z;
	//x = 5;
	/*y = 8;*/
	//z = MAX(x++, y++);
	/*printf("%s:%d\n", __FILE__,__LINE__);*/
	/*printf("x=%d,y=%d,z=%d\n", x, y, z);*/
	printf("M=%d\n", M);
#undef M 
	printf("M=%d\n", M);
	system("pause");
	return 0;
}
