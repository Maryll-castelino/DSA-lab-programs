#include <stdio.h> 
#include <stdlib.h> 

// l - lower bound
// m - mid point
// u - upper bound

void merge(int arr[], int l, int m, int u) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = u - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int u) 
{ 
	if (l < u) { 
		int m = l + (u - l) / 2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, u); 

		merge(arr, l, m, u); 
	} 
} 

void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int i, n, arr[25];
	printf("Enter value of n : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &arr[i]);
    }

	printf("Given array is \n"); 
	printArray(arr, n); 

	mergeSort(arr, 0, n - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, n); 
	return 0; 
} 
