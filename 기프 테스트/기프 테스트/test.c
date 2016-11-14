#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#pragma warning (disable:4996)
void User(); //����� ȭ��
void User_reserve(); //����� ���忹��
void User_check(); //����� ���忹����ȸ
				   //void User_notify(); //����� ��������
void Manager(); // ������ ȭ��
void Manager_check(); //������ ���忹����ȸ
void init();                 //void Manager_User_check();
void Manager_notify(); //������ ��������
UINT __stdcall StartTimer(LPVOID lpVoid);

typedef struct pro
{
	char Name[20];
	char Phone_num[13];
	char Club[50];
	int Ground;
	int StartTime;
	int EndTime;
	char content[200];
	char title[30];
	struct pro *next;
	struct pro *prev;
}PRO;

PRO *add = NULL;
PRO *head = NULL;
PRO *p = NULL;
PRO *follow = NULL;
PRO *tail = NULL;
PRO *noti = NULL;
int input = 0;
int choice = 0;
char g_print[20];

void init()
{
	head = (PRO*)malloc(sizeof(PRO));//����
	tail = (PRO*)malloc(sizeof(PRO));//������
	head->next = tail;
	tail->prev = head;
}

int second = 0;  // ��
int minitue = 0; // ��
int hour = 0;    // ��

void main()
{
	unsigned int id;
	(HANDLE)_beginthreadex(0, 0, StartTimer, NULL, 0, &id);

	system("cls");
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
	while (1) {
		scanf("%d", &choice);
		if (choice == 1)
		{
			Manager();
		}
		if (choice == 2)
		{
			User();
		}
		if (choice == 0)
		{
			system("cls");
			printf("���α׷��� �����մϴ�.\n");
		}
	}
	CloseHandle(StartTimer);
}

void Manager()
{
	system("cls");
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��    [1] ���� ���� ��Ȳ ��ȸ �� ���� ����                      ��\n");
	printf("��                                                              ��\n");
	printf("��    [2] ���� ��� �� ����                                     ��\n");
	printf("��                                                              ��\n");
	printf("��    [3] �ڷΰ���                                              ��\n");
	printf("������������������������������������������������������������������\n");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		Manager_check();
		break;
	case 2:
		Manager_notify();
		break;
	case 3:
		main();
		break;
	}

}
void Manager_notify()
{
	system("cls");
	int count = 0;
	PRO *move = NULL;//������ �����ͺ���
	PRO *link = NULL;//�� ���� ����ų ������ ����
	PRO *rear = NULL;//�ڵ���� �����ͺ���
	char del_title[30];
	while (1)
	{

		system("cls");
		printf("������������������������������������������������������������������\n");
		printf("��    [1] �������� ���                                         ��\n");
		printf("��                                                              ��\n");
		printf("��    [2] �������� ����                                         ��\n");
		printf("��                                                              ��\n");
		printf("��    [3] �������� ���                                         ��\n");
		printf("��                                                              ��\n");
		printf("��    [4] �������� ����                                         ��\n");
		printf("��                                                              ��\n");
		printf("��    [5] �ڷΰ���                                              ��\n");
		printf("������������������������������������������������������������������\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			init();
			noti = (PRO*)malloc(sizeof(PRO));
			printf("�������� ���� : ");
			scanf("%s", &noti->title);
			printf("���� : ");
			scanf("%s", &noti->content);
			tail->prev->next = noti; //�� �ڿ� noti����
			noti->prev = tail->prev;

			noti->next = tail;
			tail->prev = noti;

			break;
		}
		case 2:
		{
			printf("������ �������� ���� : ");
			scanf("%s", &del_title);
			move = rear = link;
			while (move != NULL)
			{
				if (strcmp(del_title, move->title) == 0)
				{
					printf("������ ���� : ");
					scanf("%s", &move->content);
					printf("���� ������ �Ϸ�Ǿ����ϴ�.\n");
					break;
				}
				printf("����.\n");
				move = move->next;
			}
			break;
		}

		case 4:
		{
			PRO *del;
			printf("������ �������� ���� : ");
			scanf("%s", &del_title);
			move = head->next;
			while (move != NULL)
			{
				if (strcmp(del_title, move->title) == 0)
				{
					del = move;
					move->prev->next = move->next;
					move->next->prev = move->prev;
					free(del);
					printf("�����Ϸ�.");
					Sleep(2000);
					break;
				}
			}
			if (move == NULL)
			{
				printf("����.\n");
				Sleep(2000);
				break;
			}
			if (link == move) //ù ��° ���� ������ ��
				link = move->next;
			else if (move->next == NULL) // �� ���� ������ ��
				rear->next = NULL;
			else //�߰� ���� ������ ��
				rear->next = move->next;

			break;
		}
		case 3:
		{
			system("cls");
			printf("                      <  �� �� �� �� >                            \n");
			printf("������������������������������������������������������������������\n");
			move = head->next;
			while (move != tail)
			{
				printf(" ���� : %10s                                              \n", move->title);
				printf(" ����    : %10s                                               \n", move->content);
				move = move->next;
			}
			printf("������������������������������������������������������������������\n");
			Sleep(2000);
			break;
		}
		case 5:
			Manager();
			break;
		default:
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
}
void Manager_check()
{
	system("cls");

	char del_re[30];
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��    [1] ������ ���� ��ȸ �� ���� ���� ��Ȳ                    ��\n");
	printf("��                                                              ��\n");
	printf("��    [2] ���� ���� ����                                        ��\n");
	printf("��                                                              ��\n");
	printf("��    [3] �ڷΰ���                                              ��\n");
	printf("��                                                              ��\n");
	printf("������������������������������������������������������������������\n");

	scanf("%d", &input);

	switch (input)
	{
	case 1:
		system("cls");
		printf("                      <  �� �� �� Ȳ >                              \n");
		printf("������������������������������������������������������������������������\n");
		for (p = head; p != NULL; p = p->next)
		{
			if (p->Ground == 1)
				strcpy(g_print, "ǲ��A");
			else if (p->Ground == 2)
				strcpy(g_print, "ǲ��B");
			else if (p->Ground == 3)
				strcpy(g_print, "�౸��");
			else
				strcpy(g_print, "�߱���");
			printf("�̸� : %s  �޴���ȭ :%s  ���Ƹ��� : %s \n  �������� : %s  ����ð� : %d,%d \n", p->Name, p->Phone_num, p->Club, g_print, p->StartTime, p->EndTime);
		}
		printf("��������������������������������������������������������������������\n");
		getchar();
		system("cls");
		break;
	case 2:
		system("cls");
		printf("���Ƹ��� �Է� : "); //���������� ���� �� �����Ƿ� ���Ƹ������� ��ȸ
		scanf("%s", &del_re);
		p = follow = head; //�� ������ ������ ������ �����δ�.
		while ((p != NULL) && (strcmp(del_re, p->title) != 0))
		{
			follow = p;
			p = p->next;
		}
		if (p == NULL)
		{
			printf("���� ����.\n");
			getchar();
			break;
		}
		if (head == p) //ù ��° ���� ������ ��
			head = p->next;
		else if (p->next == NULL) // �� ���� ������ ��
			follow->next = NULL;
		else //�߰� ���� ������ ��
			follow->next = p->next;
		printf("���� �Ϸ�.");
		getchar();
		break;
	case 3:
		Manager_check();
		break;
	}
}

void User()

{
	system("cls");
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
	getchar();
	system("cls");
	switch (unum)
	{
	case 1:
		User_reserve();
		break;
	case 2:
		User_check();
		break;
	case 3:
		Manager_notify();
		break;
	case 4:
		main();
		break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
}

void User_reserve()
{
	add = (PRO*)malloc(sizeof(PRO));
	system("cls");
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��      [1] ǲ�� A                          [2] ǲ�� B          ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��      [3] �౸��                          [4] �߱���          ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("������������������������������������������������������������������\n");

	scanf("%d", &add->Ground);
	getchar();
	system("cls");

	printf("�̸� : ");
	scanf("%s", &add->Name);
	printf("��ȭ��ȣ : ");
	scanf("%s", &add->Phone_num);
	printf("���Ƹ��� : ");
	scanf("%s", &add->Club);
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��     *    ���ð� AM00�� ���� 24�÷� �Է��� �ּ���     *     ��\n");
	printf("��     *            1�ð��� ���� ���ּ���                 *     ��\n");
	printf("��                                                              ��\n");
	printf("      ���۽ð� :  "); scanf("%d", &add->StartTime); printf("�� \n");
	printf("��                                                              ��\n");
	printf("      ����ð� :  "); scanf("%d", &add->EndTime); printf("�� \n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("������������������������������������������������������������������\n");
	add->next = NULL;

	getchar();

	if (head == NULL)
		head = add;// ���� head���� NULL���� �� �� �տ� ���� �־��ش�
				   //else if()
				   //{
				   //   ����ڰ� �Է��� ���� �ð� ���� �ߺ��Ǵ��� Ȯ��.
				   //}
	else
	{
		p = head;// head�� ����Ű�� �ּҰ��� p�� �����ϰ� ����Ų��
		while (p->next != NULL)
		{
			if ((add->StartTime == p->StartTime || add->EndTime == p->EndTime) && add->Ground == p->Ground)
			{
				printf("�̹� ����� �����Դϴ�. �ٽ� �������ּ���.\n");
				getchar();
				User();
			}
			else
				p = p->next;
		}
		p->next = add;
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	getchar(); //ȭ���� ������ ����� �� ����ڿ��� 2�ʰ� �������� �ֵ��� ������ �Ѵ�.
	system("cls");
	User();

}

void User_check()
{
	system("cls");
	printf("                      <  �� �� �� Ȳ >                              \n");
	printf("������������������������������������������������������������������\n");
	for (p = head; p != NULL; p = p->next)
	{
		if (p->Ground == 1)
			strcpy(g_print, "ǲ��A");
		else if (p->Ground == 2)
			strcpy(g_print, "ǲ��B");
		else if (p->Ground == 3)
			strcpy(g_print, "�౸��");
		else
			strcpy(g_print, "�߱���");
		printf("�̸� : %s   ���Ƹ��� : %s  �������� : %s   ����ð� : %d,%d\n", p->Name, p->Club, g_print, p->StartTime, p->EndTime);
	}
	printf("������������������������������������������������������������������\n");
	getchar(); //ȭ���� ������ ����� �� ����ڿ��� 3�ʰ� �������� �ֵ��� ������ �Ѵ�.
	User();

}
UINT __stdcall StartTimer(LPVOID lpVoid)
{
	// �ý��� ���� �� ���� �� �ð��Լ�

	while (1) {

		Sleep(1000);  // ������ �Լ�  0.1 ��
		second++;

		if (second == 60)  // 60�� = 1��
		{
			minitue++;
			second = 0;
		}

		if (minitue == 60) // 60�� = 1�ð�
		{
			hour++;
			minitue = 0;

		}
		if (hour == 24) return 0;
		printf("���� �ð� : %d�� %d�� %d��\n", hour, minitue, second);
	}
}
//void User_notify()
//{
//   PRO *move = NULL;//������ �����ͺ���
//   PRO *link = NULL;//�� ���� ����ų ������ ����
//   PRO *rear = NULL;//�ڵ���� �����ͺ���
//   system("cls");
//   printf("                      <  �� �� �� �� >                            \n");
//   printf("������������������������������������������������������������������\n");
//   for (move = link; move != NULL; move = move->next)
//   {
//      printf(" ���� : %10s                                              \n", move->title);
//      printf(" ����    : %10s                                               \n", move->content);
//   }
//   printf("������������������������������������������������������������������\n");
//   Sleep(3000);
//   User();
//}