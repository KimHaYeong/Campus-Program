//#include<stdio.h> 
//#include<time.h>  // 타임 
//#include<conio.h> // getch() 위해 
//#include <stdlib.h>  // system() 사용하기 위해 
//#include <Windows.h>
//
//
//void TimeView();
//
//void main()
//{
//
//
//	while (1)  // 무제한 멤돌이 
//	{
//		Sleep(900);  // 딜레이 함수  0.9 초    
//		system("cls");    // 화면 삭제 
//		TimeView();    // 사용자함수 시간        
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

	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

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