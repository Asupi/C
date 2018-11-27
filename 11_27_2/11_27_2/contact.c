#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int add_contact(pContact pcon)
{
	if (pcon->count_user == MAX)
	{
		printf("通讯录已满!");
		return -1;
	}
	else{
		printf("请输入姓名：");
		scanf("%s", pcon->people[pcon->count_user].name);
		printf("请输入性别：");
		scanf("%s", pcon->people[pcon->count_user].sex);
		printf("请输入年龄：");
		scanf("%d", &pcon->people[pcon->count_user].age);
		printf("请输入电话：");
		scanf("%s", pcon->people[pcon->count_user].tel);
		printf("请输入地址：");
		scanf("%s", pcon->people[pcon->count_user].add);
		pcon->count_user++;
	}
	return 0;
}
int del_contact(pContact pcon)
{
	int i = 0;
	int rel = search_contact(pcon);
	if (rel != -1)
	{
		for (i = rel; i<pcon->count_user - 1; i++)
		{
			pcon->people[i] = pcon->people[i + 1];
		}
		pcon->count_user--;
		return 1;
	}
	else
	{
		printf("不存在！");
		return -1;
	}
}
int search_contact(pContact pcon)
{
	int i;
	char name[NAME_LIGHT];
	printf("请输入要查找的姓名：");
	scanf("%s", name);
	for (i = 0; i < pcon->count_user; i++)
	{
		if (strcmp(pcon->people[i].name, name) == 0)
		{
			printf("\tname\tsex\tage\ttel\tadd\n");
			printf("%10s", pcon->people[i].name);
			printf("%5s", pcon->people[i].sex);
			printf("%10d", pcon->people[i].age);
			printf("%10s", pcon->people[i].tel);
			printf("%10s\n", pcon->people[i].add);
			return 1;
		}
	}
	return -1;
}
int modify_contact(pContact pcon)
{
	int rel = search_contact(pcon);
	if (rel != -1)
	{
		printf("请输入姓名：");
		scanf("%s", pcon->people[pcon->count_user].name);
		printf("请输入性别：");
		scanf("%s", pcon->people[pcon->count_user].sex);
		printf("请输入年龄：");
		scanf("%d", &pcon->people[pcon->count_user].age);
		printf("请输入电话：");
		scanf("%s", pcon->people[pcon->count_user].tel);
		printf("请输入地址：");
		scanf("%s", pcon->people[pcon->count_user].add);
		return 1;
	}
	else
	{
		printf("输入错误!");
		return -1;
	}
}
int show_contact(pContact pcon)
{
	int i;
	printf("\tname\tsex\tage\ttel\tadd\n");
	for (i = 0; i < pcon->count_user; i++)
	{
		printf("%10s", pcon->people[i].name);
		printf("%5s", pcon->people[i].sex);
		printf("%10d", pcon->people[i].age);
		printf("%10s", pcon->people[i].tel);
		printf("%10s\n", pcon->people[i].add);
	}
	printf("\n");
	return 0;
}
int clear_contact(pContact pcon)
{
	pcon->count_user = 0;
	return 1;
}

