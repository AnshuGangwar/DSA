
#include <iostream>
#include <stdlib.h>
using namespace std;

//Insertion sort -O(N^2)
void insertionSort(int arr[], int size)
{
    //int i, key, j;
    for (int i = 1; i < size; i++)
    {int value ,j;
        value = arr[i];
        j = i ;//j=hole
        while (j > 0 && arr[j-1] > value) /* Move elements of arr[0..i-1], that are greater than key, to one position ahead  of their current position */
        {
            arr[j] = arr[j-1];//all the value before hole is >>  hole value ,shift right
            j = j - 1;
        }
        arr[j] = value;
    }
    cout<<"after Insertion sort with time complexity O(n^2)"<<endl;
    for (int i=0; i< size; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
void SelectionSort(int arr[], int size)//O(n^2)
{
    for (int i=0; i< (size - 1); i++)
    {
        int min = i;
        for (int j= (i+1); j< size; j++)
        {
            if(arr[min]>arr[j])
                min = j;//update index of minimum value
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    cout<<"after Selection sort with time complexity O(n^2)"<<endl;
    for (int i=0; i< size; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void Bubblesort(int arr[], int size)//O(n^2)//flag for best case -O(n) sorted
{
    for (int i=0; i< (size - 1); i++)
    {   // int flag=0;
        for (int j=0;j< size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
               // flag=1;
                }
               // if(flag==0) break;
        }

    }
    cout<<"after Bubble sort with time complexity O(n^2)"<<endl;
    for (int i=0; i< size; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}


int Binarysearch(int A[], int key, int l, int h,bool searchFirst){
int result=-1;
    while(l<=h)
    {
       int mid=(l+h)/2;
        if (key==A[mid])
        {//cout << "The key after Binary search found at :" <<mid+ 1<<endl;
            //return ;
            result = mid;
            if(searchFirst){
                h =mid-1;//for finding the first occurance-go search towards left
            }
            else
                l=mid+1;//for finding the last occurance-go search towards right
        }
        else if (key<A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }

    }
    return result;
}

//Linear Search
void LinearSearch(int A[],int key, int n)
{
    for(int i=0; i< n; i++)
    {
        if (key==A[i])
        {
            cout << "Linear search key matched at : " <<i+1<< endl;
            return;
        }
    }
    cout << "key not  matched " << endl;
}

int main()
{
    int A[]= {2,26,46,1,26,5,6,7,26,20};
    int key,l=0,h;
    h = sizeof(A)/sizeof(A[0]);
    cout << "Enter the key value to be search" << endl;
    cin >> key;
    insertionSort(A,h);
    int first = Binarysearch(A, key, l,h,true);
    int last =  Binarysearch(A, key, l,h,false);
    if(first == -1){
        cout<<"Key not matched"<<endl;
    }else{
        cout<<"No of occurrences in array is : "<<last-first+1<<endl;
    }
    LinearSearch(A, key, h);
    SelectionSort(A,h);
    LinearSearch(A, key, h);
    Bubblesort(A,h);
    Binarysearch(A, key, l,h,true);


    return 0;
}
