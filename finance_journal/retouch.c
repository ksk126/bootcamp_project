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
		printf("������ �����Ͱ� �����ϴ�.\n");
		return;
	}

	int month, day;
	printf("\n������ ��¥ �Է� (�� ��): ");
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
		printf("�ش� ��¥�� �����Ͱ� �����ϴ�.\n");
		return;
	}

	int select;
	printf("������ ��ȣ ����: ");
	scanf("%d", &select);

	if (select < 1 || select > fcount)
	{
		printf("�߸��� �����Դϴ�.\n");
		return;
	}

	int idx = found[select - 1];
	printf("(����: ����, ����, ��Ÿ)\n(����: ��Ȱ��, ����/�ǹ�, ����/�ڱ���, ��Ÿ)\n�� ī�װ� �Է�: ");

	int ftype = 0;
	do
	{
		scanf(" %[^\n]", records[idx].type);
		if (strcmp(records[idx].type, "����") == 0 || strcmp(records[idx].type, "����") == 0 ||
			strcmp(records[idx].type, "��Ÿ") == 0 || strcmp(records[idx].type, "��Ȱ��") == 0 ||
			strcmp(records[idx].type, "����/�ǹ�") == 0 || strcmp(records[idx].type, "����/�ڱ���") == 0)
		{
			printf("�ùٸ� ī�װ��� �Է��ϼ���.");
			ftype = 1;
		}
	} while (ftype == 0);

	printf("�� ����/����(+/- n): ");

	int fpm = 0;
	do
	{
		scanf(" %c %d", &records[idx].pm, &records[idx].money);

		if ((strcmp(records[idx].type, "����") == 0 || strcmp(records[idx].type, "����") || strcmp(records[idx].type, "��Ÿ") == 0) && records[idx].pm == '-')
		{
			printf("����/���� ������ ī�װ��� ��ġ���� �ʽ��ϴ�.\n");
			fpm = 0;
		}
		else if ((strcmp(records[idx].type, "��Ȱ��") == 0 || strcmp(records[idx].type, "����/�ǹ�") == 0 ||
			strcmp(records[idx].type, "����/�ڱ���") == 0 || strcmp(records[idx].type, "��Ÿ") == 0) && records[idx].pm == '+')
		{
			printf("����/���� ������ ī�װ��� ��ġ���� �ʽ��ϴ�.\n");
			fpm = 0;
		}
		else
		{
			fpm = 1;
		}
	} while (fpm == 0);
	printf("�� �޸� �Է�: ");
	scanf(" %[^\n]", records[idx].etc);

	FILE* fp;
	fopen_s(&fp, "C:/Users/otter/Desktop/record.txt", "w");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		return;
	}

	fprintf(fp, "%s\t%10s\t%10s\t%10s\n", "��¥", "ī�װ�", "�ݾ�", "�޸�");
	for (int i = 0; i < count; i++)
	{
		fprintf(fp, "%02d/%02d\t%10s\t%10c%d\t%20s\n",
			records[i].date.month, records[i].date.day,
			records[i].type, records[i].pm,
			records[i].money, records[i].etc);
	}
	fclose(fp);

	printf("���� �Ϸ�.\n");

	return;
}