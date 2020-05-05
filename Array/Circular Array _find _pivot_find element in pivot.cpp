#include<iostream>
using namespace std;

// Returns count of rotations for an array which is first sorted in ascending order, then rotated
int countRotationsLinearSearch(int arr[], int n)//o(n)
{
    // We basically find index of minimum element
    int min = arr[0], min_index;
    for (int i=0; i<n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int countRotationsBinarySearch(int arr[], int start, int end)//o(log n)
{
    // This condition is needed to handle the case when the array is not rotated at all

    if (arr[start] <=arr[end])
        return start;
    while(start<=end)
    {
        int mid = (start + end)/2;

        // check if mid+1 is pivot
        if (mid < end && arr[mid] > arr[mid+1])
        {
            return (mid + 1);
        }
        else if (arr[start] <= arr[mid])
        {
            // If array[start] <= array[mid],
            // it means from start to mid, all elements are in sorted order,
            // so pivot will be in second half
            start = mid + 1;
        }
        else
        {
            // else pivot lies in first half, so we find the pivot in first half
            end = mid - 1;
        }

    }
    return 0;
}


int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l+h)/2;
    if (arr[mid] == key)
        return mid;

    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid-1, key);
        /*If key not lies in first half subarray,
          Divide other half  into two subarrays,
          such that we can quickly check if key lies
          in other half */
        return search(arr, mid+1, h, key);
    }

    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);

    return search(arr, l, mid-1, key);
}

int main( )
{int key;
    int arr[] = {20,21,24,1,2,3,6,12,15,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countRotationsBinarySearch(arr,0,n-1)<<endl;
    cout << countRotationsLinearSearch(arr, n)<<endl;
    cin>>key;
    int i = search(arr, 0, n-1, key);

    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";

    return 0;
}
