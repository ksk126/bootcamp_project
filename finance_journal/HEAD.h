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

typedef struct money {
	int INmoney;
	int EXmoney;
} MONEY;

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
//����/���� ���� ����ü�迭�� ����
int saveRecord(INCOMEANDEXPENSES records[]);
//����/���� ���� ����ü�迭�� �����ϵ� ���ϴ� ���� ���� ������
int filterByMonth(INCOMEANDEXPENSES filtered[], int month);

/*records[i].date.month, records[i].date.day,
			records[i].type, records[i].pm,
			records[i].money, records[i].etc)*/