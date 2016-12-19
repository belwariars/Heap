#include <bits/stdc++.h>
using namespace std;

void restoreDown(int arr[], int pos, int n)
{
	int val = arr[pos];
	int i = 2*pos;
	while(i<n &&  (arr[i] < arr[i+1]))
	{
		i++;
		if(val>=arr[i])
		{
			break; // if the max child is smaller then no modification needed in the array
		}
		else
		{
			arr [pos] = arr [i] ;
			pos = i ;
		}
	}
	
	arr[pos] = val;
}

void restoreUP(int n, int arr[])
{
	int val = arr[n];
	printf("\nval= %d\n", val);
	while(arr[n/2] <= val)
	{
		arr[n] = arr[n/2];
		printf("%d ", arr[n/2]);
		n = n/2;
	}
	
	arr[n] = val;
}

void makeheap(int arr[], int n)
{
	int i;
	for(i=(n/2); i>=0; i--)
	{
		restoreDown(arr, i, n);
	}
}

void addHeap(int arr[], int *n, int add)
{
	(*n)++;
	arr[*n] = add;
	restoreUP(*n, arr);
}

int main()
{
	int arr [20] = {7, 10, 25, 17, 23, 27, 16,
					19, 37, 42, 4, 33, 1, 5, 11 };
	int i, n = 15;
	
	makeheap(arr, n);
	
	printf ( "Heap:\n" ) ;
	for ( i = 0 ; i <= n-1 ; i++ )
		printf ( "%d\t", arr [i] ) ;
		
	
	int add = 24;
	addHeap(arr, &n, add);
	
	printf ( "\n\nElement added %d.\n", add ) ;
	printf ( "\nHeap after addition of an element:\n" ) ;
	for ( i = 0 ; i <= n-1 ; i++ )
		printf ( "%d\t", arr [i] ) ;

	return 0;
}
