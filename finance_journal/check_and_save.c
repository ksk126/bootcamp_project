#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "HEAD.h"

extern int saveRecord(INCOMEANDEXPENSES records[]);

void checkRecord(INCOMEANDEXPENSES add)
{
	INCOMEANDEXPENSES records[MAX_RECORDS];
	int count = saveRecord(records);

	printf("%s\t%10s\t%10s\t%10s\n", "날짜", "카테고리", "금액", "메모");
	for (int i = 0; i < count; i++)
	{
		printf("%02d/%02d\t%10s\t%10c%d\t%20s\n",
			records[i].date.month, records[i].date.day,
			records[i].type, records[i].pm,
			records[i].money, records[i].etc);
	}

	return;
}

int saveRecord(INCOMEANDEXPENSES records[])
{
	FILE* fp;
	fopen_s(&fp, "record.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 0;
	}

	int count = 0;
	char line[200];
	fgets(line, sizeof(line), fp); //헤더 건너뛰기

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

int filterByMonth(INCOMEANDEXPENSES filtered[], int month)
{
	INCOMEANDEXPENSES allRecords[MAX_RECORDS];
	int total = saveRecord(allRecords);
	int count = 0;

	for (int i = 0; i < total; i++)
	{
		if (allRecords[i].date.month == month)
		{
			filtered[count++] = allRecords[i];
		}
	}

	return count;

}