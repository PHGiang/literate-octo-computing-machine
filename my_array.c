#include <stdio.h> 
#include <stdlib.h>
#include "my_array.h"

void array_init(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = -1; 
	}
	array_print(arr, size); 
}

void array_push(int *arr, int val, int size) {
	int i = 0; 
	while(i < size) {
		if (arr[i] == -1) {
			arr[i] = val;
			break;
		}
		i++; 
	}	
}

int array_search(int *arr, int size, int val, int act) {
	int found = 0; 
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) {
			found = 1; 
			if (act == delete) {
				printf("\nDelete node %d", val); 
				arr[i] = -1; 
			}
			break; 
		}
	}
	return found; 
}

void array_print(int *arr, int size) {
	printf("\nPrint array:\t"); 
	int i = 0; 
	while (i < size) {
		printf("%d\t", arr[i++]); 
	}
}

void conv_alpha(char *b, int val) {
	int i = 0, j, k, g;
	k = val;  
	while (k > 0) {
		i++; 
		k = k / 10; 
	}
	g = i; 
	i--; 
	while (val > 0) {
		k = val % 10;
		b[i] = k + 48; 
		i--; 
		val = val / 10;  
	}
	b[g] = '\0'; 
}

int conv_int(char * arr) {
	int i = 1; 
	char k[9]; 
	while (arr[i] != '\0') {
		k[i-1] = arr[i];
		i++;  
	}
	k[i-1] = '\0'; 
	i = atoi(k); 
	return i; 
}

void conv_alphaN(char *b, int val) {
	int k, i = 1, j; 
	k = val; 
	b[0] = 'N'; 
	while (k > 0) {
		i++; 
		k = k/10; 
	}
	b[i] = '\0'; 
	i--; 
	while (val > 0) {
		k = val % 10; 
		b[i] = k + 48; 
		i--; 
		val = val / 10; 
	}
}