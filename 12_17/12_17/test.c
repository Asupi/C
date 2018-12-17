#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int my_strncpy(char *dst, const char *src, size_t num)
{
	assert(src);
	assert(dst);
	char *ret = dst;
	while (num--)
	{
		*dst = *src;
		dst++, src++;

	}
	return ret;
}
int main()
{
	char dst[20] = "abcdefg";
	char src[20] = "1234567";
	printf("%s\n ", my_strncpy, (dst, src, 4));
	return 0;
}
