#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void update(REMINDER* pokReminder, int reminderCount, REMINDER reminders, int listType) {

	printf("Unesite redni broj podsjetnika koji zelite izmjeniti: \n");
	listType = 1;
	read(pokReminder, reminderCount, reminders, listType);
	int izborEdit = 0;
	reminderCount = i;

	do {
		if (scanf("%d", &izborEdit) != 1) {
			printf("Unesite broj\n\n");
			while (getchar() != '\n');
		}
		else
			break;
	} while (izborEdit < 1 || izborEdit > i);

	FILE* file = fopen("data.txt", "r");
	if (file == NULL) {
		perror("Nije moguce otvoriti datoteku");
		return;
	}
	printf("%d", izborEdit);
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
	izborEdit--;
	printf("\033[2J\033[1;1H");
	printf("\nSto zelite izmjeniti?");
	printf("\n1. ime: %s", (pokReminder + izborEdit)->name);
	printf("\n2. opis: %s", (pokReminder + izborEdit)->description);
	printf("3. datum: %d.%d.%d\n\n", (pokReminder + izborEdit)->day, (pokReminder + izborEdit)->month, (pokReminder + izborEdit)->year);

	int izborEditSub = 0;

	if (scanf("%d", &izborEditSub) != 1) {
		printf("Unesite broj\n\n");
		CLEAR_INPUT_BUFFER;

	}
	else if (izborEditSub < 1 || izborEditSub > 3) {
		printf("Krivi unos\n\n");
	}
	else {};
	
	if (izborEditSub == 1) {

		CLEAR_INPUT_BUFFER;
		printf("Unesite novi naziv: ");

		fgets((pokReminder + izborEdit)->name, MAX_TITLE_LENGTH, stdin);
		strtok((pokReminder + izborEdit)->name, "\n");
		while (strlen((pokReminder + izborEdit)->name) < 2) {
			printf("Naziv ne moze biti kraci od 2 znaka\n");
			return 0;
		}

	}
	else if (izborEditSub == 2) {

		printf("Unesite novi opis ili pritisnite enter da ostavite prazno: ");
		fgets((pokReminder + izborEdit)->description, MAX_DESCRIPTION_LENGTH, stdin);

	}
	else if (izborEditSub == 3) {

		printf("Unesite novi datum (DD.MM.YYYY): ");
		char date[20];

		while (1)
		{
			scanf("%s", date);

			char dateEnd;
			if (sscanf(date, "%2d.%2d.%4d%c", &(pokReminder + izborEdit)->day, &(pokReminder + izborEdit)->month, &(pokReminder + izborEdit)->year, &dateEnd) != 3 || dateEnd > 1)
			{
				printf("Format mora biti DD.MM.YYYY\n");
			}
			else if (!(1 <= (pokReminder + izborEdit)->day && (pokReminder + izborEdit)->day <= 31) ||
				!(1 <= (pokReminder + izborEdit)->month && (pokReminder + izborEdit)->month <= 12) ||
				!((pokReminder + izborEdit)->year >= 2024))
			{
				printf("Unesite validan datum\n");
			}
			else
			{
				break;
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
			fprintf(tempFile, "%s|%s", (pokReminder + reminderCountTemp)->name, (pokReminder + reminderCountTemp)->description);
			fprintf(tempFile, "|%d.%d.%d\n", (pokReminder + reminderCountTemp)->day, (pokReminder + reminderCountTemp)->month, (pokReminder + reminderCountTemp)->year);

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

	printf("Podsjetnik uspjesno promjenjen\n\n");


}