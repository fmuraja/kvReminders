#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

int read(REMINDER* pokReminder, int reminderCount, REMINDER reminders, int listType) {
	FILE* file = fopen("data.txt", "r");
	if (file == NULL) {
		perror("Nije moguce otvoriti datoteku");
		return;
	}
	char line[512];
	reminderCount = 0;
	char tempDate[20];
	int readSwitch = 0;
	rewind(file);
	while (fgets(line, sizeof(line), file) != 0) {
		char* line1 = strchr(line, '|');
		if (line1 != NULL) {
			*line1 = '\0';
			if (readSwitch == 0) {
				strcpy((pokReminder + reminderCount)->name, line);
				strcpy((pokReminder + reminderCount)->description, line1 + 1);
				reminderCount++;
				readSwitch = 1;
				}
			else if (readSwitch == 1) {
				strcpy(tempDate, line1 + 1);
				sscanf(tempDate, "%2d.%2d.%4d", &(pokReminder + reminderCount - 1)->day, &(pokReminder + reminderCount - 1)->month, &(pokReminder + reminderCount - 1)->year);
				readSwitch = 0;
			}
		}

			
	}
	fclose(file);
	sort(pokReminder, reminderCount, reminders);
	if (listType == 0) {
		list(pokReminder, reminderCount, reminders, i);
	}
	else if (listType == 1){
		simpleList(pokReminder, reminderCount, reminders, i);
	}
	return reminderCount;
}

void list(REMINDER* pokReminder, int reminderCount, REMINDER reminders) {
	/*printf("Reminders:\n");*/
	printf("-------------------------");
	for (i = 0; i < reminderCount; i++) {
		printf("\n%s", (pokReminder + i)->name);
		if (strlen((pokReminder + i)->description) > 1)
		printf("\nOpis: %s", (pokReminder + i)->description);
		else
		printf("\n");
		if ((pokReminder + i)->day > 0)
		printf("Datum:%d.%d.%d\n", (pokReminder + i)->day, (pokReminder + i)->month, (pokReminder + i)->year);
	}
	printf("-------------------------\n");

}

void simpleList(REMINDER* pokReminder, int reminderCount, REMINDER reminders, int i) {
    for (int i = 0; i < reminderCount; i++) {
        printf("\n%d.", i + 1);
        printf("%s", (pokReminder + i)->name);
    }
    return;
}