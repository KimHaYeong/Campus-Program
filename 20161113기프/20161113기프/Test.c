//#include<stdio.h> 
//#include<time.h>  // Ÿ�� 
//#include<conio.h> // getch() ���� 
//#include <stdlib.h>  // system() ����ϱ� ���� 
//#include <Windows.h>
//
//
//void TimeView();
//
//void main()
//{
//
//
//	while (1)  // ������ �⵹�� 
//	{
//		Sleep(900);  // ������ �Լ�  0.9 ��    
//		system("cls");    // ȭ�� ���� 
//		TimeView();    // ������Լ� �ð�        
//
//	}
//
//	_getch();
//}
//
//void TimeView()
//{
//	time_t t;
//	time(&t);
//
//	printf("%s", ctime(&t));
//}
#include <stdio.h>
#include <time.h>

char* timeToString(struct tm *t);


int main(void) {
	struct tm *t;
	time_t timer;

	timer = time(NULL);    // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	printf("%s\n", timeToString(t));

	system("pause");
	return 0;

}




char* timeToString(struct tm *t) {
	static char s[20];

	sprintf(s, "%04d-%02d-%02d %02d:%02d:%02d",
		t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
		t->tm_hour, t->tm_min, t->tm_sec
	);

	return s;
}