#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
char User(PRO *add, PRO *head, PRO *p);
char User_reserve(PRO *add, PRO *head, PRO *p);
char User_check(PRO *add, PRO *head, PRO *p);
char User_notify(PRO *add, PRO *head, PRO *p);
//char Manager(PRO *add, PRO *head, PRO *p);
//char Manager_check(PRO *add, PRO *head, PRO *p);
//char Manager_notify(PRO *add, PRO *head, PRO *p);

typedef struct pro
{
	int std_num;
	char Phone_num[13];
	char name[20];
	char group[50];
	struct pro *next;
}PRO;
void main()
{
	PRO *add;
	PRO *head;
	PRO *p;
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
	printf("������������������������������������������������������������������\n");
	scanf("%d", &n);
	if (n == 1)
	{
		User(add, head, p);
	}
}

char User(PRO *add, PRO *head, PRO *p)

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
	printf("������������������������������������������������������������������\n");

	scanf("%d", &unum);

	switch (unum)
	{
	case 1:
		User_reserve(add, head, p);
		break;
	case 2:
		User_check(add, head, p);
		break;
	case 3:
		User_notify(add, head, p);
		break;
	case 4:
		break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
}

char User_reserve(PRO *add, PRO *head, PRO *p)
{
	add = (PRO*)malloc(sizeof(PRO));
	printf("�̸� : ");
	scanf("%s", &add->name);
	printf("�й� : ");
	scanf("%s", &add->std_num);
	printf("��ȭ��ȣ : ");
	scanf("%d", &add->Phone_num);
	printf("���Ƹ��� : ");
	scanf("%s", &add->group);
	printf("������������������������������������������������������������������\n");
	printf("��[1]7:00 ~                                                     ��\n");
	printf("��    [1] ���� ���� �� ���                                     ��\n");
	printf("��                                                              ��\n");
	printf("��    [2] ���� ��Ȳ                                             ��\n");
	printf("��                                                              ��\n");
	printf("��    [3] ��������                                              ��\n");
	printf("��                                                              ��\n");
	printf("��    [4] �ڷΰ���                                              ��\n");
	printf("������������������������������������������������������������������\n");
	add->next = NULL;
	if (head == NULL)
		head = add;// ���� head���� NULL���� �� �� �տ� ���� �־��ش�
				   //else if()
				   //{
				   //	����ڰ� �Է��� ���� �ð� ���� �ߺ��Ǵ��� Ȯ��.
				   //}
	else
	{
		p = head;// head�� ����Ű�� �ּҰ��� p�� �����ϰ� ����Ų��
		while (p->next != NULL)
			p = p->next;
		p->next = add;//p�� ���� ���� NULL���� �ƴ� �� ���� �޸𸮷� �Ű� lib�� ����Ű�� ���� �־��ش�
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	Sleep(2000); //ȭ���� ������ ����� �� ����ڿ��� 2�ʰ� �������� �ֵ��� ������ �Ѵ�.

}
//
//char Manager(PRO *add, PRO *head,PRO *p)
//{
//	������ ȭ�� ��� �� ����
//}

char User_check(PRO *add, PRO *head, PRO *p)
{
	printf("                      <  �� �� �� Ȳ >                              ");
	printf("������������������������������������������������������������������\n");
	for (p = head; p != NULL; p = p->next)
	{
		printf("���̸� : %s           ���Ƹ��� : %s        ����ð� : %s        ��\n");
	}
	printf("������������������������������������������������������������������\n");
}