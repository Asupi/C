#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#pragma warning(disable:4996)
char *my_strstr(const char *str, const char *sub_str)
{
	assert(str);
	assert(sub_str);
	const char *p = str;
	const char *sp = sub_str;
	while (*p){
		p = str;
		sp = sub_str;
		while (*p && *sp && *p == *sp){
			p++, sp++;
		}
		if (*sp == '\0'){
			return str;
		}
		str++;
	}
	return NULL;
}
int main()
{
	const char *str = "abcd123xyz123qwer";
	const char*sub_str = "1234";
	const char *ret =my_strstr(str, sub_str);
	printf("%s\n", ret);

//char *my_strcat(char *dest, const char *src)
//{
//	char *strdest = dest;
//	assert(dest);
//	assert(src);
//
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return strdest;
//}
//int main()
//{
//	const char arr1[20] = "1234xyz";
//	char arr2[]="world";
//	char* ret = my_strcat(arr1, arr2);
//	
//	printf("%s\n", ret);
//char *my_strcpy(char *dst,const char *src)
//{
//	assert(dst);
//	assert(src);
//	char *src_ = src;
//	char *dst_ = dst;
//	while (*dst_ = *src_)
//	{
//		dst_++, src_++;
//	}
	//while (*src_){
	//	*dst_ = *src_;
	//	dst_++, src_++;
	//}
	//*dst_ = *src_;//
//	return dst;
//}
//int main()
//{ 
//	const char *src = "abcd1234xyz";
//	char dst[16];
//	my_strcpy(dst, src);
//	printf("%s\n", dst);
 	/*char str[10] = "abcd";
	memmove(str + 1, str, strlen(str) + 1);*/
	/*int a[] = { 1, 2, 3, 4, 5 };
	int b[10];
	memcpy(b, a, sizeof(a));*/
	/*char msg[] = "hello World";
	int i = 0;
	while (msg[i]){
		if (islower(msg[i])){
			msg[i] = toupper(msg[i]);
		}
		i++;
	}
	printf("%s\n", msg);*/
	/*int i = 0;
	for (; i < 100; i++){
		printf("%d->%s\n",i,strerror(i));
	}*/
	/*char msg[] = "str : : :str:end";
	char *ret = strtok(msg, ":");
	int count = 1;
	while (ret != NULL) {
		printf("%d:%s\n",count++,ret);
		ret = strtok(NULL, ":");
	}*/
	system("pause");
	return 0;
}
