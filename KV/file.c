#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void createFile() {

	FILE* fp = NULL;
	fp = fopen("data.txt", "a+");
	if (fp == NULL) {
		perror("Nije moguce otvoriti datoteku");
		return 0;
	}
	fclose(fp);
}