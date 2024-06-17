#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int menu(int izbor, REMINDER* pokReminder, int reminderCount, REMINDER reminders, int listType) {
	printf("\nIzbornik\n");
	printf("\n1. Dodaj \n2. Ispis \n3. Obrisi podsjetnik \n4. Obrisi sve \n5. Pretraga\n6. Izlaz iz programa\n");

	if (scanf("%d", &izbor) != 1) {
		printf("\033[2J\033[1;1H");
		printf("Unesite broj\n\n");
		CLEAR_INPUT_BUFFER;

	}
	else {
	switch (izbor) {

	case 1: {
		printf("\033[2J\033[1;1H");
		add(pokReminder, reminderCount, reminders);
		return izbor;
	}
	case 2: {
		printf("\033[2J\033[1;1H");
		listType = 0;
		read(pokReminder, reminderCount, reminders, listType);
		return izbor;
	}
	case 3: {
		printf("\033[2J\033[1;1H");
		deleteReminder(pokReminder, reminderCount, reminders);
		return izbor;
	}
	case 4: {
		printf("\033[2J\033[1;1H");
		deleteFile();
		return izbor;
	}
	case 5: {
		printf("\033[2J\033[1;1H");
		listType = 2;
		reminderCount = read(pokReminder, reminderCount, reminders, listType);
		search(pokReminder, reminderCount, reminders);
		listType = 0;
		return izbor;
	}
	case 6 : {
		
		free(pokReminder);
		exit(0);
	}
	default: {
		printf("\033[2J\033[1;1H");
		printf("Krivi unos\n\n");
		return izbor;
	}
	}
}

}