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



