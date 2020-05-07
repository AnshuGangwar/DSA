#include<stdio.h>
#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp;
    temp= *a;
     *a=*b;
     *b=temp;

}
void bubblesort(int arr[],int n){

    for(int i=0;i<n;i++)  {
        for(int j=0;j<n-1;j++)
        if(arr[j]>arr[j+1])
            swap(&arr[j], &arr[j+1]);
    }

}


void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}
int main()
{
	int arr[] = {5 ,7, 4 ,3 ,2 ,6,8 ,10,1};
	int n = sizeof(arr)/sizeof(arr[0]); // length of the array
	bubblesort(arr,n);
	printarray(arr,n);
	return 0;
}

