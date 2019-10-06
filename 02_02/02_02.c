#include <stdio.h>
#include <string.h>

void main(int argc, char** argv) {
	int i = 0, size = 0;
	int key1[3] = { 3,5,7 };
	int key2[3] = { 0, };
	char string1[] = "value";
	char string2[100] = { 0, };

	key2[0] = 3;
	key2[1] = 5;
	key2[2] = 7;

	size = sizeof(key1) / sizeof(key1[0]);
	printf("Element number of key1 array = %d\n", size);
	for (i = 0; i < size; i++) {
		printf("%d->%d\n", i, key1[i]);
	}

	size = sizeof(key2) / sizeof(key2[0]);
	printf("Element number of key2 array = %d\n", size);
	for (i = 0; i < size; i++) {
		printf("%d->%d\n", i, key2[i]);
	}

	size = sizeof(string1) / sizeof(string1[0]);
	//size = sizeof(string1) / sizeof(char);
	printf("Element number of string1 = %d\n", size);
	printf("string1 = %s\n", string1);

	strcpy(string2 , "copy using strcpy");
	size = sizeof(string2) / sizeof(string2[0]);
	//size = sizeof(string2) / sizeof(char);
	printf("Element number of string2 = %d\n", size);
	printf("string2 = %s\n", string2);
}