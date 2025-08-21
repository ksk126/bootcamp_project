#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "HEAD.h"

INCOMEANDEXPENSES inputAdd(INCOMEANDEXPENSES add)
{
	FILE* fp;
	fopen_s(&fp, "C:/Users/otter/Desktop/record.txt", "a");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return add;
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	if (size == 0)
	{
		fprintf(fp, "%s\t%10s\t%10s\t%20s\n", "날짜", "카테고리", "금액", "메모\n");
	}

	int answer = 0;

	do
	{
		printf("\n날짜(1월 1일->1 1 으로 입력): ");
		scanf("%d %d", &add.date.month, &add.date.day);

		int type = 0;

		do
		{
			printf("\n수입: 고정, 변동, 기타\n지출: 생활비, 금융/의무, 여가/자기계발, 기타\n해당되는 카테고리 입력: ");
			scanf(" %[^\n]", add.type);

			if (strcmp(add.type, "고정") == 0 || strcmp(add.type, "변동") == 0 ||
				strcmp(add.type, "기타") == 0 || strcmp(add.type, "생활비") == 0 ||
				strcmp(add.type, "금융/의무") == 0 || strcmp(add.type, "여가/자기계발") == 0)
			{
				type = 1;
			}
			else {
				printf("올바른 카테고리를 입력하세요.");
				type = 0;
			}


		} while (type == 0);

		int pm = 1;

		do
		{
			printf("\n수입/지출(수입/지출->+/- n 으로 입력): ");
			scanf(" %c %d", &add.pm, &add.money);

			if ((strcmp(add.type, "고정") == 0 || strcmp(add.type, "변동") || strcmp(add.type, "기타") == 0) && add.pm == '-')
			{
				printf("수입/지출 내역이 카테고리와 일치하지 않습니다.\n");
				pm = 0;
			}
			else if ((strcmp(add.type, "생활비") == 0 || strcmp(add.type, "금융/의무") == 0 ||
				strcmp(add.type, "여가/자기계발") == 0 || strcmp(add.type, "기타") == 0) && add.pm == '+')
			{
				printf("수입/지출 내역이 카테고리와 일치하지 않습니다.\n");
				pm = 0;
			}
			else
			{
				pm = 1;
			}

		} while (pm == 0);
		printf("\n기타 메모할 것 입력: ");
		scanf(" %[^\n]", add.etc);

		printf("\n%s\t%10s\t%10s\t%20s\n", "날짜", "카테고리", "금액", "메모");
		printf("\n'%02d/%02d\t%10s\t%10c%d\t%20s'\n라고 저장할까요? (y/n)\n",
			add.date.month, add.date.day, add.type, add.pm, add.money, add.etc);
		do
		{
			answer = _getch();
			if (answer == 'Y' || answer == 'y')
			{
				answer = 1;
				break;
			}
			else if (answer != 'N' && answer != 'n')
			{
				printf("올바른 입력이 아닙니다. 다시 입력하세요.\n");
			}
			else
			{
				answer = 0;
				break;
			}
		} while (1);
	} while (answer == 0);

	fprintf(fp, "%02d/%02d\t%10s\t%10c%d\t%20s\n",
		add.date.month, add.date.day, add.type, add.pm, add.money, add.etc);

	fclose(fp);
	return add;
}