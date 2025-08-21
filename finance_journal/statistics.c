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

	printf("�� ���� ��踦 ���� �Է�: ");
	scanf("%d", &month);

	int count = filterByMonth(filtered, month);

	if (count == 0)
	{
		printf("\n%d���� ������ �����ϴ�.\n", month);
		return;
	}

	//ī�װ� ���
	for (int i = 0; i < count; i++)
	{
		if (filtered[i].pm == '+')
		{
			if (strcmp(filtered[i].type, "����") == 0)
			{
				type.income.fixed++;
			}
			else if (strcmp(filtered[i].type, "����") == 0)
			{
				type.income.variable++;
			}
			else if (strcmp(filtered[i].type, "��Ÿ") == 0)
			{
				type.income.inetc++;
			}
		}
		else
		{
			if (strcmp(filtered[i].type, "��Ȱ��") == 0)
			{
				type.expenses.living++;
			}
			else if (strcmp(filtered[i].type, "����/�ǹ�") == 0)
			{
				type.expenses.finance++;
			}
			else if (strcmp(filtered[i].type, "����/�ڱ���") == 0)
			{
				type.expenses.leisure++;
			}
			else if (strcmp(filtered[i].type, "��Ÿ") == 0)
			{
				type.expenses.exetc++;
			}
		}

	}

	//�� ����
	for (int i = 0; i < count; i++)
	{
		if (filtered[i].pm == '+')
		{
			money.INmoney += filtered[i].money;
		}
	}

	//�� ����
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

	// ������ ���� ū ��
	for (int i = 0; i < count; i++) {
		if (filtered[i].pm == '+') {
			if (filtered[i].money > maxMoney) {
				maxMoney = filtered[i].money;
				a = 0; // ���� ���ŵǾ����Ƿ� �ʱ�ȭ
				maxdate[a++] = filtered[i].date.day;
			}
			else if (filtered[i].money == maxMoney) {
				maxdate[a++] = filtered[i].date.day;
			}
		}
	}
	maxcount = a;

	int minMoney = 99999999; // ����� ū ��
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
	
	printf("------------------%d�� ���--------------------\n", month);
	printf("�� ����: %d\n", money.INmoney);
	printf("�� ����: %d\n", money.EXmoney);
	printf("�� �ܾ�: %d\n", money.INmoney - money.EXmoney);
	printf("\nī�װ� �� ����/����\n");
	printf("����\n");
	printf("��������: %d\n", type.income.fixed);
	printf("��������: %d\n", type.income.variable);
	printf("��Ÿ����: %d\n", type.income.inetc);
	printf("\n����\n");
	printf("��Ȱ��: %d\n", type.expenses.living);
	printf("����/�ǹ�: %d\n", type.expenses.finance);
	printf("����/�ڱ���: %d\n", type.expenses.leisure);
	printf("��Ÿ����: % d\n", type.expenses.exetc);
	printf("\n������ ���� ū ���� ������ %d�̰� ", maxMoney);
	for (int i = 0; i < maxcount; i++)
	{
		printf("%02d/%02d ", month, maxdate[i]);
	}
	printf("���� ������ ���� �ǽ��ϴ�.\n");
	printf("\n������ ���� ū ���� ������ %d�̰� ", minMoney);
	for (int i = 0; i < mincount; i++)
	{
		printf("%02d/%02d ", month, mindate[i]);
	}
	printf("���� ������ ���� �ǽ��ϴ�.\n");
	printf("------------------------------------------------");

	return;
}