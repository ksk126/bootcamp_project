#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HEAD.h"

int main()
{
	ADD add = { 0 };
	int select = 123;

	while (select)
	{
		select = menu(select);

		switch (select)
		{
		case 1:
			inputAdd(add);
			break;
		case 2:
			statistics();
			break;
		}

	}
	return 0;
}

int menu(int select)
{

	printf("-------------------MENU--------------------\n");
	printf("1. 수입/지출 추가\n");
	printf("2. 월별 수입/지출 통계\n");
	printf("-------------------------------------------\n");
	printf("0 입력 시 종료: ");
	if (scanf("%d", &select) != 1) {
		select = 0;
	}

	return select;
}

ADD inputAdd(ADD add)
{
	return add;
}

void statistics()
{
	return;
}

/*
1.메뉴 만들기
1) 날짜 수입/지출 추가(어디다 썼는지) 2) 월 수입과 지출 계산해서 통계 출력

2. 1번 입력받는 함수 날짜 분류 +/- 돈 자세하게


*/
