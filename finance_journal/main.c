#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HEAD.h"

int main()
{
	ADD add = { 0 };
	int select = 123;

	while (select)
	{
		select = menu(select);

		switch (select)
		{
		case 1:
			inputAdd(add);
			break;
		case 2:
			statistics();
			break;
		}

	}
	return 0;
}

int menu(int select)
{

	printf("-------------------MENU--------------------\n");
	printf("1. ����/���� �߰�\n");
	printf("2. ���� ����/���� ���\n");
	printf("-------------------------------------------\n");
	printf("0 �Է� �� ����: ");
	if (scanf("%d", &select) != 1) {
		select = 0;
	}

	return select;
}

ADD inputAdd(ADD add)
{
	return add;
}

void statistics()
{
	return;
}

/*
1.�޴� �����
1) ��¥ ����/���� �߰�(���� �����) 2) �� ���԰� ���� ����ؼ� ��� ���

2. 1�� �Է¹޴� �Լ� ��¥ �з� +/- �� �ڼ��ϰ�


*/
