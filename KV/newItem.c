#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int add(REMINDER *pokReminder, int reminderCount, REMINDER reminders) {
if (reminderCount == 29) {
		printf("Nema vise mjesta za unos\n");
		return 0;
	}
else {
	CLEAR_INPUT_BUFFER;
	printf("Unesite naziv: ");

	fgets((pokReminder + reminderCount)->name, MAX_TITLE_LENGTH, stdin);
	strtok((pokReminder + reminderCount)->name, "\n");
	while (strlen((pokReminder + reminderCount)->name) < 2) {
		printf("Naziv ne moze biti kraci od 2 znaka\n");
		return 0;
	}

	printf("Unesite opis ili pritisnite enter da ostavite prazno: ");
	fgets((pokReminder + reminderCount)->description, MAX_DESCRIPTION_LENGTH, stdin);

	printf("Unesite datum (DD.MM.YYYY): ");
	char date[20];

	while (1)
	{
		scanf("%s", date);
		
		char dateEnd;
		if (sscanf(date, "%2d.%2d.%4d%c", &(pokReminder + reminderCount)->day, &(pokReminder + reminderCount)->month, &(pokReminder + reminderCount)->year, &dateEnd) != 3 || dateEnd > 1)
		{
			printf("Format mora biti DD.MM.YYYY\n");
		}
		else if (!(1 <= (pokReminder + reminderCount)->day && (pokReminder + reminderCount)->day <= 31) ||
			!(1 <= (pokReminder + reminderCount)->month && (pokReminder + reminderCount)->month <= 12) ||
			!((pokReminder + reminderCount)->year >= 2024))
		{
			printf("Unesite validan datum\n");
		}
		else
		{
			break;
		}
	}

	printf("\n%d.%d.%d", (pokReminder + reminderCount)->day, (pokReminder + reminderCount)->month, (pokReminder + reminderCount)->year);
	write(pokReminder, reminderCount, reminders, i);
}
	return 0;

}

void addCategory(REMINDER *pokReminder, int reminderCount, REMINDER reminders) {
	printf("Odaberite kategoriju: ");
	//postojeca


	//nova
	printf("Unesite kategoriju: ");
	fgets((pokReminder + reminderCount)->category, MAX_CATEGORY_LENGTH, stdin);
	strtok((pokReminder + reminderCount)->category, "\n");
	while (strlen((pokReminder + reminderCount)->category) < 2) {
		fgets((pokReminder + reminderCount)->category, MAX_CATEGORY_LENGTH, stdin);
	}
}

void write(REMINDER *pokReminder, int reminderCount, REMINDER reminders) {
	FILE* fp = fopen("data.txt", "a+");
	if (fp == NULL) {
		perror("Nije moguce otvoriti datoteku");
		return;
	}
	
	i++;

	
	fprintf(fp, "%s|%s|%d.%d.%d\n", (pokReminder + reminderCount)->name, (pokReminder + reminderCount)->description, (pokReminder + reminderCount)->day, (pokReminder + reminderCount)->month, (pokReminder + reminderCount)->year);
	

	fclose(fp);
	return 0;
}