#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "HEAD.h"

void inputRetouch(INCOMEANDEXPENSES add)
{
	INCOMEANDEXPENSES records[MAX_RECORDS];
	int count = saveRecord(records);

	if (count == 0)
	{
		printf("수정할 데이터가 없습니다.\n");
		return;
	}

	int month, day;
	printf("\n수정할 날짜 입력 (월 일): ");
	scanf("%d %d", &month, &day);

	int found[100], fcount = 0;
	for (int i = 0; i < count; i++)
	{
		if (records[i].date.month == month && records[i].date.day == day)
		{
			printf("[%d] %02d/%02d %s %c%d %s\n",
				fcount + 1,
				records[i].date.month, records[i].date.day,
				records[i].type, records[i].pm,
				records[i].money, records[i].etc);
			found[fcount++] = i;
		}
	}

	if (fcount == 0)
	{
		printf("해당 날짜에 데이터가 없습니다.\n");
		return;
	}

	int select;
	printf("수정할 번호 선택: ");
	scanf("%d", &select);

	if (select < 1 || select > fcount)
	{
		printf("잘못된 선택입니다.\n");
		return;
	}

	int idx = found[select - 1];
	printf("(수입: 고정, 변동, 기타)\n(지출: 생활비, 금융/의무, 여가/자기계발, 기타)\n새 카테고리 입력: ");

	int ftype = 0;
	do
	{
		scanf(" %[^\n]", records[idx].type);
		if (strcmp(records[idx].type, "고정") == 0 || strcmp(records[idx].type, "변동") == 0 ||
			strcmp(records[idx].type, "기타") == 0 || strcmp(records[idx].type, "생활비") == 0 ||
			strcmp(records[idx].type, "금융/의무") == 0 || strcmp(records[idx].type, "여가/자기계발") == 0)
		{
			printf("올바른 카테고리를 입력하세요.");
			ftype = 1;
		}
	} while (ftype == 0);

	printf("새 수입/지출(+/- n): ");

	int fpm = 0;
	do
	{
		scanf(" %c %d", &records[idx].pm, &records[idx].money);

		if ((strcmp(records[idx].type, "고정") == 0 || strcmp(records[idx].type, "변동") || strcmp(records[idx].type, "기타") == 0) && records[idx].pm == '-')
		{
			printf("수입/지출 내역이 카테고리와 일치하지 않습니다.\n");
			fpm = 0;
		}
		else if ((strcmp(records[idx].type, "생활비") == 0 || strcmp(records[idx].type, "금융/의무") == 0 ||
			strcmp(records[idx].type, "여가/자기계발") == 0 || strcmp(records[idx].type, "기타") == 0) && records[idx].pm == '+')
		{
			printf("수입/지출 내역이 카테고리와 일치하지 않습니다.\n");
			fpm = 0;
		}
		else
		{
			fpm = 1;
		}
	} while (fpm == 0);
	printf("새 메모 입력: ");
	scanf(" %[^\n]", records[idx].etc);

	FILE* fp;
	fopen_s(&fp, "C:/Users/otter/Desktop/record.txt", "w");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return;
	}

	fprintf(fp, "%s\t%10s\t%10s\t%10s\n", "날짜", "카테고리", "금액", "메모");
	for (int i = 0; i < count; i++)
	{
		fprintf(fp, "%02d/%02d\t%10s\t%10c%d\t%20s\n",
			records[i].date.month, records[i].date.day,
			records[i].type, records[i].pm,
			records[i].money, records[i].etc);
	}
	fclose(fp);

	printf("수정 완료.\n");

	return;
}