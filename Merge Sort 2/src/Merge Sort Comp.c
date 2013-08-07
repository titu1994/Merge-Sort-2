/*
 ============================================================================
 Name        : Merge.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Contains the memcpy() functions and memmove() functions
#include <string.h>


int main(void) {

	int *a = NULL, i;
	int n;

	void MergeSort(int *a, int size);

	setbuf(stdout, NULL);

	printf("Enter number of elements : \n");
	scanf("%d",&n);

	a = (int*) calloc(n, sizeof(int));

	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}

	MergeSort(a, n);

	for(i = 0; i < n; i ++){
		printf("%d\t",a[i]);
	}

	return EXIT_SUCCESS;
}


void MergeSort(int *a, int size){

	void merge(int*,int*,int,int);

	//size <= 1 prevents infinite recursion

	if(size <= 1){
		return;
	}
	else{

		int middle = size/2;
		int leftsize = middle;
		int rightsize = size - middle;

		int *left,*right;

		// Makes left point to the first sub array
		left = a;

		// Makes right point to the second sub array
		right = a + leftsize;

		// Recursively call MergeSort to split the array into atomic elements
	
		MergeSort(left, leftsize);
		MergeSort(right, rightsize);

		//Merges De-Recursively into a single array
		merge(left, right,leftsize,rightsize);
	}
}

void merge(int *left, int *right,int leftsize, int rightsize){

	int *lTemp;
	int *rTemp;

	// Creates a temporary array to hold the sub elements

	lTemp = (int*) calloc(leftsize, sizeof(int));
	rTemp = (int*) calloc(rightsize, sizeof(int));

	// Access pointers to the created memory

	int *lPos = lTemp, *rPos = rTemp;

	//Copy the memory from left[0] to left[leftsize - 1]
	memcpy(lTemp, left, leftsize*sizeof(int));

	//Copy the memory from right[0] to rig[size - 1]
	memcpy(rTemp, right , rightsize*sizeof(int));

	//Important : Directly accesses the array passed as a
	int *result = left;

	while(leftsize > 0 || rightsize > 0){

		if(leftsize > 0 && rightsize > 0){

			if(*lPos <= *rPos){

				*result = *lPos;
				++lPos;
				--leftsize;
			}
			else{

				*result = *rPos;
				++rPos;
				--rightsize;
			}

			++result;

		}
		else if(leftsize > 0){

			while(leftsize > 0){
				*result = *lPos;
				++result;
				++lPos;
				--leftsize;
			}

		}
		else if(rightsize > 0){
			while(rightsize > 0){

				*result = *rPos;
				++result;
				++rPos;
				--rightsize;

			}

		}

	}

	free(lTemp);
	free(rTemp);
}


