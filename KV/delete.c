#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void deleteFile() {
	int izborDelete = 0;
	printf("Jeste li sigurni da zelite trajno obrisati sve?\n");
	printf("\n1. Da \n2. Ne \n");

	if (scanf("%d", &izborDelete) != 1) {
		printf("\033[2J\033[1;1H");
		printf("Unesite broj\n\n");
		CLEAR_INPUT_BUFFER;

	}
	else {
		switch (izborDelete) {

		case 1: {
			if (remove("data.txt") == 0) {
				printf("\033[2J\033[1;1H");
				printf("Datoteka uspjesno obrisana\n\n");
			}
			else
				perror("Nije moguce obrisati datoteku\n\n");
		}
		case 2: {
			return 0;
		}
		default: {
			printf("\033[2J\033[1;1H");
			printf("Krivi unos\n\n");
			return 0;
		}
		}
	}


	return 0;
}

void deleteReminder(REMINDER* pokReminder, int reminderCount, REMINDER reminders, int listType) {

	printf("Unesite redni broj podsjetnika koji zelite obrisati: \n");
	listType = 1;
	read(pokReminder, reminderCount, reminders, listType);
	int izborDelete = 0;
	reminderCount = i;

	do {
		if (scanf("%d", &izborDelete) != 1) {
			printf("Unesite broj\n\n");
			while (getchar() != '\n');
		}
		else
			break;
	} while (izborDelete < 1 || izborDelete > i);

	FILE* file = fopen("data.txt", "r");
	if (file == NULL) {
		perror("Nije moguce otvoriti datoteku");
		return;
	}
	printf("%d", izborDelete);
	char line[512];
	reminderCount = 0;
	char tempDateDel[20];
	int readSwitchDel = 0;
	while (fgets(line, sizeof(line), file) != 0) {
		char* line1 = strchr(line, '|');
		if (line1 != NULL) {
			*line1 = '\0';
			if (readSwitchDel == 0) {
				strcpy((pokReminder + reminderCount)->name, line);
				strcpy((pokReminder + reminderCount)->description, line1 + 1);
				reminderCount++;
				readSwitchDel = 1;
			}
			else if (readSwitchDel == 1) {
				strcpy(tempDateDel, line1 + 1);
				sscanf(tempDateDel, "%2d.%2d.%4d", &(pokReminder + reminderCount - 1)->day, &(pokReminder + reminderCount - 1)->month, &(pokReminder + reminderCount - 1)->year);
				readSwitchDel = 0;
			}
		}


	}

	FILE* tempFile = fopen("temp.txt", "w");
	if (tempFile == NULL) {
		perror("Nije moguce otvoriti privremenu datoteku");
		fclose(file);
		return;
	}
	int reminderCountTemp = 0;
	printf("%d, %d", reminderCount, i);
	rewind(file);
	while (reminderCountTemp < i) {
		if ((pokReminder + reminderCountTemp)->name != (pokReminder + izborDelete - 1)->name) {
			fprintf(tempFile, "%s|%s", (pokReminder + reminderCountTemp)->name, (pokReminder + reminderCountTemp)->description);
			fprintf(tempFile, "|%d.%d.%d\n", (pokReminder + reminderCountTemp)->day, (pokReminder + reminderCountTemp)->month, (pokReminder + reminderCountTemp)->year);
		}
			reminderCountTemp++;
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

	printf("Podsjetnik uspjesno obrisan\n\n");


}