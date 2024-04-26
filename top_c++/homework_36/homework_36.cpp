#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void main()
{
	FILE* file;
	FILE* newFile;
	char fileName[] = "words.txt";
	char newFileName[] = "newWords.txt";

	if ((file = fopen(fileName, "r")) && (newFile = fopen(newFileName, "w"))) {
		char word[20];
		while (!feof(file)) {
			fscanf(file, "%s", word);
			if (strlen(word) >= 7) {
				fprintf(newFile, word);
				fprintf(newFile, "\n");
			}
		}
		fclose(file);
		fclose(newFile);
	}
}

