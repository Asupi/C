//#define _CRT_SECURE_NO_WARNINGS 1
//struct Stu
//{
//	char name[20];//����
//	int age;//����
//	char sx[5];//�Ա�
//	char id[20];//ѧ��
//};//�ֺŲ��ܶ�
//
//
////�����ṹ������
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], *p;
//
//struct Point
//{
//	int x;
//	int y;
//}p1;//�������͵�ͬʱ�������p1
//struct Point p2;//����ṹ�����p2
//
////��ʼ��
//struct Point p3 = { x, y };
//struct Stu   //��������
//{
//	char name[15];//����
//	int age;//����
//};
//struct Stu s = { "zhangsan",20 }//��ʼ��
//
//struct Node
//{
//	int datd;
//	struct Point p;
//	struct Node*next;
//}n1 = { 10, { 4, 5 }, NULL };//�ṹͷǶ�׳�ʼ��
//n2 = { 20, { 5, 6 }, NULL };//�ṹͷǶ�׳�ʼ��
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int main()
{
	int n;
	struct contact people;
	people.count_user = 0;
	printf("������һ������");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		add_contact(&people);
		break;
	case 2:
		del_contact(&people);
		break;
	case 3:
		search_contact(&people);
		break;
	case 4:
		clear_contact(&people);
		break;
	case 5:
		modify_contact(&people);
		break;
	case 6:
		show_contact(&people);
		break;
	default:
		printf("�������");
		break;
	}
	return 0;
}
