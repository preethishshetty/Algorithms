//
//  main.cpp
//  Algorithms
//  Created by Preethish Shetty on 9/9/15.
//  Copyright (c) 2015 Preethish Shetty. All rights reserved.
//

#include <iostream>
using namespace std;


//=======SORT ALGORITHMS=======
/*Bubble Sort
 - Time Complexity : O(n^2)
 - Time Complexity ( optimized ) - Best Case : O(n) when already sorted
 - Space Complexity : Aux O(1)
 - The optimization stops when a row is already sorted thereby improving the best case condition
 - Use : Graphical systems
*/
void BubbleSort(int A[],int n)
{
    int i=0,j=0,temp=0;
    bool swapped = false;
    
    for(i=0;i<n-1;i++)
    {
        swapped=false;
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                swapped=true;
            }
        }
        if(swapped==false)
            break;
    }
}

/*Insertion Sort
 - Time Complexity : O(n^2)
 - Space Complexity : Aux O(1)
 - Boundary Case : Max time when sorted in reverse order, Least Time when already sorted O(n)
 - Use : When almost sorted and few elements not sorted
*/
void InsertionSort(int A[],int n)
{
    int i=0,j=0;
    int key=0;
    
    for(i=1;i<n;i++)
    {
        key=A[i];
        for(j=i-1;j>=0;j--)
        {
            if(A[j]>key)
                A[j+1]=A[j];
            else
                break;
        }
        
        A[j+1]=key;
    }
}

/*Selection Sort
 - Time Complexity : O(n^2)
 - Space Complexity : Aux O(1)
 - Use : Useful when memory swaps are expensive as it makes at most N swaps
*/

void SelectionSort(int A[],int n)
{
    int i=0,j=0,min=0,temp=0;
    
    for(i=0;i<n;i++)
    {   min=i;
        for(j=i;j<n;j++)
        {
            if(A[j]<A[min])
                min=j;
        }
        temp=A[min];
        A[min]=A[i];
        A[i]=temp;
    }
}

/* Merge Sort
 - Time Complexity : O(NLogN )  => Using Master Theorem T(n) = 2T(n/2) + O(n) 
 - Space Complexity : O(n)
 - Uses : Faster algorithm as compared to the other N^2 counterparts
*/
void Merge(int A[],int left,int mid,int right)
{
    int B[10];
    for(int i=left;i<=right;i++)
        B[i]=A[i];
    
    //Indices for A
    int i=left;
    int j=mid+1;
    //Index for B
    int k=left;

    while(i<=mid&&j<=right)
    {
        if(B[i]<B[j])
        {
            A[k]=B[i];
            k++;
            i++;
        }
        else
        {
            A[k]=B[j];
            k++;
            j++;
        }
    }
    
    while(i<=mid)
    {
        A[k]=B[i];
        k++;
        i++;
    }
    
    while(j<=right)
    {
        A[k]=B[j];
        k++;
        j++;
    }

    cout<<"\nProgress : ";
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
}


void MergeSort(int A[],int left,int right)
{
    if(left<right)
    {
        int mid=(right+left)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}

//=======SORT ALGORITHMS=======

int main(int argc, const char * argv[]) {
    //Initializations
    int A[]={5,12,3,6,2,61,1,45,4,24};      //Count == 10
    int i=0;
    
    //Algorithms
    /*Bubble Sort*/
    cout<<"Before Sort -> :";
    for(i=0;i<10;i++)
        cout<<A[i]<<" ";
    
    
    //cout<<"Bubble Sort : ";
    //BubbleSort(A,10);
    
    //cout<<"\nInsertion Sort : ";
    //InsertionSort(A,10);
    
    //cout<<"\nSelecttion Sort : ";
    //SelectionSort(A,10);
    
    cout<<"\nMerge Sort : ";
    MergeSort(A,0,9);
    
    cout<<"\nAfter Sort -> :";
    for(i=0;i<10;i++)
        cout<<A[i]<<" ";
    
    
    return 0;
}
