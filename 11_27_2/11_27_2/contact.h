#ifndef CONTACT_H
#define CONTACT_H
#endif
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define NAME_LIGHT 10
#define SEX_LIGHT 4
#define TEL_LIGHT 20
#define ADD_LIGHT 30
#define MAX 1000
struct peopleInfo
{
	char name[NAME_LIGHT];
	char sex[SEX_LIGHT];
	int age;
	char tel[TEL_LIGHT];
	char add[ADD_LIGHT];
};
struct contact
{
	struct peopleInfo people[MAX];
	int count_user;
}; typedef struct contact *pContact;
int add_contact(pContact pcon);
int del_contact(pContact pcon);
int search_contact(pContact pcon);
int modify_contact(pContact pcon);
int show_contact(pContact pcon);
int clear_contact(pContact pcon);

