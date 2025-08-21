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
		printf("���� ���� ����\n");
		return add;
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	if (size == 0)
	{
		fprintf(fp, "%s\t%10s\t%10s\t%20s\n", "��¥", "ī�װ�", "�ݾ�", "�޸�\n");
	}

	int answer = 0;

	do
	{
		printf("\n��¥(1�� 1��->1 1 ���� �Է�): ");
		scanf("%d %d", &add.date.month, &add.date.day);

		int type = 0;

		do
		{
			printf("\n����: ����, ����, ��Ÿ\n����: ��Ȱ��, ����/�ǹ�, ����/�ڱ���, ��Ÿ\n�ش�Ǵ� ī�װ� �Է�: ");
			scanf(" %[^\n]", add.type);

			if (strcmp(add.type, "����") == 0 || strcmp(add.type, "����") == 0 ||
				strcmp(add.type, "��Ÿ") == 0 || strcmp(add.type, "��Ȱ��") == 0 ||
				strcmp(add.type, "����/�ǹ�") == 0 || strcmp(add.type, "����/�ڱ���") == 0)
			{
				type = 1;
			}
			else {
				printf("�ùٸ� ī�װ��� �Է��ϼ���.");
				type = 0;
			}


		} while (type == 0);

		int pm = 1;

		do
		{
			printf("\n����/����(����/����->+/- n ���� �Է�): ");
			scanf(" %c %d", &add.pm, &add.money);

			if ((strcmp(add.type, "����") == 0 || strcmp(add.type, "����") || strcmp(add.type, "��Ÿ") == 0) && add.pm == '-')
			{
				printf("����/���� ������ ī�װ��� ��ġ���� �ʽ��ϴ�.\n");
				pm = 0;
			}
			else if ((strcmp(add.type, "��Ȱ��") == 0 || strcmp(add.type, "����/�ǹ�") == 0 ||
				strcmp(add.type, "����/�ڱ���") == 0 || strcmp(add.type, "��Ÿ") == 0) && add.pm == '+')
			{
				printf("����/���� ������ ī�װ��� ��ġ���� �ʽ��ϴ�.\n");
				pm = 0;
			}
			else
			{
				pm = 1;
			}

		} while (pm == 0);
		printf("\n��Ÿ �޸��� �� �Է�: ");
		scanf(" %[^\n]", add.etc);

		printf("\n%s\t%10s\t%10s\t%20s\n", "��¥", "ī�װ�", "�ݾ�", "�޸�");
		printf("\n'%02d/%02d\t%10s\t%10c%d\t%20s'\n��� �����ұ��? (y/n)\n",
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
				printf("�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է��ϼ���.\n");
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