//
//  AlgoQuestions.cpp
//  Algorithms
//
//  Created by Preethish Shetty on 9/11/15.
//  Copyright (c) 2015 Preethish Shetty. All rights reserved.
//
#include <iostream>
using namespace std;

/*Some Algorithm Questions*/


/*Q: Find smallest element in a sorted (asc)+rotated array
  ==Works for inputs without duplicates==
 */
int findMin(int *array,int left,int right)
{
    //single element
    if(left==right)
        return array[left];
    
    //No Rotation
    if(right<left)
        return array[0];
    
    int mid=(left+right)/2;

    if(mid>left && array[mid]<array[mid-1])
        return array[mid];
    
    if(mid<right && array[mid+1]<array[mid])
        return array[mid+1];
    
    if(array[mid]<array[right])
        return findMin(array,left,mid-1);
    else
        return findMin(array,mid+1,right);
    
}

void findMinDriver()
{
    cout<<"Finding the smallest element : ";
    int B[]={3,4,5,1,2};
    
    for(int i=0;i<5;i++)
      cout<<B[i]<<" ";
    cout<<"\nMinumum Value : "<<findMin(B,0,4);
}


/*Q: Find peak element in an array ( not smaller than its neighbors => greater than equal to )
 == Haven't boundary cased it.
*/

int findPeakRecursive(int *A,int left,int right)
{
    int mid=(left+right)/2;
    if(A[mid]>=A[mid-1] && A[mid]>=A[mid+1])
        return A[mid];
    
    if(A[mid]<A[mid-1])
        return findPeakRecursive(A,left,mid);
    else
        return findPeakRecursive(A,mid,right);
    
    return -1;
}

int findPeak(int *A,int size)
{
    int left=0;
    int right=size-1;
    
    if(size==1)
        return A[0];
    
    if(A[0]>=A[1])
        return A[0];
    
    if(A[size-1]>=A[size-2])
        return A[size-1];
    
    return findPeakRecursive(A,left,right);
}

void findPeakDriver()
{
    int A[]={1,4,4,3,6,2,1};
    cout<<"Elements are : ";
    for(int i=0;i<7;i++)
        cout<<A[i]<<" ";
    cout<<"Peak Element is : "<<findPeak(A,7);
    
}


