#pragma once

typedef struct add {
	int date;
	char type[20];
	char pm;
	int money;
	int etc;
}ADD;

int menu(int select);
ADD inputAdd(ADD add);
void statistics();