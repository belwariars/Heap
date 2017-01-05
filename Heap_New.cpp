// Heap codes...
#include <bits/stdc++.h>
using namespace std;

void makeHeap(int *arr, int size);

void printArr(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void restoreUp(int arr[], int n)
{
	int val = arr[n];
	while(arr[n/2] <= val)
	{
		arr[n] = arr[n/2];
		n = (n/2);
	}
	arr[n] = val;
}

void addHeap(int arr[], int *n, int item)
{
	arr[*n] = item;
	(*n)++;
	printArr(arr, *n);
	restoreUp(arr, *n); // here, don't send the address as we only need the copy....
	printf("\n\n");
	printf("Heap Formed ADDING  %d:   ", item);
	printArr(arr, *n);
}

void deleteHeap(int arr[], int *n)
{
	int delitem = arr[1];
	printf("The item to be deleted:  %d\n", delitem);
	arr[1] = arr[(*n)-1];
	(*n)--;
	
	makeHeap(arr, *n);
}

int main()
{
	int arr[20] = {1000, 7, 10, 25, 17, 23, 27, 16, 19, 37, 42, 4, 33, 1, 5, 11 };
	// ALWAYS REMEMBER!!!  arr[x] here, x(20 here) > n(16 here)..so always make x > n while writing code
	// Array of 20 size as if we want to add more items...
//	int n = sizeof(arr)/sizeof(arr[0]);
	int n = 16;
	makeHeap(arr, n);
//	printf("size = %d\n", n);
// Don't write or call printArr(arr, n); here, as, the size of array is reducing to half
	int item = 24;
	addHeap(arr, &n, 24);  // Address of n which is total no. of elements in array which isnt sizeof(arr)/sizeof(arr[0]), has to increased....
	
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	deleteHeap(arr, &n);
	return 0;
}


void restoreDown(int pos, int arr[], int n)
{
	int val = arr[pos];
	
	while(pos <= (n/2))
	{
		int i = 2*pos;
		if((i < n) && arr[i] < arr[i+1]) // (i < n) because the indexing is till (n-1) and arr[i] < arr[i+1] because to get the maximum child value...
			i++;
		if(val >= arr[i])
			break;
		arr[pos] = arr[i]; // Putting the value in parent position of its max. child value...or its like swapping...but not exactly swapping
		pos = i;
	}
	arr[pos] = val;
}


// LEARN makeHeap() function and restoreDown() only....and it could be used in insertion deletion or anything.....
void makeHeap(int arr[], int n)
{
	int i;
	for(i=(n/2); i>=0; i--)
	{
		restoreDown(i, arr, n);
	}
	printf("Heap Formed:   ");
	printArr(arr, n);
	printf("\n n = %d", n);
}


