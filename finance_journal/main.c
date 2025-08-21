#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "HEAD.h"

extern int menu(int select);
extern INCOMEANDEXPENSES inputAdd(INCOMEANDEXPENSES add);
extern void inputRetouch(INCOMEANDEXPENSES add);
extern void statistics(INCOMEANDEXPENSES add);
extern void checkRecord(INCOMEANDEXPENSES add);
extern int saveRecord(INCOMEANDEXPENSES records[]);

int main()
{
	run();

	return 0;
}

void run()
{
	INCOMEANDEXPENSES add = { 0 };
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
			return;
		}
	}
	
	return;
}

