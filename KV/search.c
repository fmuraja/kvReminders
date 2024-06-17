#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void search(REMINDER* pokReminder, int reminderCount, REMINDER reminders) {
    int result;
    char searchTerm[20];
    printf("Unesite pojam za pretrazivanje: ");
    CLEAR_INPUT_BUFFER;
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';
    for(int i = 0; i < reminderCount; i++) {
		result = strcmp(searchTerm, (pokReminder + i)->name);
		if (result == 0) {
			printf("Pronadeno: \n%s\n%s", (pokReminder + i)->name, (pokReminder + i)->description);
            printf("%d.%d.%d\n", (pokReminder + i)->day, (pokReminder + i)->month, (pokReminder + i)->year);
            break;
		}
	}
    if (result != 0) {
		printf("Nema rezultata\n");
	}

    return(0);
}