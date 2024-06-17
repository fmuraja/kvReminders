#define HEADER_H
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_TITLE_LENGTH 20
#define CLEAR_INPUT_BUFFER while (getchar() != '\n');

typedef struct reminder {

	char description[100];
	char category[20];
	char name[20];
	int day;
	int month;
	int year;

}REMINDER;

int i;
int j;

int menu(izbor, pokReminder, reminderCount, reminders, listType);
void list(pokReminder, reminderCount, reminders);
int add(pokReminder, reminderCount, reminders, listType);
int read(pokReminder, reminderCount, reminders, listType);
void write(pokReminder, reminderCount, reminders);
void search(pokReminder, reminderCount, reminders);
int compare(x_void, y_void);
void rewriteSortedList(pokReminder, reminderCount, reminders, tempDateArray);
void createFile();
void deleteFile();
void deleteReminder(pokReminder, reminderCount, reminders, listType);
void sort(pokReminder, reminderCount, reminders);
void simpleList(pokReminder, reminderCount, reminders);