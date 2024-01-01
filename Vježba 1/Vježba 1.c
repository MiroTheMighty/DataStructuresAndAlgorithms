#include<stdio.h>
#include<string.h>

int myStrlen(char* str) {
	int n = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		n++;
	}
	return n;
}

char* myStrcpy(char* destination, char* source) {
	int n, i;
	n = myStrlen(source);
	for (i = 0; i < n; i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

int myStrcmp(char* str1, char* str2) {
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] > str2[i]) {
			return 1;
		}
		if (str1[i] < str2[i]) {
			return -1;
		}
		i++;
	}
	return 0;
}

char* myStrcat(char* destination, char* source) {
	int n, i;
	n = myStrlen(destination);
	for (i = 0; source[i] != '\0'; i++) {
		destination[n] = source[i];
		n++;
	}
	destination[n] = '\0';
	return destination;
}

char* mystrstr(char* source, char* ser) {
	int flag = 0;
	for (int i = 0; i < myStrlen(source); i++) {
		if (source[i] == ser[0]) {
			for (int j = 0; j < myStrlen(ser); j++) {
				if (source[i + j] == ser[j]) {
					flag = 1;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				return &source[i];
			}
		}
	}
	return NULL;
}

char* Reverse(char* source, char* destination) {
	int i, n;
	char temp[50];
	n = myStrlen(source);
	temp[n] = '\0';
	for (i = n - 1; i >= 0; i--) {
		temp[n - 1 - i] = source[i];
	}
	myStrcat(destination, &temp);
	return destination;
}

void main() {
	char* str = "je string";
	char reverseS[50] = "Ante";
	char reverseD[50] = "Luka ";
	char cpyStr[50];
	char strcat[50] = "Ovo ";
	char strcmpr1[20] = "aab";
	char strcmpr2[20] = "aabc";
	char strstr1[50] = "Automehanicar";
	char strstr2[20] = "mehanicar";
	char* strstrC;
	int n = 0, j;
	n = myStrlen(str);
	printf("Duljina stringa je: %d\n", n);
	myStrcpy(&cpyStr, str);
	printf("Kopirani string je: %s\n", cpyStr);
	myStrcat(&strcat, str);
	printf("Dodani string je: %s\n", strcat);
	j = myStrcmp(&strcmpr1, &strcmpr2);
	printf("Strcmp: %d\n", j);
	strstrC = mystrstr(&strstr1, &strstr2);
	printf("Strstr: %s\n", strstrC);
	strstrC = strstr(&strstr1, &strstr2);
	printf("Strstr(string.h): %s\n", strstrC);
	Reverse(&reverseS, &reverseD);
	printf("Reverse: %s", reverseD);
}