#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "HEAD.h"

int main()
{
	run();

	return 0;
}

void run()
{
	ADD add = { 0 };
	int select = 0;

	while (1)
	{
		select = menu(select);

		switch (select)
		{
		case 1:
			inputAdd(add);
			break;
		case 2:
			inputRetouch(add);
			break;
		case 3:
			statistics(add);
			break;
		case 4:
			checkRecord(add);
			break;
		default:
			return 0;
		}
	}
	
	return;
}

int menu(int select)
{
	printf("\n-------------------MENU--------------------\n");
	printf("1. ����/���� �߰�\n");
	printf("2. ����/���� ����\n");
	printf("3. ���� ����/���� ���\n");
	printf("4. ����/���� ����\n");
	printf("-------------------------------------------\n");
	printf("0 �Է� �� ����: ");
	if (scanf("%d", &select) != 1)
	{
		select = 0;
	}
	return select;
}

ADD inputAdd(ADD add)
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

void inputRetouch(ADD add)
{
	ADD records[MAX_RECORDS];
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

void statistics(ADD add)
{
	ADD records[MAX_RECORDS];
	int count = saveRecord(records);
	
	return;
}

void checkRecord(ADD add)
{
	ADD records[MAX_RECORDS];
	int count = saveRecord(records);

	printf("%s\t%10s\t%10s\t%10s\n", "��¥", "ī�װ�", "�ݾ�", "�޸�");
	for (int i = 0; i < count; i++)
	{
		printf("%02d/%02d\t%10s\t%10c%d\t%20s\n",
			records[i].date.month, records[i].date.day,
			records[i].type, records[i].pm,
			records[i].money, records[i].etc);
	}

	return;
}

int saveRecord(ADD records[])
{
	FILE* fp;
	fopen_s(&fp, "C:/Users/otter/Desktop/record.txt", "r");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		return 0;
	}

	int count = 0;
	char line[200];
	fgets(line, sizeof(line), fp); //��� �ǳʶٱ�

	while (fgets(line, sizeof(line), fp) && count < MAX_RECORDS)
	{
		line[strcspn(line, "\n")] = 0;

		if (sscanf(line, "%d/%d %s %c%d %[^\n]",
			&records[count].date.month,
			&records[count].date.day,
			records[count].type,
			&records[count].pm,
			&records[count].money,
			records[count].etc) == 6)
		{
			count++;
		}
	}
	fclose(fp);

	return count;
}