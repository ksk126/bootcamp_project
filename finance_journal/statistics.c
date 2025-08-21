#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "HEAD.h"

void statistics(INCOMEANDEXPENSES add)
{
	INCOMEANDEXPENSES filtered[MAX_RECORDS] = { 0 };
	CATEGORY type = { 0 };
	MONEY money = { 0 };
	int maxdate[31] = { 0 };
	int mindate[31] = { 0 };
	int month = 0;

	printf("몇 월의 통계를 볼지 입력: ");
	scanf("%d", &month);

	int count = filterByMonth(filtered, month);

	if (count == 0)
	{
		printf("\n%d월의 내역이 없습니다.\n", month);
		return;
	}

	//카테고리 통계
	for (int i = 0; i < count; i++)
	{
		if (filtered[i].pm == '+')
		{
			if (strcmp(filtered[i].type, "고정") == 0)
			{
				type.income.fixed++;
			}
			else if (strcmp(filtered[i].type, "수입") == 0)
			{
				type.income.variable++;
			}
			else if (strcmp(filtered[i].type, "기타") == 0)
			{
				type.income.inetc++;
			}
		}
		else
		{
			if (strcmp(filtered[i].type, "생활비") == 0)
			{
				type.expenses.living++;
			}
			else if (strcmp(filtered[i].type, "금융/의무") == 0)
			{
				type.expenses.finance++;
			}
			else if (strcmp(filtered[i].type, "여가/자기계발") == 0)
			{
				type.expenses.leisure++;
			}
			else if (strcmp(filtered[i].type, "기타") == 0)
			{
				type.expenses.exetc++;
			}
		}

	}

	//총 수입
	for (int i = 0; i < count; i++)
	{
		if (filtered[i].pm == '+')
		{
			money.INmoney += filtered[i].money;
		}
	}

	//총 지출
	for (int i = 0; i < count; i++)
	{
		if (filtered[i].pm == '-')
		{
			money.EXmoney += filtered[i].money;
		}
	}

	int maxMoney = 0;
	int a = 0;
	int maxcount = 0;

	// 수입이 제일 큰 날
	for (int i = 0; i < count; i++) {
		if (filtered[i].pm == '+') {
			if (filtered[i].money > maxMoney) {
				maxMoney = filtered[i].money;
				a = 0; // 새로 갱신되었으므로 초기화
				maxdate[a++] = filtered[i].date.day;
			}
			else if (filtered[i].money == maxMoney) {
				maxdate[a++] = filtered[i].date.day;
			}
		}
	}
	maxcount = a;

	int minMoney = 99999999; // 충분히 큰 값
	int b = 0;
	int mincount = 0;

	for (int i = 0; i < count; i++) {
		if (filtered[i].pm == '-') {
			if (filtered[i].money < minMoney) {
				minMoney = filtered[i].money;
				b = 0;
				mindate[b++] = filtered[i].date.day;
			}
			else if (filtered[i].money == minMoney) {
				mindate[b++] = filtered[i].date.day;
			}
		}
	}
	mincount = b;
	
	printf("------------------%d월 통계--------------------\n", month);
	printf("총 수입: %d\n", money.INmoney);
	printf("총 지출: %d\n", money.EXmoney);
	printf("총 잔액: %d\n", money.INmoney - money.EXmoney);
	printf("\n카테고리 별 수입/지출\n");
	printf("수입\n");
	printf("고정수입: %d\n", type.income.fixed);
	printf("변동수입: %d\n", type.income.variable);
	printf("기타수입: %d\n", type.income.inetc);
	printf("\n지출\n");
	printf("생활비: %d\n", type.expenses.living);
	printf("금융/의무: %d\n", type.expenses.finance);
	printf("여가/자기계발: %d\n", type.expenses.leisure);
	printf("기타지출: % d\n", type.expenses.exetc);
	printf("\n수입이 가장 큰 날의 수입은 %d이고 ", maxMoney);
	for (int i = 0; i < maxcount; i++)
	{
		printf("%02d/%02d ", month, maxdate[i]);
	}
	printf("날에 수입이 가장 컸습니다.\n");
	printf("\n지출이 가장 큰 날의 지출은 %d이고 ", minMoney);
	for (int i = 0; i < mincount; i++)
	{
		printf("%02d/%02d ", month, mindate[i]);
	}
	printf("날에 지출이 가장 컸습니다.\n");
	printf("------------------------------------------------");

	return;
}