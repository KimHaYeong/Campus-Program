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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                              ┃\n");
	printf("┃    [1] 구장 예약 및 취소                                     ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃    [2] 예약 현황                                             ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃    [3] 공지사항                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃    [4] 뒤로가기                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");


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
	//	printf("잘못 입력하셨습니다.\n");
	//}
}


void main()
{


	int n = 0;

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                              ┃\n");
	printf("┃                          선문대학교                          ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                    교내 구장 예약 프로그램                   ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃             1. 관리자 모드        2.사용자 모드              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                           0. 종료                            ┃\n");
	printf("┃                                                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	scanf("%d", &n);

	if (n == 2)
	{
		system("cls");
		User();
	}


}