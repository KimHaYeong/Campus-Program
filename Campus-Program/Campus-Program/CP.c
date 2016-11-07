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
	scanf("%d", &n);
	if (n == 1)
	{
		User(add, head, p);
	}
}

char User(PRO *add, PRO *head, PRO *p)

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
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

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
		printf("잘못 입력하셨습니다.\n");
	}
}

char User_reserve(PRO *add, PRO *head, PRO *p)
{
	add = (PRO*)malloc(sizeof(PRO));
	printf("이름 : ");
	scanf("%s", &add->name);
	printf("학번 : ");
	scanf("%s", &add->std_num);
	printf("전화번호 : ");
	scanf("%d", &add->Phone_num);
	printf("동아리명 : ");
	scanf("%s", &add->group);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃[1]7:00 ~                                                     ┃\n");
	printf("┃    [1] 구장 예약 및 취소                                     ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃    [2] 예약 현황                                             ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃    [3] 공지사항                                              ┃\n");
	printf("┃                                                              ┃\n");
	printf("┃    [4] 뒤로가기                                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	add->next = NULL;
	if (head == NULL)
		head = add;// 만약 head값이 NULL값일 때 맨 앞에 값을 넣어준다
				   //else if()
				   //{
				   //	사용자가 입력한 예약 시간 정보 중복되는지 확인.
				   //}
	else
	{
		p = head;// head가 가르키는 주소값을 p도 동일하게 가르킨다
		while (p->next != NULL)
			p = p->next;
		p->next = add;//p의 다음 값이 NULL값이 아닐 때 다음 메모리로 옮겨 lib가 가르키는 값을 넣어준다
	}
	printf("예약이 완료되었습니다.\n");
	Sleep(2000); //화면을 깨끗히 지우기 전 사용자에게 2초간 보여질수 있도록 딜레이 한다.

}
//
//char Manager(PRO *add, PRO *head,PRO *p)
//{
//	관리자 화면 출력 후 선택
//}

char User_check(PRO *add, PRO *head, PRO *p)
{
	printf("                      <  예 약 현 황 >                              ");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	for (p = head; p != NULL; p = p->next)
	{
		printf("┃이름 : %s           동아리명 : %s        예약시간 : %s        ┃\n");
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}