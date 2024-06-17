#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void sort(REMINDER* pokReminder, int reminderCount, REMINDER reminders) {
	int tempDateArray[30];
	for(int i = 0; i < reminderCount; i++) {
		tempDateArray[i] = (pokReminder + i)->year * 10000 + (pokReminder + i)->month * 100 + (pokReminder + i)->day;
	}
	qsort(tempDateArray, reminderCount, sizeof(int), compare);
	
	rewriteSortedList(pokReminder, reminderCount, reminders, tempDateArray);
	return 0;

}

int compare(const void* x_void, const void* y_void) {
	
	int x = *(int *)x_void;
	int y = *(int *)y_void;
	return x - y;

}

void rewriteSortedList(REMINDER* pokReminder, int reminderCount, REMINDER reminders, int tempDateArray[30]) {
	

	static char tempName[30][MAX_TITLE_LENGTH];
	static char tempDesc[30][MAX_DESCRIPTION_LENGTH];
	for (int i = 0; i < reminderCount; i++) {
		for (int j = 0; j < reminderCount; j++) {
			if (tempDateArray[i] == (pokReminder + j)->year * 10000 + (pokReminder + j)->month * 100 + (pokReminder + j)->day) {
				strcpy(tempName[i], (pokReminder + j)->name);
				strcpy(tempDesc[i], (pokReminder + j)->description);
			}
		}
	}
	char tempDateString[10] = { 0 };
	for (int i = 0; i < reminderCount; i++) {
		sprintf(tempDateString, "%d", tempDateArray[i]);
		(sscanf(tempDateString, "%4d%2d%2d", &(pokReminder + i)->year, &(pokReminder + i)->month, &(pokReminder + i)->day));
		
	}

	FILE* file = fopen("data.txt", "r");
	if (file == NULL) {
		perror("Nije moguce otvoriti datoteku");
		return;
	}
	FILE* tempFile = fopen("temp.txt", "w");
	if (tempFile == NULL) {
		perror("Nije moguce otvoriti privremenu datoteku");
		return;
	}
	for (int i = 0; i < reminderCount; i++) {
		fprintf(tempFile, "%s|%s", tempName[i], tempDesc[i]);
		fprintf(tempFile, "|%d.%d.%d\n", (pokReminder + i)->day, (pokReminder + i)->month, (pokReminder + i)->year);
	}
	fclose(file);
	fclose(tempFile);

	if (remove("data.txt") != 0) {
		perror("Nije moguce obrisati datoteku");
		return;
	}

	if (rename("temp.txt", "data.txt") != 0) {
		perror("Nije moguce preimenovati privremenu datoteku");
		return;
	}

	return 0;

}

