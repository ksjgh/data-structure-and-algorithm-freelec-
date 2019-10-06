// Nice review of pointer
// https://youtu.be/AReyaOH6VYE?list=PL7mmuO705dG12pP82RPUR3wdD5dbYu9gZ&t=2344
// see allocating 2D array dynamically using double pointer

#define _CRT_SECURE_NO_WARNINGS // to handle "strcpy" unsafe error
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[20 + 1];
	int year;
	float score;
};

void main(int argc, char** argv) {
	int* ptr_int = NULL;
	int** pptr_int_array = NULL;
	int i = 0, j = 0;
	int row = 3;
	int col = 4;
	int value = 0;
	struct student student_lee;
	struct student* ptr_student = NULL;
	struct student* ptr_student_new = NULL;

	// dynamic 1D array allocation example
	ptr_int = (int*)malloc(sizeof(int) * 100);
	if(ptr_int != NULL) {
		printf("Memory allocation success\n");
		memset(ptr_int, 0, sizeof(int) * 100);
		free(ptr_int);
	}

	// dynamic 2D array allocation example
	//**/////////////////////////////////////////////////////

	// create rows
	pptr_int_array = (int**)malloc(sizeof(int*) * row);
	
	// initialize rows
	memset(pptr_int_array, 0, sizeof(int*) * row);
	
	// create columns
	for (i = 0; i < row; i++) {
		pptr_int_array[i] = (int*)malloc(sizeof(int) * col);
		memset(pptr_int_array[i], 0, sizeof(int) * col);
	}

	// save value
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			value++;
			pptr_int_array[i][j] = value;
		}
		printf("\n");
	}

	// print value using pointer
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf( "%d\t", *(*(pptr_int_array+i)+j) );
		}
		printf("\n");
	}

	// free 2D array
	for (i = 0; i < row; i++) {
		free(pptr_int_array[i]);
	}
	free(pptr_int_array);
	///////////////////////////////////////////////////////**


	// structure pointer example
	//**/////////////////////////////////////////////////////
	ptr_student = &student_lee;
	strcpy(ptr_student->name, "lee");
	ptr_student->score = 80.1f;
	ptr_student->year = 2005;

	printf("%s, %d, %f\n", student_lee.name,
					    	student_lee.year,
							student_lee.score);

	ptr_student_new = (struct student*)malloc(sizeof(struct student) * 1);
	if (ptr_student_new != NULL) {
		strcpy((*ptr_student_new).name, "new");
		(*ptr_student_new).year = 2010;
		(*ptr_student_new).score = 99.9f;

		printf("%s, %d, %f\n", ptr_student_new->name,
			ptr_student_new->year,
			ptr_student_new->score);

		free(ptr_student_new);
	}

	///////////////////////////////////////////////////////**
}
