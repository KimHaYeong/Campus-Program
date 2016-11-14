#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#pragma warning (disable:4996)
void User(); //»ç¿ëÀÚ È­¸é
void User_reserve(); //»ç¿ëÀÚ ±¸Àå¿¹¾à
void User_check(); //»ç¿ëÀÚ ±¸Àå¿¹¾àÁ¶È¸
				   //void User_notify(); //»ç¿ëÀÚ °øÁö»çÇ×
void Manager(); // °ü¸®ÀÚ È­¸é
void Manager_check(); //°ü¸®ÀÚ ±¸Àå¿¹¾àÁ¶È¸
void init();                 //void Manager_User_check();
void Manager_notify(); //°ü¸®ÀÚ °øÁö»çÇ×
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
	head = (PRO*)malloc(sizeof(PRO));//½ÃÀÛ
	tail = (PRO*)malloc(sizeof(PRO));//¸¶Áö¸·
	head->next = tail;
	tail->prev = head;
}

int second = 0;  // ÃÊ
int minitue = 0; // ºÐ
int hour = 0;    // ½Ã

void main()
{
	unsigned int id;
	(HANDLE)_beginthreadex(0, 0, StartTimer, NULL, 0, &id);

	system("cls");
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                          ¼±¹®´ëÇÐ±³                          ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                    ±³³» ±¸Àå ¿¹¾à ÇÁ·Î±×·¥                   ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­             1. °ü¸®ÀÚ ¸ðµå        2.»ç¿ëÀÚ ¸ðµå              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                           0. Á¾·á                            ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
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
			printf("ÇÁ·Î±×·¥À» Á¾·áÇÕ´Ï´Ù.\n");
		}
	}
	CloseHandle(StartTimer);
}

void Manager()
{
	system("cls");
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [1] ±¸Àå ¿¹¾à ÇöÈ² Á¶È¸ ¹× ¼öÁ¤ »èÁ¦                      ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [2] °øÁö µî·Ï ¹× °ü¸®                                     ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [3] µÚ·Î°¡±â                                              ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
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
	PRO *move = NULL;//¿òÁ÷ÀÏ Æ÷ÀÎÅÍº¯¼ö
	PRO *link = NULL;//¸Ç ¾ÕÀ» °¡¸£Å³ Æ÷ÀÎÅÍ º¯¼ö
	PRO *rear = NULL;//µÚµû¶ó¿Ã Æ÷ÀÎÅÍº¯¼ö
	char del_title[30];
	while (1)
	{

		system("cls");
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("¦­    [1] °øÁö»çÇ× µî·Ï                                         ¦­\n");
		printf("¦­                                                              ¦­\n");
		printf("¦­    [2] °øÁö»çÇ× ¼öÁ¤                                         ¦­\n");
		printf("¦­                                                              ¦­\n");
		printf("¦­    [3] °øÁö»çÇ× ¸ñ·Ï                                         ¦­\n");
		printf("¦­                                                              ¦­\n");
		printf("¦­    [4] °øÁö»çÇ× »èÁ¦                                         ¦­\n");
		printf("¦­                                                              ¦­\n");
		printf("¦­    [5] µÚ·Î°¡±â                                              ¦­\n");
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			init();
			noti = (PRO*)malloc(sizeof(PRO));
			printf("°øÁö»çÇ× Á¦¸ñ : ");
			scanf("%s", &noti->title);
			printf("³»¿ë : ");
			scanf("%s", &noti->content);
			tail->prev->next = noti; //¸Ç µÚ¿¡ noti¿¬°á
			noti->prev = tail->prev;

			noti->next = tail;
			tail->prev = noti;

			break;
		}
		case 2:
		{
			printf("¼öÁ¤ÇÒ °øÁö»çÇ× Á¦¸ñ : ");
			scanf("%s", &del_title);
			move = rear = link;
			while (move != NULL)
			{
				if (strcmp(del_title, move->title) == 0)
				{
					printf("¼öÁ¤ÇÒ ³»¿ë : ");
					scanf("%s", &move->content);
					printf("°øÁö ¼öÁ¤ÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù.\n");
					break;
				}
				printf("¾øÀ½.\n");
				move = move->next;
			}
			break;
		}

		case 4:
		{
			PRO *del;
			printf("»èÁ¦ÇÒ °øÁö»çÇ× Á¦¸ñ : ");
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
					printf("»èÁ¦¿Ï·á.");
					Sleep(2000);
					break;
				}
			}
			if (move == NULL)
			{
				printf("¾øÀ½.\n");
				Sleep(2000);
				break;
			}
			if (link == move) //Ã¹ ¹øÂ° °ªÀ» »èÁ¦ÇÒ ¶§
				link = move->next;
			else if (move->next == NULL) // ³¡ °ªÀ» »èÁ¦ÇÒ ¶§
				rear->next = NULL;
			else //Áß°£ °ªÀ» »èÁ¦ÇÒ ¶§
				rear->next = move->next;

			break;
		}
		case 3:
		{
			system("cls");
			printf("                      <  °ø Áö »ç Ç× >                            \n");
			printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
			move = head->next;
			while (move != tail)
			{
				printf(" °øÁö : %10s                                              \n", move->title);
				printf(" ³»¿ë    : %10s                                               \n", move->content);
				move = move->next;
			}
			printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
			Sleep(2000);
			break;
		}
		case 5:
			Manager();
			break;
		default:
			printf("Àß¸øÀÔ·ÂÇÏ¼Ì½À´Ï´Ù.\n");
			break;
		}
	}
}
void Manager_check()
{
	system("cls");

	char del_re[30];
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [1] ¿¹¾àÀÚ Á¤º¸ Á¶È¸ ¹× ±¸Àå ¿¹¾à ÇöÈ²                    ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [2] ±¸Àå ¿¹¾à »èÁ¦                                        ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [3] µÚ·Î°¡±â                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");

	scanf("%d", &input);

	switch (input)
	{
	case 1:
		system("cls");
		printf("                      <  ¿¹ ¾à Çö È² >                              \n");
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		for (p = head; p != NULL; p = p->next)
		{
			if (p->Ground == 1)
				strcpy(g_print, "Ç²»ìA");
			else if (p->Ground == 2)
				strcpy(g_print, "Ç²»ìB");
			else if (p->Ground == 3)
				strcpy(g_print, "Ãà±¸Àå");
			else
				strcpy(g_print, "¾ß±¸Àå");
			printf("ÀÌ¸§ : %s  ÈÞ´ëÀüÈ­ :%s  µ¿¾Æ¸®¸í : %s \n  ±¸ÀåÁ¤º¸ : %s  ¿¹¾à½Ã°£ : %d,%d \n", p->Name, p->Phone_num, p->Club, g_print, p->StartTime, p->EndTime);
		}
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
		getchar();
		system("cls");
		break;
	case 2:
		system("cls");
		printf("µ¿¾Æ¸®¸í ÀÔ·Â : "); //µ¿¸íÀÌÀÎÀÌ ÀÖÀ» ¼ö ÀÖÀ¸¹Ç·Î µ¿¾Æ¸®¸íÀ¸·Î Á¶È¸
		scanf("%s", &del_re);
		p = follow = head; //¸Ç ¾ÕÀ¸·Î Æ÷ÀÎÅÍ º¯¼ö¸¦ ¿òÁ÷ÀÎ´Ù.
		while ((p != NULL) && (strcmp(del_re, p->title) != 0))
		{
			follow = p;
			p = p->next;
		}
		if (p == NULL)
		{
			printf("Á¤º¸ ¾øÀ½.\n");
			getchar();
			break;
		}
		if (head == p) //Ã¹ ¹øÂ° °ªÀ» »èÁ¦ÇÒ ¶§
			head = p->next;
		else if (p->next == NULL) // ³¡ °ªÀ» »èÁ¦ÇÒ ¶§
			follow->next = NULL;
		else //Áß°£ °ªÀ» »èÁ¦ÇÒ ¶§
			follow->next = p->next;
		printf("»èÁ¦ ¿Ï·á.");
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
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [1] ±¸Àå ¿¹¾à ¹× Ãë¼Ò                                     ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [2] ¿¹¾à ÇöÈ²                                             ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [3] °øÁö»çÇ×                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­    [4] µÚ·Î°¡±â                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");


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
		printf("Àß¸ø ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù.\n");
	}
}

void User_reserve()
{
	add = (PRO*)malloc(sizeof(PRO));
	system("cls");
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­      [1] Ç²»ì A                          [2] Ç²»ì B          ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­      [3] Ãà±¸Àå                          [4] ¾ß±¸Àå          ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");

	scanf("%d", &add->Ground);
	getchar();
	system("cls");

	printf("ÀÌ¸§ : ");
	scanf("%s", &add->Name);
	printf("ÀüÈ­¹øÈ£ : ");
	scanf("%s", &add->Phone_num);
	printf("µ¿¾Æ¸®¸í : ");
	scanf("%s", &add->Club);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­     *    »ç¿ë½Ã°£ AM00½Ã ±âÁØ 24½Ã·Î ÀÔ·ÂÇØ ÁÖ¼¼¿ä     *     ¦­\n");
	printf("¦­     *            1½Ã°£¾¿ ¿¹¾à ÇØÁÖ¼¼¿ä                 *     ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("      ½ÃÀÛ½Ã°£ :  "); scanf("%d", &add->StartTime); printf("½Ã \n");
	printf("¦­                                                              ¦­\n");
	printf("      Á¾·á½Ã°£ :  "); scanf("%d", &add->EndTime); printf("½Ã \n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦­                                                              ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
	add->next = NULL;

	getchar();

	if (head == NULL)
		head = add;// ¸¸¾à head°ªÀÌ NULL°ªÀÏ ¶§ ¸Ç ¾Õ¿¡ °ªÀ» ³Ö¾îÁØ´Ù
				   //else if()
				   //{
				   //   »ç¿ëÀÚ°¡ ÀÔ·ÂÇÑ ¿¹¾à ½Ã°£ Á¤º¸ Áßº¹µÇ´ÂÁö È®ÀÎ.
				   //}
	else
	{
		p = head;// head°¡ °¡¸£Å°´Â ÁÖ¼Ò°ªÀ» pµµ µ¿ÀÏÇÏ°Ô °¡¸£Å²´Ù
		while (p->next != NULL)
		{
			if ((add->StartTime == p->StartTime || add->EndTime == p->EndTime) && add->Ground == p->Ground)
			{
				printf("ÀÌ¹Ì ¿¹¾àµÈ ±¸ÀåÀÔ´Ï´Ù. ´Ù½Ã ¿¹¾àÇØÁÖ¼¼¿ä.\n");
				getchar();
				User();
			}
			else
				p = p->next;
		}
		p->next = add;
	}
	printf("¿¹¾àÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù.\n");
	getchar(); //È­¸éÀ» ±ú²ýÈ÷ Áö¿ì±â Àü »ç¿ëÀÚ¿¡°Ô 2ÃÊ°£ º¸¿©Áú¼ö ÀÖµµ·Ï µô·¹ÀÌ ÇÑ´Ù.
	system("cls");
	User();

}

void User_check()
{
	system("cls");
	printf("                      <  ¿¹ ¾à Çö È² >                              \n");
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	for (p = head; p != NULL; p = p->next)
	{
		if (p->Ground == 1)
			strcpy(g_print, "Ç²»ìA");
		else if (p->Ground == 2)
			strcpy(g_print, "Ç²»ìB");
		else if (p->Ground == 3)
			strcpy(g_print, "Ãà±¸Àå");
		else
			strcpy(g_print, "¾ß±¸Àå");
		printf("ÀÌ¸§ : %s   µ¿¾Æ¸®¸í : %s  ±¸ÀåÁ¤º¸ : %s   ¿¹¾à½Ã°£ : %d,%d\n", p->Name, p->Club, g_print, p->StartTime, p->EndTime);
	}
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
	getchar(); //È­¸éÀ» ±ú²ýÈ÷ Áö¿ì±â Àü »ç¿ëÀÚ¿¡°Ô 3ÃÊ°£ º¸¿©Áú¼ö ÀÖµµ·Ï µô·¹ÀÌ ÇÑ´Ù.
	User();

}
UINT __stdcall StartTimer(LPVOID lpVoid)
{
	// ½Ã½ºÅÛ ½ÃÀÛ ½Ã ±¸µ¿ µÉ ½Ã°£ÇÔ¼ö

	while (1) {

		Sleep(1000);  // µô·¹ÀÌ ÇÔ¼ö  0.1 ÃÊ
		second++;

		if (second == 60)  // 60ÃÊ = 1ºÐ
		{
			minitue++;
			second = 0;
		}

		if (minitue == 60) // 60ºÐ = 1½Ã°£
		{
			hour++;
			minitue = 0;

		}
		if (hour == 24) return 0;
		printf("ÇöÀç ½Ã°£ : %d½Ã %dºÐ %dÃÊ\n", hour, minitue, second);
	}
}
//void User_notify()
//{
//   PRO *move = NULL;//¿òÁ÷ÀÏ Æ÷ÀÎÅÍº¯¼ö
//   PRO *link = NULL;//¸Ç ¾ÕÀ» °¡¸£Å³ Æ÷ÀÎÅÍ º¯¼ö
//   PRO *rear = NULL;//µÚµû¶ó¿Ã Æ÷ÀÎÅÍº¯¼ö
//   system("cls");
//   printf("                      <  °ø Áö »ç Ç× >                            \n");
//   printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
//   for (move = link; move != NULL; move = move->next)
//   {
//      printf(" °øÁö : %10s                                              \n", move->title);
//      printf(" ³»¿ë    : %10s                                               \n", move->content);
//   }
//   printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
//   Sleep(3000);
//   User();
//}