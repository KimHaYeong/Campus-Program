#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#pragma warning (disable:4996)
void User(); //����� ȭ��
void User_reserve(); //����� ���忹��
void User_check(); //����� ���忹����ȸ
void User_notify();// ����� ��������
void Manager(); // ������ ȭ��
void Manager_check(); //������ ���忹����ȸ
void init(); //�޸� �Ҵ��Լ�
void Manager_notify(); //������ ��������
UINT __stdcall StartTimer(LPVOID lpVoid);// ������ Ÿ�̸�
int gotoxy(int x, int y);
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
PRO *ch_head = NULL; //����� ��ȸ���� ���� ����
PRO *add = NULL; //�޸� �Ҵ纯�� 
PRO *head = NULL; // �������׿� ���� �����ͺ���
PRO *p = NULL; // ������ �����ͺ���
PRO *follow = NULL; //����� �����ͺ���
PRO *tail = NULL; // ���߿��Ḯ��Ʈ
PRO *noti = NULL; //�������׿� ���� �޸�
int input = 0; // ����Է°�
int choice = 0;//  ����Է°�
PRO *move = NULL;//������ �����ͺ���
PRO *link = NULL;//�� ���� ����ų ������ ����
PRO *rear = NULL;// ���� 
char g_print[20];// ���� �̸� ����� ���� ����
int second = 0;  // ��
int minitue = 0; // ��
int hour = 0;    // ��
char statusOfUse[20]; //����� ����� ��Ÿ�� ����
HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
void init()
{
	head = (PRO*)malloc(sizeof(PRO));//�Ӹ������Ҵ�
	tail = (PRO*)malloc(sizeof(PRO));//���� �����Ҵ�
	head->next = tail;
	tail->prev = head; //�� ���� ���Ḯ��Ʈ�� �������
}

void main()
{
	unsigned int id;
	(HANDLE)_beginthreadex(0, 0, StartTimer, NULL, 0, &id);

	while (1) {
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
		scanf("%d", &choice);
		if (choice == 1)
		{
			Manager(); continue;
		}
		if (choice == 2)
		{
			User(); continue;
		}
		if (choice == 0)
		{
			system("cls");
			printf("���α׷��� �����մϴ�.\n");
			return;
		}
	}
	CloseHandle(StartTimer);
}

void Manager()
{
	while (1)
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
			continue;
		case 2:
			Manager_notify();
			continue;
		case 3:
			return;
		default: printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}
	}
}
void Manager_notify()
{
	system("cls");
	int count = 0;
	char del_title[30];
	init();
	while (1)
	{
		int input = 0;
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
			noti = (PRO*)malloc(sizeof(PRO));
			printf("�������� ���� : ");
			scanf("%s", &noti->title);
			printf("���� : ");
			scanf("%s", &noti->content);
			tail->prev->next = noti; //���� �ٷ� ���� �� ��带 �߰�
			noti->prev = tail->prev; // �� ��� ������ ������������
			noti->next = tail; // �� ��� ������ ����
			tail->prev = noti; //���� ������ �� ���
							   //�����ϸ� ���� �־��ش�.
			continue;
		}
		case 2:
		{
			printf("������ �������� ���� : ");
			scanf("%s", &del_title);
			if (head == NULL)
			{
				printf("����.\n");
				Sleep(1000);
				break;
			}
			move = rear = head->next; //������ ������ ���� �ʱ�ȭ
			while (move != tail) //����� ���� �Ǳ������� �ݺ����� ����
			{
				if (strcmp(del_title, move->title) == 0) //������ �������� �̸��� ���Ͽ� ã�Ƴ�
				{
					printf("������ ���� : ");
					scanf("%s", &move->content);
					printf("���� ������ �Ϸ�Ǿ����ϴ�.\n");
					Sleep(1000);
					break;
				}
				move = move->next; //�ƴϸ� ���� ������ �Ѱ���
			}
			Sleep(1000);
			break;
			continue;
		}

		case 4:
		{
			PRO *del;
			printf("������ �������� ���� : ");
			scanf("%s", &del_title);
			move = head->next; // �ʱ� ������ �ּҰ� ����
			if (head == NULL)
			{
				printf("����\n");
				Sleep(1000);
				continue;
			}
			while (move != tail)
			{
				if (strcmp(del_title, move->title) == 0) //�Է��� ���� ���� ��� ������
				{
					del = move;
					move->prev->next = move->next; //������ �޳�带 �� ���� ����
					move->next->prev = move->prev; //������ �ճ�带 �޳��� ����
					printf("�����Ϸ�.");
					Sleep(2000);
					break;
				}
			}
			if (move == tail) //���� 
			{
				printf("����.\n");
				Sleep(2000);
				continue;
			}
			return;
		}
		case 3:
		{
			system("cls");
			if (head == NULL)
			{
				printf("����.\n");
				Sleep(2000);
				continue;
			}
			printf("                      <  �� �� �� �� >                            \n");
			printf("������������������������������������������������������������������\n");
			move = head->next; //������ ���� �ּҰ� �ʱ�ȭ
			while (move != tail)
			{
				printf(" ���� : %10s                                              \n", move->title);
				printf(" ����    : %10s                                               \n", move->content);
				move = move->next;
			}
			printf("������������������������������������������������������������������\n");
			Sleep(2000);
			continue;
		}
		case 5:
			return;
		default:
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
}
void Manager_check()
{
	while (1)
	{
		system("cls");
		PRO *del = NULL;
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
			for (p = ch_head; p != NULL; p = p->next)
			{
				if (p->Ground == 1) //Ground�� ���� ���� ���� ���� g_print�� �����Ѵ�.
					strcpy(g_print, "ǲ��A");
				else if (p->Ground == 2)
					strcpy(g_print, "ǲ��B");
				else if (p->Ground == 3)
					strcpy(g_print, "�౸��");
				else
					strcpy(g_print, "�߱���");
				if (p->StartTime == hour) // ������ �ð��� ����ð��� ���Ͽ� ����߰� ������� ǥ��
				{
					strcpy(statusOfUse, "�����");
				}
				else if (p->StartTime != hour)
				{
					strcpy(statusOfUse, "�����");
				}
				printf("�̸� : %s  �޴���ȭ :%s  ���Ƹ��� : %s \n  �������� : %s  ����ð� : %d,%d  ��Ȳ : %s \n", p->Name, p->Phone_num, p->Club, g_print, p->StartTime, p->EndTime, statusOfUse);
			}
			printf("������������������������������������������������������������������������\n");
			getchar();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			printf("���Ƹ��� �Է� : "); //���������� ���� �� �����Ƿ� ���Ƹ������� ��ȸ
			scanf("%s", &del_re);
			p = follow = ch_head;
			while ((p != NULL) && (strcmp(del_re, p->Club) != 0))
			{
				follow = p;
				p = p->next;
			}
			if (p == NULL)
			{
				printf("����.\n");
				Sleep(2000);
				break;
			}
			if (ch_head == p) //ù ��° ���� ������ ��
				ch_head = p->next;
			else if (p->next == NULL) // �� ���� ������ ��
				follow->next = NULL;
			else //�߰� ���� ������ ��
				follow->next = p->next;
			printf("�����Ϸ�.");
			Sleep(2000);
			break;

		case 3:
			return;
		}
	}
}



void User()

{
	while (1)
	{
		system("cls");
		int unum = 0;
		printf("������������������������������������������������������������������\n");
		printf("��                                                              ��\n");
		printf("��    [1] ���� ����                                             ��\n");
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
			continue;
		case 2:
			User_check();
			continue;
		case 3:
			User_notify();
			continue;
		case 4:
			return;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}
	}
}

void User_reserve()
{
	add = (PRO*)malloc(sizeof(PRO)); //���� �޸��Ҵ�
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
	scanf("%s", &add->Club); //������ ����, �̸�, ��ȭ��ȣ, ���Ƹ� �̸��� �Է��Ͽ� ����
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��     *    ���ð� AM00�� ���� 24�÷� �Է��� �ּ���     *     ��\n");
	printf("��     *            1�ð��� ���� ���ּ���                 *     ��\n");
	printf("��                                                              ��\n");
	printf("��                                   ��                         ��\n");
	gotoxy(20, 8); printf("���۽ð� :  "); scanf("%d", &add->StartTime);
	printf("��                                                              ��\n");
	printf("��                                   ��                         ��\n");
	gotoxy(20, 10); printf("����ð� :  "); scanf("%d", &add->EndTime); //����ڰ� ���� ������ ��ġ�� �ű� 
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("������������������������������������������������������������������\n");
	add->next = NULL;

	getchar();

	if (ch_head == NULL)
		ch_head = add; //��尡 ������� ��� �� �տ� ���� �־���.

	else
	{
		p = ch_head;// head�� ����Ű�� �ּҰ��� p�� �����ϰ� ����Ų��
		while (p->next != NULL)
		{
			if ((add->StartTime == p->StartTime || add->EndTime == p->EndTime) && add->Ground == p->Ground) //������ ���� ���۽ð� �Ǵ� ��ġ�� �ð��� ���� ��� 
			{
				printf("�̹� ����� �����Դϴ�. �ٽ� �������ּ���.\n");
				getchar();
				User();
			}
			else
				p = p->next; //���� ������ �����δ�
		}
		p->next = add; //p�� ���� ���� �Է� ���� �־��ش�.
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	getchar();
	system("cls");
}

void User_check()
{
	system("cls");
	printf("                      <  �� �� �� Ȳ >                              \n");
	printf("������������������������������������������������������������������\n");
	for (p = ch_head; p != NULL; p = p->next) //�����͸� �� ������ �Ű� ���� p�� ����Ű�� ���� NULL�� �ƴ� ��� ���� ������ �Ѱ��ش�
	{
		if (p->Ground == 1)
			strcpy(g_print, "ǲ��A");
		else if (p->Ground == 2)
			strcpy(g_print, "ǲ��B");
		else if (p->Ground == 3)
			strcpy(g_print, "�౸��");
		else
			strcpy(g_print, "�߱���");

		if (p->StartTime == hour)  // ������ �ð��� ����ð��� ���Ͽ� ����߰� ������� ǥ��
		{
			strcpy(statusOfUse, "�����");
		}
		else if (p->StartTime != hour)
		{
			strcpy(statusOfUse, "�����");
		}
		printf("�̸� : %s   ���Ƹ��� : %s  �������� : %s   ����ð� : %d,%d  ��Ȳ : %s \n", p->Name, p->Club, g_print, p->StartTime, p->EndTime, statusOfUse);
	}
	printf("������������������������������������������������������������������\n");
	getchar();

}


void User_notify()
{
	system("cls");
	if (head == NULL)
	{
		printf("����\n");
		Sleep(1000);
		return;
	}
	move = head->next; //head->next�� �ּҰ��� move�����Ϳ� �־��ش�
	printf("                      <  �� �� �� �� >                            \n");
	printf("������������������������������������������������������������������\n");
	while (move != tail) //move�� ����Ű�� ���� tail�� �ƴ� ������
	{
		printf(" ���� : %10s                                              \n", move->title);
		printf(" ����    : %10s                                               \n", move->content);
		move = move->next; //���� ������ �Ѱ��ָ� ����ؼ� ����Ѵ�
	}
	printf("������������������������������������������������������������������\n");
	Sleep(3000);
}
UINT __stdcall StartTimer(LPVOID lpVoid)
{
	// �ý��� ���� �� ���� �� �ð��Լ�
	system("title ���� �ð�");
	char nowtime[30];
	char *t1 = "��", *t2 = "��", *t3 = "��";
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
		sprintf(nowtime, "title ���� �ð� %d%s %d%s %d%s", hour, t1, minitue, t2, second, t3);
		system(nowtime);

	}
}

int gotoxy(int x, int y) //x,y ��ġ�� draw��ġ ���� / �ܼ�â���� ���� ��Ȯ�� ��ǥ������ ���ػ��
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(x), static_cast<short>(y) };//���ϴ� �ܼ�Ŀ���� ��ǥ (x,y)�� ���� COORD����ü ���� ����
	SetConsoleCursorPosition(consoleHandler, coords); //�Ű������� ���� �ܼ� ��ũ�����ۿ� Ư�� Ŀ�� ��ǥ�� ������ �ش��ܼ� ��ũ�� ������ Ŀ����ǥ�� �� ��ǥ�� �ٲ��ִ� ����

	return 1;
}