#include <stdio.h>
#include "dictionary.h"

int readWord(FILE * fp, char *buffer)
{
	int c;
	
	do {
		c = fgetc(fp);
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fp);
		if(c == 146)
			c = '\'';
	} while(isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

int main()
{
	FILE *fp;
	char buffer[1024];
	Dictionary dict;

	fp = fopen("liar.txt", "r");
	if(fp == NULL) {
		printf("Error opening file.\n");
		return 0;
	}

	dict = create();
	while(readWord(fp, buffer)) {
		add(dict, buffer);
	}

	fclose(fp);

	print(dict);

	destroy(dict);

	return 0;
}