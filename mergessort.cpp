#include <iostream>
using namespace std;

void mergeSort(int *a, int start, int end, int mid)
{
    int i = start;
    int j = mid + 1;
    int temp[end-start+1];
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = start; i <= end; i++)
    {
        a[i] = temp[i-start];
    }
}

void divide(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end)/2;
    divide(arr, start, mid);
    divide(arr, mid + 1, end);
    mergeSort(arr, start, end, mid);
}

int main()
{
    int n, i;
    cout << "\nEnter the number of data element to be sorted: ";
    cin >> n;
    
    int arr[n];
    for(i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    divide(arr, 0, n-1);
    
    // Printing the sorted data.
    cout<<"\nSorted Data ";
    for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];
    
    return 0;
} 
