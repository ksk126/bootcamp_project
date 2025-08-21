#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HEAD.h"

int menu(int select)
{
	printf("\n-------------------MENU--------------------\n");
	printf("1. 수입/지출 추가\n");
	printf("2. 수입/지출 수정\n");
	printf("3. 월별 수입/지출 통계\n");
	printf("4. 수입/지출 내역\n");
	printf("-------------------------------------------\n");
	printf("0 입력 시 종료: ");
	if (scanf("%d", &select) != 1)
	{
		select = 0;
	}
	return select;
}