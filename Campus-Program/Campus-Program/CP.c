#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning (disable:4996)

typedef struct pro
{
	char Name[20];
	char Phone_num[13];
	char Club[50];
	int Ground;
	int StartTime;
	int EndTime;

	struct pro *next;
}PRO;

PRO *add, *head, *p;
void User();

void User()

{
	int unum = 0;
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��    [1] ���� ���� �� ���                                     ��\n");
	printf("��                                                              ��\n");
	printf("��    [2] ���� ��Ȳ                                             ��\n");
	printf("��                                                              ��\n");
	printf("��    [3] ��������                                              ��\n");
	printf("��                                                              ��\n");
	printf("��    [4] �ڷΰ���                                              ��\n");
	printf("��                                                              ��\n");
	printf("������������������������������������������������������������������\n");


	scanf("%d", &unum);

	//switch (unum)
	//{
	//case 1:
	//	User_reserve(add, head, p);
	//	break;
	//case 2:
	//	User_check(add, head, p);
	//	break;
	//case 3:
	//	User_notify(add, head, p);
	//	break;
	//case 4:
	//	break;
	//default:
	//	printf("�߸� �Է��ϼ̽��ϴ�.\n");
	//}
}


void main()
{


	int n = 0;

	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��                          �������б�                          ��\n");
	printf("��                                                              ��\n");
	printf("��                    ���� ���� ���� ���α׷�                   ��\n");
	printf("��                                                              ��\n");
	printf("��             1. ������ ���        2.����� ���              ��\n");
	printf("��                                                              ��\n");
	printf("��                           0. ����                            ��\n");
	printf("��                                                              ��\n");
	printf("������������������������������������������������������������������\n");
	scanf("%d", &n);

	if (n == 2)
	{
		system("cls");
		User();
	}


}