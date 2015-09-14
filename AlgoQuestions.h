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
 == Time : O(logn)
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

/*Q: Find Fixed Point ( A[i]==i ) in a sorted array
 ==Time Complexity : O(logn) 
 ==Paradigm : Divide and Conquer
*/
int findFixedPoint(int *A,int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        if(A[mid]==mid)
            return mid;
        
        if(A[mid]<mid)
            return findFixedPoint(A,mid+1,right);
        else
            return findFixedPoint(A,left,mid-1);

    }

    return -1;
}


void findFixedPointDriver()
{
    int A[]={-10,0,1,3,6,9,21};
    cout<<"Elements are : ";
    for(int i=0;i<7;i++)
        cout<<A[i]<<" ";
    cout<<"\nFixed Point Element is : "<<findFixedPoint(A,0,6);
    
}


/* Q: Length of minimum subarray that must be sorted to sort entire array
 */

int minSubArray(int *A,int size)
{

    int i=0;
    int s=-1,e=-1;
    for(i=0;i<size-1;i++)
    {
        if(A[i]>A[i+1])
        {
            s=i;
            break;
        }
    }

    if(i==size)
        return 0;
    
    for(i=size-1;i>0;i--)
    {
        if(A[i]<A[i-1])
        {
            e=i;
            break;
        }
    }
    
    int min=s;
    int max=e;
    
    for(i=s+1;i<e;i++)
    {
        if(A[i]<A[min])
            min=i;
        if(A[i]>A[max])
            max=i;
    }
    
    for(i=0;i<s;i++)
    {
        if(A[i]>A[min])
        {
            s=i;
            break;
        }
    }
    
    for(i=size-1;i>e;i--)
    {
        if(A[i]<A[max])
        {
            e=i;
            break;
        }
    }

    cout<<"\n=Start Index : "<<s<<"-> "<<A[s];
    cout<<"\n=End Index : "<<e<<" -> "<<A[e];
    return e-s+1;
}

void minSubArrayDriver()
{
    int A[]={10,12,20,30,25,40,32,31,35,50,60,70};
    cout<<"Elements are : ";
    for(int i=0;i<12;i++)
        cout<<A[i]<<" ";
    int len =minSubArray(A,12);
    cout<<"\nLength : "<<len;
}


/* == Divide and Conquer == */

/* Q: Power(x,y) 
    Time Complexity : O(logn)
 */

float pow(float x,int y)
{
    float temp;
    if(y==0)
        return 1;
    
    temp=pow(x,y/2);
    
    if(y%2==0)
        return temp*temp;
    else
    {
        if(y>0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }


}

void powDriver()
{
    float x=2;
    int y=5;
    
    cout<<"Power of ("<<x<<","<<y<<") = "<<pow(x,y);
    
}
