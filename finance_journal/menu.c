#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HEAD.h"

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