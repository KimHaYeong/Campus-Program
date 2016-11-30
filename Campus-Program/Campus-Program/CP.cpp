#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#pragma warning (disable:4996)
void User(); //사용자 화면
void User_reserve(); //사용자 구장예약
void User_check(); //사용자 구장예약조회
void User_notify();// 사용자 공지사항
void Manager(); // 관리자 화면
void Manager_check(); //관리자 구장예약조회
void init(); //메모리 할당함수
void Manager_notify(); //관리자 공지사항
UINT __stdcall StartTimer(LPVOID lpVoid);// 스레드 타이머
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
PRO *ch_head = NULL; //사용자 조회에서 쓰일 변수
PRO *add = NULL; //메모리 할당변수 
PRO *head = NULL; // 공지사항에 쓰일 포인터변수
PRO *p = NULL; // 움직일 포인터변수
PRO *follow = NULL; //따라올 포인터변수
PRO *tail = NULL; // 이중연결리스트
PRO *noti = NULL; //공지사항에 쓰일 메모리
int input = 0; // 기능입력값
int choice = 0;//  기능입력값
PRO *move = NULL;//움직일 포인터변수
PRO *link = NULL;//맨 앞을 가르킬 포인터 변수
PRO *rear = NULL;// 꼬리 
char g_print[20];// 구장 이름 출력을 위한 변수
int second = 0;  // 초
int minitue = 0; // 분
int hour = 0;    // 시
char statusOfUse[20]; //사용중 대기중 나타낼 변수
HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
void init()
{
	head = (PRO*)malloc(sizeof(PRO));//머리동적할당
	tail = (PRO*)malloc(sizeof(PRO));//꼬리 동적할당
	head->next = tail;
	tail->prev = head; //두 개의 연결리스트를 만들어줌
}

void main()
{
	unsigned int id;
	(HANDLE)_beginthreadex(0, 0, StartTimer, NULL, 0, &id);

	while (1) {
		system("cls");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                              ┃\n");
		printf("┃                          선문대학교                          ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃                    교내 구장 예약 프로그램                   ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃             1. 관리자 모드        2.사용자 모드              ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃                           0. 종료                            ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
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
			printf("프로그램을 종료합니다.\n");
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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                              ┃\n");
		printf("┃    [1] 구장 예약 현황 조회 및 수정 삭제                      ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [2] 공지 등록 및 관리                                     ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [3] 뒤로가기                                              ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
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
		default: printf("잘못 입력하셨습니다.\n");
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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃    [1] 공지사항 등록                                         ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [2] 공지사항 수정                                         ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [3] 공지사항 목록                                         ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [4] 공지사항 삭제                                         ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [5] 뒤로가기                                              ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			noti = (PRO*)malloc(sizeof(PRO));
			printf("공지사항 제목 : ");
			scanf("%s", &noti->title);
			printf("내용 : ");
			scanf("%s", &noti->content);
			tail->prev->next = noti; //꼬리 바로 전에 새 노드를 추가
			noti->prev = tail->prev; // 새 노드 이전을 꼬리이전으로
			noti->next = tail; // 새 노드 다음은 꼬리
			tail->prev = noti; //꼬리 이전은 새 노드
							   //연결하며 값을 넣어준다.
			continue;
		}
		case 2:
		{
			printf("수정할 공지사항 제목 : ");
			scanf("%s", &del_title);
			if (head == NULL)
			{
				printf("없음.\n");
				Sleep(1000);
				break;
			}
			move = rear = head->next; //포인터 변수에 값을 초기화
			while (move != tail) //노드의 끝이 되기전까지 반복문을 돈다
			{
				if (strcmp(del_title, move->title) == 0) //수정할 공지사항 이름과 비교하여 찾아냄
				{
					printf("수정할 내용 : ");
					scanf("%s", &move->content);
					printf("공지 수정이 완료되었습니다.\n");
					Sleep(1000);
					break;
				}
				move = move->next; //아니면 다음 값으로 넘겨줌
			}
			Sleep(1000);
			break;
			continue;
		}

		case 4:
		{
			PRO *del;
			printf("삭제할 공지사항 제목 : ");
			scanf("%s", &del_title);
			move = head->next; // 초기 포인터 주소값 삽입
			if (head == NULL)
			{
				printf("없음\n");
				Sleep(1000);
				continue;
			}
			while (move != tail)
			{
				if (strcmp(del_title, move->title) == 0) //입력한 값과 맞을 경우 삭제함
				{
					del = move;
					move->prev->next = move->next; //지울노드 뒷노드를 앞 노드와 연결
					move->next->prev = move->prev; //지울노드 앞노드를 뒷노드와 연결
					printf("삭제완료.");
					Sleep(2000);
					break;
				}
			}
			if (move == tail) //만약 
			{
				printf("없음.\n");
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
				printf("없음.\n");
				Sleep(2000);
				continue;
			}
			printf("                      <  공 지 사 항 >                            \n");
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			move = head->next; //포인터 변수 주소값 초기화
			while (move != tail)
			{
				printf(" 공지 : %10s                                              \n", move->title);
				printf(" 내용    : %10s                                               \n", move->content);
				move = move->next;
			}
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			Sleep(2000);
			continue;
		}
		case 5:
			return;
		default:
			printf("잘못입력하셨습니다.\n");
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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                              ┃\n");
		printf("┃    [1] 예약자 정보 조회 및 구장 예약 현황                    ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [2] 구장 예약 삭제                                        ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [3] 뒤로가기                                              ┃\n");
		printf("┃                                                              ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			system("cls");
			printf("                      <  예 약 현 황 >                              \n");
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			for (p = ch_head; p != NULL; p = p->next)
			{
				if (p->Ground == 1) //Ground의 값에 따라 구장 값을 g_print에 복사한다.
					strcpy(g_print, "풋살A");
				else if (p->Ground == 2)
					strcpy(g_print, "풋살B");
				else if (p->Ground == 3)
					strcpy(g_print, "축구장");
				else
					strcpy(g_print, "야구장");
				if (p->StartTime == hour) // 스레드 시간과 예약시간을 비교하여 사용중과 대기중을 표시
				{
					strcpy(statusOfUse, "사용중");
				}
				else if (p->StartTime != hour)
				{
					strcpy(statusOfUse, "대기중");
				}
				printf("이름 : %s  휴대전화 :%s  동아리명 : %s \n  구장정보 : %s  예약시간 : %d,%d  현황 : %s \n", p->Name, p->Phone_num, p->Club, g_print, p->StartTime, p->EndTime, statusOfUse);
			}
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			getchar();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			printf("동아리명 입력 : "); //동명이인이 있을 수 있으므로 동아리명으로 조회
			scanf("%s", &del_re);
			p = follow = ch_head;
			while ((p != NULL) && (strcmp(del_re, p->Club) != 0))
			{
				follow = p;
				p = p->next;
			}
			if (p == NULL)
			{
				printf("없음.\n");
				Sleep(2000);
				break;
			}
			if (ch_head == p) //첫 번째 값을 삭제할 때
				ch_head = p->next;
			else if (p->next == NULL) // 끝 값을 삭제할 때
				follow->next = NULL;
			else //중간 값을 삭제할 때
				follow->next = p->next;
			printf("삭제완료.");
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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                              ┃\n");
		printf("┃    [1] 구장 예약                                             ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [2] 예약 현황                                             ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [3] 공지사항                                              ┃\n");
		printf("┃                                                              ┃\n");
		printf("┃    [4] 뒤로가기                                              ┃\n");
		printf("┃                                                              ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");


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
			printf("잘못 입력하셨습니다.\n");
		}
	}
}

void User_reserve()
{
	add = (PRO*)malloc(sizeof(PRO)); //동적 메모리할당
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃      [1] 풋살 A                          [2] 풋살 B          ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃      [3] 축구장                          [4] 야구장          ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	scanf("%d", &add->Ground);
	getchar();
	system("cls");

	printf("이름 : ");
	scanf("%s", &add->Name);
	printf("전화번호 : ");
	scanf("%s", &add->Phone_num);
	printf("동아리명 : ");
	scanf("%s", &add->Club); //각각의 구장, 이름, 전화번호, 동아리 이름을 입력하여 저장
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                              ┃\n");
	printf("┃     *    사용시간 AM00시 기준 24시로 입력해 주세요     *     ┃\n");
	printf("┃     *            1시간씩 예약 해주세요                 *     ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                                   시                         ┃\n");
	gotoxy(20, 8); printf("시작시간 :  "); scanf("%d", &add->StartTime);
	printf("┃                                                              ┃\n");
	printf("┃                                   시                         ┃\n");
	gotoxy(20, 10); printf("종료시간 :  "); scanf("%d", &add->EndTime); //사용자가 보기 좋도록 위치를 옮김 
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	add->next = NULL;

	getchar();

	if (ch_head == NULL)
		ch_head = add; //노드가 비어있을 경우 맨 앞에 값을 넣어줌.

	else
	{
		p = ch_head;// head가 가르키는 주소값을 p도 동일하게 가르킨다
		while (p->next != NULL)
		{
			if ((add->StartTime == p->StartTime || add->EndTime == p->EndTime) && add->Ground == p->Ground) //구장이 같고 시작시간 또는 마치는 시간이 같을 경우 
			{
				printf("이미 예약된 구장입니다. 다시 예약해주세요.\n");
				getchar();
				User();
			}
			else
				p = p->next; //다음 값으로 움직인다
		}
		p->next = add; //p의 다음 값에 입력 값을 넣어준다.
	}
	printf("예약이 완료되었습니다.\n");
	getchar();
	system("cls");
}

void User_check()
{
	system("cls");
	printf("                      <  예 약 현 황 >                              \n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	for (p = ch_head; p != NULL; p = p->next) //포인터를 맨 앞으로 옮겨 끝이 p가 가르키는 값이 NULL이 아닐 경우 다음 값으로 넘겨준다
	{
		if (p->Ground == 1)
			strcpy(g_print, "풋살A");
		else if (p->Ground == 2)
			strcpy(g_print, "풋살B");
		else if (p->Ground == 3)
			strcpy(g_print, "축구장");
		else
			strcpy(g_print, "야구장");

		if (p->StartTime == hour)  // 스레드 시간과 예약시간을 비교하여 사용중과 대기중을 표시
		{
			strcpy(statusOfUse, "사용중");
		}
		else if (p->StartTime != hour)
		{
			strcpy(statusOfUse, "대기중");
		}
		printf("이름 : %s   동아리명 : %s  구장정보 : %s   예약시간 : %d,%d  현황 : %s \n", p->Name, p->Club, g_print, p->StartTime, p->EndTime, statusOfUse);
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	getchar();

}


void User_notify()
{
	system("cls");
	if (head == NULL)
	{
		printf("없음\n");
		Sleep(1000);
		return;
	}
	move = head->next; //head->next의 주소값을 move포인터에 넣어준다
	printf("                      <  공 지 사 항 >                            \n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	while (move != tail) //move가 가르키는 곳이 tail이 아닐 떄까지
	{
		printf(" 공지 : %10s                                              \n", move->title);
		printf(" 내용    : %10s                                               \n", move->content);
		move = move->next; //다음 값으로 넘겨주며 계속해서 출력한다
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	Sleep(3000);
}
UINT __stdcall StartTimer(LPVOID lpVoid)
{
	// 시스템 시작 시 구동 될 시간함수
	system("title 현재 시간");
	char nowtime[30];
	char *t1 = "시", *t2 = "분", *t3 = "초";
	while (1) {
		Sleep(1000);  // 딜레이 함수  0.1 초
		second++;

		if (second == 60)  // 60초 = 1분
		{
			minitue++;
			second = 0;
		}

		if (minitue == 60) // 60분 = 1시간
		{
			hour++;
			minitue = 0;

		}
		if (hour == 24) return 0;
		sprintf(nowtime, "title 현재 시간 %d%s %d%s %d%s", hour, t1, minitue, t2, second, t3);
		system(nowtime);

	}
}

int gotoxy(int x, int y) //x,y 위치로 draw위치 변경 / 콘솔창에서 보다 정확한 좌표설정을 위해사용
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(x), static_cast<short>(y) };//원하는 콘솔커서의 좌표 (x,y)를 담은 COORD구조체 변수 생성
	SetConsoleCursorPosition(consoleHandler, coords); //매개변수로 받은 콘솔 스크린버퍼와 특정 커서 좌표를 가지고 해당콘솔 스크린 버퍼의 커서좌표를 새 좌표로 바꿔주는 역할

	return 1;
}