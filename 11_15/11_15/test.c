#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include<assert.h>
//int main()
//{
//	system("pause");
//
//	return 0;
//}
//	char *strcpy(char *dst, const char *src)
//	{
//		assert(dst != NULL && src != NULL);
//		char*ret = dst;
//		while ((*dst++ = *src++) != '\0');
//		system("pause");
//		return ret;
//	}
extern char* my_strstr(const char* dest, const char* src);
int main()
{ 
	char *str1 = "qwee";
	char*str2 = "qwer";
	char*ret = my_strstr(str1, str2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}
char *my_strstr(const char *dest, const char *src)
{
	char *pdest = dest;
	char *psrc = src;
	
	while (*psrc&*pdest)
	{
		if (*psrc == *pdest)
		{
			psrc++;
			pdest++;
		}
		else
			break;
	}
	if ((*psrc == '\0'))
		return psrc;
	else
		return NULL;
}