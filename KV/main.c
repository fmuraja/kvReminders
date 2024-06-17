#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

extern int listType = 0;

int main() {

	createFile();

	int reminderCount = 0;
	struct reminder reminders;
	REMINDER* pokReminder = &reminders;
	pokReminder = (REMINDER*)calloc(30, sizeof(REMINDER));
	if (pokReminder == NULL) {
		perror("Nije moguce alocirati memoriju");
		return 0;
	}

	
	read(pokReminder, reminderCount, reminders, listType);

	while (1) {
		int izbor = 0;
		menu(izbor, pokReminder, reminderCount, reminders, listType);
	}
	printf("menu output");

	return 0;
}