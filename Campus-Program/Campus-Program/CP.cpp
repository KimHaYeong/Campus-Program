#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#pragma warning (disable:4996)
void User(); //餌辨濠 �飛�
void User_reserve(); //餌辨濠 掘濰蕨擒
void User_check(); //餌辨濠 掘濰蕨擒褻��
void User_notify();// 餌辨濠 奢雖餌о
void Manager(); // 婦葬濠 �飛�
void Manager_check(); //婦葬濠 掘濰蕨擒褻��
void init(); //詭賅葬 й渡л熱
void Manager_notify(); //婦葬濠 奢雖餌о
UINT __stdcall StartTimer(LPVOID lpVoid);// 蝶溯萄 顫檜該
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
PRO *ch_head = NULL; //餌辨濠 褻�蛾□� 噙橾 滲熱
PRO *add = NULL; //詭賅葬 й渡滲熱 
PRO *head = NULL; // 奢雖餌о縑 噙橾 ん檣攪滲熱
PRO *p = NULL; // 遺霜橾 ん檣攪滲熱
PRO *follow = NULL; //評塭螢 ん檣攪滲熱
PRO *tail = NULL; // 檜醞翱唸葬蝶お
PRO *noti = NULL; //奢雖餌о縑 噙橾 詭賅葬
int input = 0; // 晦棟殮溘高
int choice = 0;//  晦棟殮溘高
PRO *move = NULL;//遺霜橾 ん檣攪滲熱
PRO *link = NULL;//裔 擅擊 陛腦鑒 ん檣攪 滲熱
PRO *rear = NULL;// 窒葬 
char g_print[20];// 掘濰 檜葷 轎溘擊 嬪и 滲熱
int second = 0;  // 蟾
int minitue = 0; // 碟
int hour = 0;    // 衛
char statusOfUse[20]; //餌辨醞 渠晦醞 釭顫鳥 滲熱
HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
void init()
{
	head = (PRO*)malloc(sizeof(PRO));//該葬翕瞳й渡
	tail = (PRO*)malloc(sizeof(PRO));//窒葬 翕瞳й渡
	head->next = tail;
	tail->prev = head; //舒 偃曖 翱唸葬蝶お蒂 虜菟橫邀
}

void main()
{
	unsigned int id;
	(HANDLE)_beginthreadex(0, 0, StartTimer, NULL, 0, &id);

	while (1) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                                              早\n");
		printf("早                          摹僥渠з掖                          早\n");
		printf("早                                                              早\n");
		printf("早                    掖頂 掘濰 蕨擒 Щ煎斜極                   早\n");
		printf("早                                                              早\n");
		printf("早             1. 婦葬濠 賅萄        2.餌辨濠 賅萄              早\n");
		printf("早                                                              早\n");
		printf("早                           0. 謙猿                            早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
			printf("Щ煎斜極擊 謙猿м棲棻.\n");
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                                              早\n");
		printf("早    [1] 掘濰 蕨擒 ⑷�� 褻�� 塽 熱薑 餉薯                      早\n");
		printf("早                                                              早\n");
		printf("早    [2] 奢雖 蛔煙 塽 婦葬                                     早\n");
		printf("早                                                              早\n");
		printf("早    [3] 菴煎陛晦                                              早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
		default: printf("澀跤 殮溘ж樟蝗棲棻.\n");
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早    [1] 奢雖餌о 蛔煙                                         早\n");
		printf("早                                                              早\n");
		printf("早    [2] 奢雖餌о 熱薑                                         早\n");
		printf("早                                                              早\n");
		printf("早    [3] 奢雖餌о 跡煙                                         早\n");
		printf("早                                                              早\n");
		printf("早    [4] 奢雖餌о 餉薯                                         早\n");
		printf("早                                                              早\n");
		printf("早    [5] 菴煎陛晦                                              早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			noti = (PRO*)malloc(sizeof(PRO));
			printf("奢雖餌о 薯跡 : ");
			scanf("%s", &noti->title);
			printf("頂辨 : ");
			scanf("%s", &noti->content);
			tail->prev->next = noti; //窒葬 夥煎 瞪縑 億 喻萄蒂 蹺陛
			noti->prev = tail->prev; // 億 喻萄 檜瞪擊 窒葬檜瞪戲煎
			noti->next = tail; // 億 喻萄 棻擠擎 窒葬
			tail->prev = noti; //窒葬 檜瞪擎 億 喻萄
							   //翱唸ж貊 高擊 厥橫遽棻.
			continue;
		}
		case 2:
		{
			printf("熱薑й 奢雖餌о 薯跡 : ");
			scanf("%s", &del_title);
			if (head == NULL)
			{
				printf("橈擠.\n");
				Sleep(1000);
				break;
			}
			move = rear = head->next; //ん檣攪 滲熱縑 高擊 蟾晦��
			while (move != tail) //喻萄曖 部檜 腎晦瞪梱雖 奩犒僥擊 絲棻
			{
				if (strcmp(del_title, move->title) == 0) //熱薑й 奢雖餌о 檜葷婁 綠掖ж罹 瓊嬴鹵
				{
					printf("熱薑й 頂辨 : ");
					scanf("%s", &move->content);
					printf("奢雖 熱薑檜 諫猿腎歷蝗棲棻.\n");
					Sleep(1000);
					break;
				}
				move = move->next; //嬴棲賊 棻擠 高戲煎 剩啖邀
			}
			Sleep(1000);
			break;
			continue;
		}

		case 4:
		{
			PRO *del;
			printf("餉薯й 奢雖餌о 薯跡 : ");
			scanf("%s", &del_title);
			move = head->next; // 蟾晦 ん檣攪 輿模高 鳶殮
			if (head == NULL)
			{
				printf("橈擠\n");
				Sleep(1000);
				continue;
			}
			while (move != tail)
			{
				if (strcmp(del_title, move->title) == 0) //殮溘и 高婁 蜃擊 唳辦 餉薯л
				{
					del = move;
					move->prev->next = move->next; //雖選喻萄 萌喻萄蒂 擅 喻萄諦 翱唸
					move->next->prev = move->prev; //雖選喻萄 擅喻萄蒂 萌喻萄諦 翱唸
					printf("餉薯諫猿.");
					Sleep(2000);
					break;
				}
			}
			if (move == tail) //虜擒 
			{
				printf("橈擠.\n");
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
				printf("橈擠.\n");
				Sleep(2000);
				continue;
			}
			printf("                      <  奢 雖 餌 о >                            \n");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			move = head->next; //ん檣攪 滲熱 輿模高 蟾晦��
			while (move != tail)
			{
				printf(" 奢雖 : %10s                                              \n", move->title);
				printf(" 頂辨    : %10s                                               \n", move->content);
				move = move->next;
			}
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			Sleep(2000);
			continue;
		}
		case 5:
			return;
		default:
			printf("澀跤殮溘ж樟蝗棲棻.\n");
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                                              早\n");
		printf("早    [1] 蕨擒濠 薑爾 褻�� 塽 掘濰 蕨擒 ⑷��                    早\n");
		printf("早                                                              早\n");
		printf("早    [2] 掘濰 蕨擒 餉薯                                        早\n");
		printf("早                                                              早\n");
		printf("早    [3] 菴煎陛晦                                              早\n");
		printf("早                                                              早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			system("cls");
			printf("                      <  蕨 擒 ⑷ �� >                              \n");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			for (p = ch_head; p != NULL; p = p->next)
			{
				if (p->Ground == 1) //Ground曖 高縑 評塭 掘濰 高擊 g_print縑 犒餌и棻.
					strcpy(g_print, "Е髦A");
				else if (p->Ground == 2)
					strcpy(g_print, "Е髦B");
				else if (p->Ground == 3)
					strcpy(g_print, "蹴掘濰");
				else
					strcpy(g_print, "撿掘濰");
				if (p->StartTime == hour) // 蝶溯萄 衛除婁 蕨擒衛除擊 綠掖ж罹 餌辨醞婁 渠晦醞擊 ル衛
				{
					strcpy(statusOfUse, "餌辨醞");
				}
				else if (p->StartTime != hour)
				{
					strcpy(statusOfUse, "渠晦醞");
				}
				printf("檜葷 : %s  �瑒蹀��� :%s  翕嬴葬貲 : %s \n  掘濰薑爾 : %s  蕨擒衛除 : %d,%d  ⑷�� : %s \n", p->Name, p->Phone_num, p->Club, g_print, p->StartTime, p->EndTime, statusOfUse);
			}
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			getchar();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			printf("翕嬴葬貲 殮溘 : "); //翕貲檜檣檜 氈擊 熱 氈戲嘎煎 翕嬴葬貲戲煎 褻��
			scanf("%s", &del_re);
			p = follow = ch_head;
			while ((p != NULL) && (strcmp(del_re, p->Club) != 0))
			{
				follow = p;
				p = p->next;
			}
			if (p == NULL)
			{
				printf("橈擠.\n");
				Sleep(2000);
				break;
			}
			if (ch_head == p) //羅 廓簞 高擊 餉薯й 陽
				ch_head = p->next;
			else if (p->next == NULL) // 部 高擊 餉薯й 陽
				follow->next = NULL;
			else //醞除 高擊 餉薯й 陽
				follow->next = p->next;
			printf("餉薯諫猿.");
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                                              早\n");
		printf("早    [1] 掘濰 蕨擒                                             早\n");
		printf("早                                                              早\n");
		printf("早    [2] 蕨擒 ⑷��                                             早\n");
		printf("早                                                              早\n");
		printf("早    [3] 奢雖餌о                                              早\n");
		printf("早                                                              早\n");
		printf("早    [4] 菴煎陛晦                                              早\n");
		printf("早                                                              早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");


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
			printf("澀跤 殮溘ж樟蝗棲棻.\n");
		}
	}
}

void User_reserve()
{
	add = (PRO*)malloc(sizeof(PRO)); //翕瞳 詭賅葬й渡
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("早      [1] Е髦 A                          [2] Е髦 B          早\n");
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("早      [3] 蹴掘濰                          [4] 撿掘濰          早\n");
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	scanf("%d", &add->Ground);
	getchar();
	system("cls");

	printf("檜葷 : ");
	scanf("%s", &add->Name);
	printf("瞪�食醽� : ");
	scanf("%s", &add->Phone_num);
	printf("翕嬴葬貲 : ");
	scanf("%s", &add->Club); //陝陝曖 掘濰, 檜葷, 瞪�食醽�, 翕嬴葬 檜葷擊 殮溘ж罹 盪濰
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                                              早\n");
	printf("早     *    餌辨衛除 AM00衛 晦遽 24衛煎 殮溘п 輿撮蹂     *     早\n");
	printf("早     *            1衛除噶 蕨擒 п輿撮蹂                 *     早\n");
	printf("早                                                              早\n");
	printf("早                                   衛                         早\n");
	gotoxy(20, 8); printf("衛濛衛除 :  "); scanf("%d", &add->StartTime);
	printf("早                                                              早\n");
	printf("早                                   衛                         早\n");
	gotoxy(20, 10); printf("謙猿衛除 :  "); scanf("%d", &add->EndTime); //餌辨濠陛 爾晦 謠紫煙 嬪纂蒂 衡梯 
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("早                                                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	add->next = NULL;

	getchar();

	if (ch_head == NULL)
		ch_head = add; //喻萄陛 綠橫氈擊 唳辦 裔 擅縑 高擊 厥橫邀.

	else
	{
		p = ch_head;// head陛 陛腦酈朝 輿模高擊 p紫 翕橾ж啪 陛腦鑑棻
		while (p->next != NULL)
		{
			if ((add->StartTime == p->StartTime || add->EndTime == p->EndTime) && add->Ground == p->Ground) //掘濰檜 偽堅 衛濛衛除 傳朝 葆纂朝 衛除檜 偽擊 唳辦 
			{
				printf("檜嘐 蕨擒脹 掘濰殮棲棻. 棻衛 蕨擒п輿撮蹂.\n");
				getchar();
				User();
			}
			else
				p = p->next; //棻擠 高戲煎 遺霜檣棻
		}
		p->next = add; //p曖 棻擠 高縑 殮溘 高擊 厥橫遽棻.
	}
	printf("蕨擒檜 諫猿腎歷蝗棲棻.\n");
	getchar();
	system("cls");
}

void User_check()
{
	system("cls");
	printf("                      <  蕨 擒 ⑷ �� >                              \n");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	for (p = ch_head; p != NULL; p = p->next) //ん檣攪蒂 裔 擅戲煎 衡啖 部檜 p陛 陛腦酈朝 高檜 NULL檜 嬴棍 唳辦 棻擠 高戲煎 剩啖遽棻
	{
		if (p->Ground == 1)
			strcpy(g_print, "Е髦A");
		else if (p->Ground == 2)
			strcpy(g_print, "Е髦B");
		else if (p->Ground == 3)
			strcpy(g_print, "蹴掘濰");
		else
			strcpy(g_print, "撿掘濰");

		if (p->StartTime == hour)  // 蝶溯萄 衛除婁 蕨擒衛除擊 綠掖ж罹 餌辨醞婁 渠晦醞擊 ル衛
		{
			strcpy(statusOfUse, "餌辨醞");
		}
		else if (p->StartTime != hour)
		{
			strcpy(statusOfUse, "渠晦醞");
		}
		printf("檜葷 : %s   翕嬴葬貲 : %s  掘濰薑爾 : %s   蕨擒衛除 : %d,%d  ⑷�� : %s \n", p->Name, p->Club, g_print, p->StartTime, p->EndTime, statusOfUse);
	}
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	getchar();

}


void User_notify()
{
	system("cls");
	if (head == NULL)
	{
		printf("橈擠\n");
		Sleep(1000);
		return;
	}
	move = head->next; //head->next曖 輿模高擊 moveん檣攪縑 厥橫遽棻
	printf("                      <  奢 雖 餌 о >                            \n");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	while (move != tail) //move陛 陛腦酈朝 夠檜 tail檜 嬴棍 ��梱雖
	{
		printf(" 奢雖 : %10s                                              \n", move->title);
		printf(" 頂辨    : %10s                                               \n", move->content);
		move = move->next; //棻擠 高戲煎 剩啖輿貊 啗樓п憮 轎溘и棻
	}
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	Sleep(3000);
}
UINT __stdcall StartTimer(LPVOID lpVoid)
{
	// 衛蝶蠱 衛濛 衛 掘翕 腆 衛除л熱
	system("title ⑷營 衛除");
	char nowtime[30];
	char *t1 = "衛", *t2 = "碟", *t3 = "蟾";
	while (1) {
		Sleep(1000);  // 裁溯檜 л熱  0.1 蟾
		second++;

		if (second == 60)  // 60蟾 = 1碟
		{
			minitue++;
			second = 0;
		}

		if (minitue == 60) // 60碟 = 1衛除
		{
			hour++;
			minitue = 0;

		}
		if (hour == 24) return 0;
		sprintf(nowtime, "title ⑷營 衛除 %d%s %d%s %d%s", hour, t1, minitue, t2, second, t3);
		system(nowtime);

	}
}

int gotoxy(int x, int y) //x,y 嬪纂煎 draw嬪纂 滲唳 / 夔樂璽縑憮 爾棻 薑�旁� 謝ル撲薑擊 嬪п餌辨
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(x), static_cast<short>(y) };//錳ж朝 夔樂醴憮曖 謝ル (x,y)蒂 氬擎 COORD掘褻羹 滲熱 儅撩
	SetConsoleCursorPosition(consoleHandler, coords); //衙偃滲熱煎 嫡擎 夔樂 蝶觼萼幗ぷ諦 か薑 醴憮 謝ル蒂 陛雖堅 п渡夔樂 蝶觼萼 幗ぷ曖 醴憮謝ル蒂 億 謝ル煎 夥脯輿朝 羲й

	return 1;
}