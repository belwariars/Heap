#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int start)
{
	int largest = start;
	int l = 2*start +1;
	int r = 2*start +2;
	
	if(l<n && arr[l] > arr[largest])
	{
		largest = l;
	}
	
	if(r<n && arr[r] > arr[largest])
	{
		largest = r;
	}
	
	if(largest!=start)
	{
		swap(arr[largest], arr[start]);
		heapify(arr, n, largest); // heapify the affected sub-tree
	}
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapsort(int arr[], int n)
{
	int i;
	for(i=(n/2-1); i>=0; i--)
	{
		heapify(arr, n, i);
	}
	printArray(arr, n); //Heap-Is Build
	
	for (i=n-1; i>=0; i--) //Remove the root every time and keep it in the last...thus sorting
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    
    printf("\n\n");
    printf("Sorted Array:  ");
    
    printArray(arr, n);
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    heapsort(arr, n);
	return 0;
}
