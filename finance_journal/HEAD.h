#pragma once

#define MAX_RECORDS 1000

typedef struct date {
	int month;
	int day;
}DATE;

typedef struct add {
	DATE date;
	char type[20];
	char pm;
	int money;
	char etc[100];
}ADD;

//���α׷� ���� ����
void run();
//�޴� ���, ������ ��ȣ ��ȯ
int menu(int select);
//����/���� ���� �߰�
ADD inputAdd(ADD add);
//����/���� ���� ����
void inputRetouch(ADD add);
//���� ��� ���
void statistics(ADD add);
//����/���� ���� ����
void checkRecord(ADD add);
//����/���� ���� ����ü�� ����
int saveRecord(ADD records[]);