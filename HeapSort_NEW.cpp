#include <bits/stdc++.h>
using namespace std;

void heapSort(int*, int);
void makeHeap(int*, int);
void restoreDown(int*, int, int);

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void printHeap(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int arr[20] = {7, 10, 25, 17, 23, 27, 16, 19, 37, 42, 4, 33, 1, 5, 11 };
	int n = sizeof(arr)/sizeof(arr[0]);
	heapSort(arr, 15);
	makeHeap(arr, 15);
	return 0;
}

void heapSort(int *arr, int n)
{
	makeHeap(arr, n);
	
	int i;
	for(i=n-1; i>0; i--)
	{
		swap(&arr[i], &arr[0]); // We're swapping the largest element which would be always at 0 position with the last element and heapifying it till list-1 element...
		printf("After Swapping :  ");
		printHeap(arr, n);
		printf("\n");		
		makeHeap(arr, i-1); // SEE, HERE WE DID  "makeHeap(arr, "i-1")" , (i-1) not (i)...
	}
	
	printf("HeapSort :  ");
	printHeap(arr, n);
}

void makeHeap(int arr[], int n)
{
	int i;
	for(i = (n/2-1); i>=0; i--)  // Its like makeHeap of previous only... but here start i = n/2 -1
	{
		restoreDown(arr, n, i); 
	}
	printf("Heap Formation :   ");
	printHeap(arr, n);
	printf("\n");
}

void restoreDown(int arr[], int n, int pos)
{
	int val = arr[pos];
	
	while(pos <= (n/2-1)) // Its like restoreDown of previous only... but here start i = n/2 -1
	{
		int i = 2*pos+1; // as the indexing in this program is starting from 0, so, i = 2*pos+1(left child), UNLIKE i =2*pos when indexing starts from 1.
		if((i < n) && arr[i] < arr[i+1]) 
		{
			i++;
		}
		if(val >= arr[i])
			break;
		arr[pos] = arr[i];
		pos = i;
	}
	arr[pos] = val;
}
