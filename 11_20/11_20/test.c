#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct A{
	char a;
	int b;
	char c;
	
};
int main()
{
	printf("%d\n", sizeof(struct A));
	system("pause");
	return 0;
}
//int my_strcmp(const char *str1, const char *str2)
//{
//	assert(str1);
//	assert(str2);
//	int ret = 0;
//	while (!(ret = *(const unsigned char *)str1 - *(const unsigned char *)str2) && *str1){
//		str1++, str2++;
//	}
//	if (ret > 0){
//		return 1;
//	}
		//return -1; 
//	}
//	else{
//		//do nothing
//	}
//	return 0;
	/*while (*str1&&*str2){
		if (*str1 > *str2){
			return 1;
		}
		else if (*str1 < *str2){
			return -1;
		}
		else{

		}
		str1++, str2++;
	}
	if (*str1>*str2){
		return 1;
	}
	else if (*str1 < *str2){
		return -1;
	}
	else{
		return 0;
	}*/
//}
//void *my_memmove(char *dst, const char *src, int num)
//{
//	assert(dst);
//	assert(src);
//	if (src < dst&&dst < src + num){
//		//r->1
//		char *dst_ = (char*)dst + num - 1;
//		const char *src_ = (const char *)src + num - 1;
//		while (num){
//			*dst_ = *src_;
//			dst_--, src_--;
//			num--;
//		}
//	}
//	else{
//		//l->r
//		char *dst_ = (char *)dst;
//		const char *src_ = (const char *)src;
//		while (num){
//			*dst_ = *src_;
//			src_++, dst_++;
//			num--;
//
//		}
//	}
//	return dst;
//}
//int main()
//{
//	char a[32] = "abcdef123456";
//	char b[32] = "abcdef123456";
//	my_memmove(a+1, a, strlen(a) + 1);
//	printf("%s\n", a);//aabcd...6
//	my_memmove(b,b+1, strlen(b) + 1);
//	printf("%s\n", b);//bcd..6
////void *my_memcpy(void *dst, const void *src, int num)
////{
////	assert(dst);
////	assert(src);
////	char *dst_ = (char *)dst;
////	const char *src_ = (const char *)src;
////	while (num){
////		*dst_ = *src_;
////		src_++, dst_++;
////		num--;
////	}
////	return dst;
////}
//////int main()
////{
////	char a[32] = "abcdef123456";
////	char b[32];
////	my_memcpy(a,b, strlen(a) + 1);
//	/*my_memove(a+1,a, strlen(a)+1);
//	printf("%s\n", a);*/
//	/*const char *str1 = "abcd123xyz123qwer";
//	const char *str2 = "abcD123xyz123qwer";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);*/
//	system("pause");
//	return 0;
//}
