//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <process.h>
//
//#pragma warning (disable:4996)
//
//void User(); //餌辨濠 �飛�
//void User_reserve(); //餌辨濠 掘濰蕨擒
//void User_check(); //餌辨濠 掘濰蕨擒褻��
//				   //void User_notify(); //餌辨濠 奢雖餌о
//void Manager(); // 婦葬濠 �飛�
//void Manager_check(); //婦葬濠 掘濰蕨擒褻��
//void init();                 //void Manager_User_check();
//void Manager_notify(); //婦葬濠 奢雖餌о
//int gotoxy(int x, int y);
//UINT __stdcall StartTimer(LPVOID lpVoid);
//
//typedef struct pro
//{
//	char Name[20];
//	char Phone_num[13];
//	char Club[50];
//	int Ground;
//	int StartTime;
//	int EndTime;
//	char content[200];
//	char title[30];
//	struct pro *next;
//	struct pro *prev;
//}PRO;
//PRO *add = NULL;
//PRO *head = NULL;
//PRO *p = NULL;
//PRO *follow = NULL;
//PRO *tail = NULL;
//PRO *noti = NULL;
//char g_print[20];
//
//void init()
//{
//	head = (PRO*)malloc(sizeof(PRO));//衛濛
//	tail = (PRO*)malloc(sizeof(PRO));//葆雖虞
//	head->next = tail;
//	tail->prev = head;
//}
//
//int second = 0;  // 蟾
//int minitue = 0; // 碟
//int hour = 0;    // 衛
//HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
//
//void main()
//{
//	unsigned int id;
//	(HANDLE)_beginthreadex(0, 0, StartTimer, NULL, 0, &id);
//
//	while (1) {
//
//		int choice = 0;
//
//		system("cls");
//		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//		printf("早                                                              早\n");
//		printf("早                          摹僥渠з掖                          早\n");
//		printf("早                                                              早\n");
//		printf("早                    掖頂 掘濰 蕨擒 Щ煎斜極                   早\n");
//		printf("早                                                              早\n");
//		printf("早             1. 婦葬濠 賅萄        2.餌辨濠 賅萄              早\n");
//		printf("早                                                              早\n");
//		printf("早                           0. 謙猿                            早\n");
//		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//
//		scanf("%d", &choice);
//
//		if (choice == 1)
//		{
//			Manager(); continue;
//		}
//		if (choice == 2)
//		{
//
//			User(); continue;
//		}
//		if (choice == 0)
//		{
//			system("cls");
//			printf("Щ煎斜極擊 謙猿м棲棻.\n");
//			return;
//		}
//	}
//	CloseHandle(StartTimer);
//}
//
//void Manager()
//{
//	while (1)
//	{
//		system("cls");
//		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//		printf("早                                                              早\n");
//		printf("早    [1] 掘濰 蕨擒 ⑷�� 褻�� 塽 熱薑 餉薯                      早\n");
//		printf("早                                                              早\n");
//		printf("早    [2] 奢雖 蛔煙 塽 婦葬                                     早\n");
//		printf("早                                                              早\n");
//		printf("早    [3] 菴煎陛晦                                              早\n");
//		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//
//		int input = 0;
//		scanf(" %d", &input);
//		switch (input)
//		{
//		case 1:
//			Manager_check();
//			continue;
//		case 2:
//			Manager_notify();
//			continue;
//		case 3:
//			return;
//		default: printf("澀跤殮溘ж樟蝗棲棻.\n");
//		}
//	}
//
//}
//void Manager_notify()
//{
//	system("cls");
//	int count = 0;
//	PRO *move = NULL;//遺霜橾 ん檣攪滲熱
//	PRO *link = NULL;//裔 擅擊 陛腦鑒 ん檣攪 滲熱
//	PRO *rear = NULL;//菴評塭螢 ん檣攪滲熱
//	char del_title[30];
//	while (1)
//	{
//		system("cls");
//		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//		printf("早    [1] 奢雖餌о 蛔煙                                         早\n");
//		printf("早                                                              早\n");
//		printf("早    [2] 奢雖餌о 熱薑                                         早\n");
//		printf("早                                                              早\n");
//		printf("早    [3] 奢雖餌о 跡煙                                         早\n");
//		printf("早                                                              早\n");
//		printf("早    [4] 奢雖餌о 餉薯                                         早\n");
//		printf("早                                                              早\n");
//		printf("早    [5] 菴煎陛晦                                              早\n");
//		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//
//		int input = 0;
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//		{
//			init();
//			noti = (PRO*)malloc(sizeof(PRO));
//			printf("奢雖餌о 薯跡 : ");
//			scanf("%s", &noti->title);
//			printf("頂辨 : ");
//			scanf("%s", &noti->content);
//			tail->prev->next = noti; //裔 菴縑 noti翱唸
//			noti->prev = tail->prev;
//
//			noti->next = tail;
//			tail->prev = noti;
//
//			continue;
//		}
//		case 2:
//		{
//			printf("熱薑й 奢雖餌о 薯跡 : ");
//			scanf("%s", &del_title);
//			move = rear = link;
//			while (move != NULL)
//			{
//				if (strcmp(del_title, move->title) == 0)
//				{
//					printf("熱薑й 頂辨 : ");
//					scanf("%s", &move->content);
//					printf("奢雖 熱薑檜 諫猿腎歷蝗棲棻.\n");
//					continue;
//				}
//				else
//				{
//					printf("橈擠.\n");
//					move = move->next;
//				}
//			}
//			continue;
//		}
//
//		case 4:
//		{
//			PRO *del;
//			printf("餉薯й 奢雖餌о 薯跡 : ");
//			scanf("%s", &del_title);
//			move = head->next;
//			while (move != NULL)
//			{
//				if (strcmp(del_title, move->title) == 0)
//				{
//					del = move;
//					move->prev->next = move->next;
//					move->next->prev = move->prev;
//					free(del);
//					printf("餉薯諫猿.");
//					Sleep(2000);
//					continue;
//				}
//			}
//			if (move == NULL)
//			{
//				printf("橈擠.\n");
//				Sleep(2000);
//				continue;
//			}
//			if (link == move) //羅 廓簞 高擊 餉薯й 陽
//				link = move->next;
//			else if (move->next == NULL) // 部 高擊 餉薯й 陽
//				rear->next = NULL;
//			else //醞除 高擊 餉薯й 陽
//				rear->next = move->next;
//
//			continue;
//		}
//		case 3:
//		{
//			system("cls");
//			printf("                      <  奢 雖 餌 о >                            \n");
//			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//			move = head->next;
//			while (move != tail)
//			{
//				printf(" 奢雖 : %10s                                              \n", move->title);
//				printf(" 頂辨    : %10s                                               \n", move->content);
//				move = move->next;
//			}
//			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//			Sleep(2000);
//			continue;
//		}
//		case 5:
//			return;
//		default:
//			printf("澀跤殮溘ж樟蝗棲棻.\n");
//			break;
//		}
//	}
//}
//void Manager_check()
//{
//	while (1)
//	{
//		int input = 0;
//
//		system("cls");
//
//		char del_re[30];
//		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//		printf("早                                                              早\n");
//		printf("早    [1] 蕨擒濠 薑爾 褻�� 塽 掘濰 蕨擒 ⑷��                    早\n");
//		printf("早                                                              早\n");
//		printf("早    [2] 掘濰 蕨擒 餉薯                                        早\n");
//		printf("早                                                              早\n");
//		printf("早    [3] 菴煎陛晦                                              早\n");
//		printf("早                                                              早\n");
//		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			system("cls");
//			printf("                      <  蕨 擒 ⑷ �� >                              \n");
//			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//			for (p = head; p != NULL; p = p->next)
//			{
//				if (p->Ground == 1)
//					strcpy(g_print, "Е髦A");
//				else if (p->Ground == 2)
//					strcpy(g_print, "Е髦B");
//				else if (p->Ground == 3)
//					strcpy(g_print, "蹴掘濰");
//				else
//					strcpy(g_print, "撿掘濰");
//				printf("檜葷 : %s  �瑒蹀��� :%s  翕嬴葬貲 : %s \n  掘濰薑爾 : %s  蕨擒衛除 : %d,%d \n", p->Name, p->Phone_num, p->Club, g_print, p->StartTime, p->EndTime);
//			}
//			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//			getchar();
//			system("pause");
//			system("cls");
//			break;
//		case 2:
//			system("cls");
//			printf("翕嬴葬貲 殮溘 : "); //翕貲檜檣檜 氈擊 熱 氈戲嘎煎 翕嬴葬貲戲煎 褻��
//			scanf("%s", &del_re);
//			p = follow = head; //裔 擅戲煎 ん檣攪 滲熱蒂 遺霜檣棻.
//			while ((p != NULL) && (strcmp(del_re, p->title) != 0))
//			{
//				follow = p;
//				p = p->next;
//			}
//			if (p == NULL)
//			{
//				printf("薑爾 橈擠.\n");
//				getchar();
//				break;
//			}
//			if (head == p) //羅 廓簞 高擊 餉薯й 陽
//				head = p->next;
//			else if (p->next == NULL) // 部 高擊 餉薯й 陽
//				follow->next = NULL;
//			else //醞除 高擊 餉薯й 陽
//				follow->next = p->next;
//			printf("餉薯 諫猿.");
//			getchar();
//			break;
//		case 3:
//			return;
//		}
//	}
//}
//
//void User()
//
//{
//	while (1)
//	{
//
//		system("cls");
//		int unum = 0;
//		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//		printf("早                                                              早\n");
//		printf("早    [1] 掘濰 蕨擒 塽 鏃模                                     早\n");
//		printf("早                                                              早\n");
//		printf("早    [2] 蕨擒 ⑷��                                             早\n");
//		printf("早                                                              早\n");
//		printf("早    [3] 奢雖餌о                                              早\n");
//		printf("早                                                              早\n");
//		printf("早    [4] 菴煎陛晦                                              早\n");
//		printf("早                                                              早\n");
//		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//
//
//		scanf("%d", &unum);
//		getchar();
//		system("cls");
//		switch (unum)
//		{
//		case 1:
//			User_reserve();
//			continue;
//		case 2:
//			User_check();
//			continue;
//		case 3:
//			Manager_notify();
//			continue;
//		case 4:
//			return;
//		default:
//			printf("澀跤 殮溘ж樟蝗棲棻.\n");
//		}
//	}
//}
//
//void User_reserve()
//{
//	add = (PRO*)malloc(sizeof(PRO));
//	system("cls");
//	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("早      [1] Е髦 A                          [2] Е髦 B          早\n");
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("早      [3] 蹴掘濰                          [4] 撿掘濰          早\n");
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//
//	scanf("%d", &add->Ground);
//	getchar();
//	system("cls");
//
//	printf("檜葷 : ");
//	scanf("%s", &add->Name);
//	printf("瞪�食醽� : ");
//	scanf("%s", &add->Phone_num);
//	printf("翕嬴葬貲 : ");
//	scanf("%s", &add->Club);
//	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//	printf("早                                                              早\n");
//	printf("早     *    餌辨衛除 AM00衛 晦遽 24衛煎 殮溘п 輿撮蹂     *     早\n");
//	printf("早     *            1衛除噶 蕨擒 п輿撮蹂                 *     早\n");
//	printf("早                                                              早\n");
//	printf("早                                   衛                         早\n");
//	gotoxy(20, 8); printf("衛濛衛除 :  "); scanf("%d", &add->StartTime);
//	printf("早                                                              早\n");
//	printf("早                                   衛                         早\n");
//	gotoxy(20, 10); printf("謙猿衛除 :  "); scanf("%d", &add->EndTime);
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("早                                                              早\n");
//	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//	add->next = NULL;
//
//	getchar();
//
//	if (head == NULL)
//		head = add;// 虜擒 head高檜 NULL高橾 陽 裔 擅縑 高擊 厥橫遽棻
//				   //else if()
//				   //{
//				   //   餌辨濠陛 殮溘и 蕨擒 衛除 薑爾 醞犒腎朝雖 �挫�.
//				   //}
//	else
//	{
//		p = head;// head陛 陛腦酈朝 輿模高擊 p紫 翕橾ж啪 陛腦鑑棻
//		while (p->next != NULL)
//		{
//			if ((add->StartTime == p->StartTime || add->EndTime == p->EndTime) && add->Ground == p->Ground)
//			{
//				printf("檜嘐 蕨擒脹 掘濰殮棲棻. 棻衛 蕨擒п輿撮蹂.\n");
//				getchar();
//				User();
//			}
//			else
//				p = p->next;
//		}
//		p->next = add;
//	}
//	printf("蕨擒檜 諫猿腎歷蝗棲棻.\n");
//	getchar(); //�飛橉� 梟荻�� 雖辦晦 瞪 餌辨濠縑啪 2蟾除 爾罹韓熱 氈紫煙 裁溯檜 и棻.
//	system("cls");
//
//}
//
//void User_check()
//{
//	system("cls");
//	printf("                      <  蕨 擒 ⑷ �� >                              \n");
//	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
//	for (p = head; p != NULL; p = p->next)
//	{
//		if (p->Ground == 1)
//			strcpy(g_print, "Е髦A");
//		else if (p->Ground == 2)
//			strcpy(g_print, "Е髦B");
//		else if (p->Ground == 3)
//			strcpy(g_print, "蹴掘濰");
//		else
//			strcpy(g_print, "撿掘濰");
//		printf("檜葷 : %s   翕嬴葬貲 : %s  掘濰薑爾 : %s   蕨擒衛除 : %d,%d\n", p->Name, p->Club, g_print, p->StartTime, p->EndTime);
//	}
//	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
//	getchar(); //�飛橉� 梟荻�� 雖辦晦 瞪 餌辨濠縑啪 3蟾除 爾罹韓熱 氈紫煙 裁溯檜 и棻.
//
//}
//UINT __stdcall StartTimer(LPVOID lpVoid)
//{
//	// 衛蝶蠱 衛濛 衛 掘翕 腆 衛除л熱
//	system("title ⑷營 衛除");
//	char nowtime[30];
//	char *t1 = "衛", *t2 = "碟", *t3 = "蟾";
//	while (1) {
//		Sleep(1000);  // 裁溯檜 л熱  0.1 蟾
//		second++;
//
//		if (second == 60)  // 60蟾 = 1碟
//		{
//			minitue++;
//			second = 0;
//		}
//
//		if (minitue == 60) // 60碟 = 1衛除
//		{
//			hour++;
//			minitue = 0;
//
//		}
//		if (hour == 24) return 0;
//		sprintf(nowtime, "title ⑷營 衛除 %d%s %d%s %d%s", hour, t1, minitue, t2, second, t3);
//		system(nowtime);
//
//	}
//}
//
//int gotoxy(int x, int y) //x,y 嬪纂煎 draw嬪纂 滲唳
//{
//	if (consoleHandler == INVALID_HANDLE_VALUE)
//		return 0;
//
//	COORD coords = { static_cast<short>(x), static_cast<short>(y) };
//	SetConsoleCursorPosition(consoleHandler, coords);
//
//	return 1;
//}
//
//
////void User_notify()
////{
////   PRO *move = NULL;//遺霜橾 ん檣攪滲熱
////   PRO *link = NULL;//裔 擅擊 陛腦鑒 ん檣攪 滲熱
////   PRO *rear = NULL;//菴評塭螢 ん檣攪滲熱
////   system("cls");
////   printf("                      <  奢 雖 餌 о >                            \n");
////   printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
////   for (move = link; move != NULL; move = move->next)
////   {
////      printf(" 奢雖 : %10s                                              \n", move->title);
////      printf(" 頂辨    : %10s                                               \n", move->content);
////   }
////   printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
////   Sleep(3000);
////   User();
////}