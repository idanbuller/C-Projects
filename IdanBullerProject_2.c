#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();

/* Declarations of other functions */
//EX1 Functions
char** split(char c, char* str, int* size);
//EX2 Functions
char* clearDigitsAndSpaces(char* str);
//EX3 Functions
void createFile(char* name);
char commonestLetter(char* filename);
//EX4 Functions
void decode(char* str);
//EX5 Functions
void memoryReport(char* filename, char* decleration);
void printFile(char* name);
int getArrayInfo(char** name);
//EX6 Functions

//EX7 Functions

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 7));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
				//case 6: Ex6(); break;
				//case 7: Ex7(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

//EX1 Functions
void Ex1() {
	char str[50];
	char c;
	printf("Enter a String: ");
	fgets(str, 50, stdin); fgets(str, 50, stdin);
	printf("Enter a Char: ");
	c = getchar();
	char** arr;
	int size;
	int* psize = &size, i = 0, j = 0;

	arr = split(c, str, psize);
	for (i = 0; i < size; i++) {
		puts(arr[i]);
		printf("\n");

	}
}
char** split(char c, char* str, int* size) {
	char** mat = NULL;
	int i = 0, count = 0, j = 0, k = 0, count1 = 0;
	if (str[i] == c || (str[i] - 'A' + 'a') == c)
		count1++;
	i++;
	while (str[i] != '\0') {
		if (str[i] == 32)
		{
			if (str[i + 1] != 32)
			{
				if (str[i + 1] == c || (str[i + 1] - 'A' + 'a') == c)
					count1++;
			}
		}
		i++;
	}
	mat = (char**)malloc(count1 * sizeof(char*));
	if (mat == NULL)
	{
		printf("couldn't allocate memory\n");
		return NULL;
	}

	i = 0;
	while (str[i + 1] != '\0' && str[i] != '\0') {

		if (str[i] == c || (str[i] - 'A' + 'a') == c) {
			count++;
			if (str[i + 1] != '\0')
				i++;
			while (str[i] != 32 && str[i + 1] != '\0') {
				count++;
				i++;
			}
			mat[j++] = (char*)malloc((count + 1) * sizeof(char));
			count = 0;
		}
		else {
			while (str[i] != 32 && str[i + 1] != '\0') {
				i++;
			}
		}
		i++;
	}
	j = 0, i = 0;
	while (str[i + 1] != '\0' && str[i] != '\0') {

		if (str[i] == c || (str[i] - 'A' + 'a') == c) {
			mat[j][k++] = str[i];
			if (str[i + 1] != '\0')
				i++;
			while (str[i] != 32 && str[i + 1] != '\0') {
				mat[j][k++] = str[i];
				i++;
			}
			mat[j][k] = '\0';
			j++;
			k = 0;
		}
		else {
			while (str[i] != 32 && str[i + 1] != '\0') {
				i++;
			}
		}
		i++;
	}
	*size = count1;
	return mat;

}

//EX2 Functions
void Ex2() {
	char str[50];
	int i = 0;
	printf("Enter a String: ");
	fgets(str, 50, stdin); fgets(str, 50, stdin);
	char* newStr;
	newStr = clearDigitsAndSpaces(str);
	while (newStr[i] != '\0')
	{
		printf("%c", newStr[i]);
		i++;
	}
	printf("\n\n");
}
char* clearDigitsAndSpaces(char* str) {
	char* newStr;
	int i = 0, j = 0, count = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] != 32 && (str[i] <= 48 || str[i] >= 57))
			count++;
		i++;
	}
	newStr = (char*)malloc((count + 1) * sizeof(char));
	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] != 32 && (str[i] <= 48 || str[i] >= 57)) {
			*(newStr + j) = str[i];
			j++;
		}
		i++;
	}
	*(newStr + j) = '\0';
	return newStr;
}

//EX3 Functions
void Ex3() {
	FILE* file = NULL;
	char name[50] = "input.txt";
	char c;
	createFile(name);
	file = fopen(name, "r");
	if (file == NULL) // checking if the file opened
	{
		printf("couldn't open the file\n");
		return;
	}
	printf("\nThe file is:\n");
	while (1)
	{
		c = fgetc(file);
		printf("%c", c);
		if (feof(file))
			break;
	}
	c = commonestLetter(name);

	printf("\nThe most common letter is : %c\n", c);

}
void createFile(char* name) {
	FILE* file = NULL;
	file = fopen(name, "a");
	char c;
	if (file == NULL) // checking if the file opened
	{
		printf("couldn't open the file\n");
		return;
	}
	printf("Enter a char to the file to stop enter 0: ");
	c = getchar();
	while (c != '0')
	{
		fprintf(file, "%c", c);
		c = getchar();
	}
	fclose(file);
}
char commonestLetter(char* filename) {
	int count[26] = { 0 };
	char c;
	FILE* file = NULL;
	int i, max, maxI;
	file = fopen(filename, "r");
	if (file == NULL) // checking if the file opened
	{
		printf("couldn't read the file\n");
		return NULL;
	}
	c = fgetc(file);

	while (c != EOF)
	{
		if (c >= 97 && c <= 122) count[c - 97]++;
		if (c >= 65 && c <= 90) count[c - 65]++;
		c = fgetc(file);
	}
	fclose(file);
	maxI = 0;
	max = count[0];

	for (i = 0; i < 25; i++)
	{
		if (count[i + 1] >= max)
		{
			max = count[i + 1];
			maxI = i + 1;
		}
	}

	c = (65 + maxI);

	return c;

}
//EX4 Functions
void Ex4() {
	char str[60] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
	printf("The encoded string is : %s\n", str);
	decode(str);
	printf("\n");
	printf("After decodeing the string is: %s\n", str);
}
void decode(char* str) {
	int i = 0, count = 1;
	while (str[i] != '\0') {
		if (str[i] == 32)
			count = 1;
		else {
			str[i] = str[i] - count;
			count++;
		}
		i++;
	}
}

//EX5 Functions
void Ex5(){
	char str[50];
	char filename[50] = "Ex5.txt";
	printf("enter a string:\n\n");
	fgets(str, 50, stdin);
	fgets(str, 50, stdin);
	memoryReport(filename, str);
	printf("\n\n");
	printFile(filename);
}
void memoryReport(char* filename, char* decleration)
{
	char* variabletype = NULL; // contains the variable type
	char* variablename = NULL; // contains the variable name 
	char* tempVarName = NULL;  // contains the variable name
	char tempName = '0', tempType = '0'; // used to check if there is ; or * or []
	int lengthName, lengthType; // // used to check if there is ; or * or []
	int toWriteVar = 0; // used to write the amount of bytes needed
	int longFlag = 0; // used to check a special situation for long or long long
	char c; // used to determain if the variable is an array
	int arrayMult; // used to store the size of the array

	FILE* file = NULL;
	file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("coudln't open the file\n");
		return;
	}

	variabletype = strtok(decleration, " "); // extracting the variable type and determening the type

	if (strcmp(variabletype, "int") == 0 || strcmp(variabletype, "float") == 0)
		toWriteVar = 4;
	else
		if (strcmp(variabletype, "double") == 0)
			toWriteVar = 8;
		else
			if (strcmp(variabletype, "short") == 0)
				toWriteVar = 2;
			else
				if (strcmp(variabletype, "char") == 0)
					toWriteVar = 1;
				else
					if (strcmp(variabletype, "long") == 0) // checking whether the type is long, or long long
					{
						longFlag = 1;
						variablename = strtok(NULL, ",");
						if (strstr(variablename, "long") != NULL)
							toWriteVar = 8;
						else
							toWriteVar = 4;
					}

	/*special check if the variable entered was long or long long*/

	if (longFlag == 1)
	{
		if (strcmp(variablename, "long") == 0)
			variablename = strtok(NULL, ","); // if the type is long long, read the variable name, else continue
	}
	else
		variablename = strtok(NULL, ",");


	while (variablename != NULL)
	{
		lengthName = strlen(variablename);
		tempName = variablename[lengthName - 2];
		if (tempName == ';') // checking if it's the end of the command
		{
			variablename[lengthName - 2] = '\0';
			break;
		}

		c = variablename[lengthName - 1];
		if (c == 93) // if it is an array, seperate the name from the size of the array
		{
			arrayMult = getArrayInfo(&variablename);
			fprintf(file, "%s requires %d bytes\n", variablename, (arrayMult * toWriteVar));
			variablename = strtok(NULL, ", ");
			continue;
		}

		if (variablename[0] == 42 || variablename[1] == 42) // if the name is a pointer, give it 4 bytes
		{
			fprintf(file, "%s requires %d bytes\n", variablename, 4);
			variablename = strtok(NULL, ",");

			continue;
		}

		fprintf(file, "%s requires %d bytes\n", variablename, toWriteVar);
		variablename = strtok(NULL, ",");
	}

	if (variablename[0] == 42 || variablename[1] == 42) // if the name is a pointer, give it 4 bytes
		toWriteVar = 4;
	else
	{
		c = variablename[lengthName - 2];
		if (c == 93) // if it is an array, seperate the name from the size of the array
		{
			arrayMult = getArrayInfo(&variablename);
			fprintf(file, "%s requires %d bytes\n", variablename, (arrayMult * toWriteVar));
			variablename = strtok(NULL, ", ");
		}
	}
	fprintf(file, "%s requires %d bytes\n", variablename, toWriteVar);
	fclose(file);
}
void printFile(char* name)
{
	FILE* file = NULL;
	file = fopen(name, "r");
	char read[50];

	if (file == NULL)
	{
		printf("couldn't open the file\n");
		return;
	}
	while (fgets(read, sizeof(read), file) != 0)
	{
		printf("%s", read);
	}
	fclose(file);
}
int getArrayInfo(char** name)
{
	char* str = *name;
	int digits = 0;
	int info = 0;
	int i = 0, k = 0;
	char* number = NULL;

	while (str[i] != 93)
	{
		if (str[i] == 91)
		{
			info = i;
			i++;
			while (str[i] != 93)
			{
				digits++;
				i++;
			}
			break;
		}
		i++;
	}

	number = (char*)malloc((digits + 1) * sizeof(char));
	if (number == NULL) return 0;

	i = 0;
	while (str[i] != 93)
	{
		if (str[i] == 91)
		{
			i++;
			while (str[i] != 93)
			{
				number[k] = str[i];
				i++;
				k++;
			}
			break;
		}
		i++;
	}

	str[info] = '\0';
	*name = str;
	k = atoi(number);
	free(number);
	return k;
}



//EX6 Functions
//void Ex6(){}


//EX7 Functions
//void Ex7(){}


/* ------------------- */