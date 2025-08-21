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

//프로그램 실행 루프
void run();
//메뉴 출력, 선택한 번호 반환
int menu(int select);
//수입/지출 내역 추가
ADD inputAdd(ADD add);
//수입/지출 내역 수정
void inputRetouch(ADD add);
//월별 통계 출력
void statistics(ADD add);
//수입/지출 내역 보기
void checkRecord(ADD add);
//수입/지출 내역 구조체에 저장
int saveRecord(ADD records[]);