#pragma once

#define MAX_RECORDS 1000

typedef struct date {
	int month;
	int day;
}DATE;

typedef struct incomeAndExpenses {
	DATE date; //날짜
	char type[20]; //수입/지출 카테고리
	char pm; //plus+minus 수입인지 지출인지 구분하는 기호
	int money; //금액
	char etc[100]; //기타
}INCOMEANDEXPENSES;

typedef struct income {
	int fixed; //고정(수입)
	int variable; //변동(수입)
	int inetc; //수입기타
} INCOME;

typedef struct expenses {
	int living; //생활비
	int finance; //금융/의무
	int leisure; //여가/자기계발
	int exetc; //지출기타
} EXPENSES;

typedef struct category {
	INCOME income;
	EXPENSES expenses;
} CATEGORY;

typedef struct money {
	int INmoney;
	int EXmoney;
} MONEY;

//프로그램 실행 루프
void run();
//메뉴 출력, 선택한 번호 반환
int menu(int select);
//수입/지출 내역 추가
INCOMEANDEXPENSES inputAdd(INCOMEANDEXPENSES add);
//수입/지출 내역 수정
void inputRetouch(INCOMEANDEXPENSES add);
//월별 통계 출력
void statistics(INCOMEANDEXPENSES add);
//수입/지출 내역 보기
void checkRecord(INCOMEANDEXPENSES add);
//수입/지출 내역 구조체배열에 저장
int saveRecord(INCOMEANDEXPENSES records[]);
//수입/지출 내역 구조체배열에 저장하되 원하는 월에 대한 내역만
int filterByMonth(INCOMEANDEXPENSES filtered[], int month);

/*records[i].date.month, records[i].date.day,
			records[i].type, records[i].pm,
			records[i].money, records[i].etc)*/