#pragma once

#define MAX_RECORDS 1000

typedef struct date {
	int month;
	int day;
}DATE;

typedef struct incomeAndExpenses {
	DATE date; //��¥
	char type[20]; //����/���� ī�װ�
	char pm; //plus+minus �������� �������� �����ϴ� ��ȣ
	int money; //�ݾ�
	char etc[100]; //��Ÿ
}INCOMEANDEXPENSES;

typedef struct income {
	int fixed; //����(����)
	int variable; //����(����)
	int inetc; //���Ա�Ÿ
} INCOME;

typedef struct expenses {
	int living; //��Ȱ��
	int finance; //����/�ǹ�
	int leisure; //����/�ڱ���
	int exetc; //�����Ÿ
} EXPENSES;

typedef struct category {
	INCOME income;
	EXPENSES expenses;
} CATEGORY;

//���α׷� ���� ����
void run();
//�޴� ���, ������ ��ȣ ��ȯ
int menu(int select);
//����/���� ���� �߰�
INCOMEANDEXPENSES inputAdd(INCOMEANDEXPENSES add);
//����/���� ���� ����
void inputRetouch(INCOMEANDEXPENSES add);
//���� ��� ���
void statistics(INCOMEANDEXPENSES add);
//����/���� ���� ����
void checkRecord(INCOMEANDEXPENSES add);
//����/���� ���� ����ü�� ����
int saveRecord(INCOMEANDEXPENSES records[]);