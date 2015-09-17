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



/* Q :Median of sorted Arrays :
    =Method 1 :
    - Go till count<=n and merge the two arrays
    - At this point either i==n or j==n or a mix. Find appropriate m & n and take average
 
    =Method 2 :
    - Find medians of the two arrays; compare them and accordingly divide the input array into smaller chunks
 */

float median(int *A,int n)
{
    if(n%2==0)
        return ((float)A[n/2]+A[n/2-1])/2;
    else
        return A[n/2];
}


// Time Complexity : O(n)
float MedianSortedArrayMethod1(int *A,int *B,int n)
{
    int i=0;
    int j=0;
    int prev=-1;
    int cur=-1;
    
    for(int count=0;count<n;count++)
    {
        if(i==n)
        {   prev=cur;
            cur=B[0];
            break;
        }
    
        if(j==n)
        {   prev=cur;
            cur=A[0];
            break;
        }
        
        if(A[i]<B[j])
        {
            prev=cur;
            cur=A[i];
            i++;
        }
        
        if(A[i]>B[j])
        {
            prev=cur;
            cur=B[j];
            j++;
        }
        
    }
    
    return ((float)prev+cur)/2;
}

float MedianSortedArrayMethod2(int *A,int *B,int n)
{
    float m1,m2;
    
    if(n<=0)
        return -1;
    
    if(n==1)
        return ((float)A[0]+B[0])/2;
    
    if(n==2)
        return ((float)max(A[0],B[0])+min(A[1],B[1]))/2;
    
    m1=median(A,n);
    m2=median(B,n);
    
    if(m1==m2)
        return m1;
    
    if(m1<m2)
    {
        if(n%2==0)
            return MedianSortedArrayMethod2(A+n/2-1,B,n/2+1);
        else
            return MedianSortedArrayMethod2(A+n/2,B,n/2+1);
    }
    
    if(m1>m2)
    {
        if(n%2==0)
            return MedianSortedArrayMethod2(A,B+n/2-1,n/2+1);
        else
            return MedianSortedArrayMethod2(A,B+n/2,n/2+1);
    }
    
    return -1;
}

float MedianSortedArrayMethod3(int *A,int *B,int left,int right,int n)
{
    int i,j;
    //Reached end of array
    if(left>right)
        return MedianSortedArrayMethod3(B, A, 0, n-1,n);
    
    i=(left+right)/2;
    j=n-1-i;
    
    if(A[i]>B[j] && (j==n-1 || A[i]<=B[j+1]))
    {
        //Here A[j] is one of the medians. The other one needs to be decided.
        if(i==0 || B[j]>A[i-1])
            return ((float)A[i]+B[j])/2;
        else
            return ((float)A[i]+A[i-1])/2;
    }
    else //A[i] greater than B[j] so check elements after A[i] & B
        if(A[i]>B[j] && j!=n-1 && A[i] > B[j+1])
            return MedianSortedArrayMethod3(A,B, left, i-1,n);
    else    //A[i] smaller than B[j] so check elements before A[i]
        return MedianSortedArrayMethod3(A,B,i+1,right,n);

}

void MedianSortedArrayDriver()
{
    int A[]={1,2,3,4,5};
    int B[]={6,7,9,10,12};
    
    cout<<"Median is :"<<MedianSortedArrayMethod1(A,B,5);
    
    cout<<"\nMedian (Method 2) is : "<<MedianSortedArrayMethod2(A,B,5);
    
    cout<<"\nMedian (Method 3) is : "<<MedianSortedArrayMethod3(A,B,0,4,5);
}



/*Q : Key in sorted array ( but shifted either to +1 position or -1 position 
 =Time Complexity : O(logn)
 */

int BinarySearchModed(int *A,int left,int right,int key)
{
    if(left<right)
    {
        //int mid=(left+right)/2;
        
        int mid = left + (right-left)/2;
        
        if(A[mid]==key)
            return mid;
        if(mid-1>left && A[mid-1]==key)
            return mid-1;
        if(mid+1<right && A[mid+1]==key)
            return mid+1;
        
        if(A[mid]<key)
            return BinarySearchModed(A,mid+2,right,key);
        else
            return BinarySearchModed(A,left,mid-2,key);
    
    }

    return -1;
}

void BinarySearchModedDriver()
{
    int A[] ={10, 3, 40, 20, 50, 80, 70};
    int key=40;
    
    for(int i=0;i<7;i++)
        cout<<A[i]<<" ";
    
    cout<<"\nIndex of Key is : "<<BinarySearchModed(A,0,6,key);
}


/* Q : K closest points in a sorted array 
    =Binary Search : Time Complexity = O(logn)
    =Search of indciecs : Time Complexity = O(k)
 */

int BinarySearch(int *A,int left,int right,int key)
{
    if(left<=right)
    {
        int mid = left+(right-left)/2;
        
        if(A[mid]==key)
            return mid;
        
        if(A[mid]>key)
            return BinarySearch(A,left,mid-1,key);
        else
            return BinarySearch(A,mid+1,right,key);
    }

    return -1;
}

void KClosestPoints(int *A, int k, int key,int size)
{
    //Binary Search to find the point
    int index = BinarySearch(A,0,size-1,key);

    int l=index-1;
    int r=index+1;
    int count=0;
    
    for(int i=0;i<k;i++)
    {
        if(l>0 && (key-A[l] < A[r]-key) && r<size)
        {
            cout<<"\nElement "<<++count<<" : "<<A[l--];
            continue;
        }
        
        if(l>0 && (key-A[l] > A[r]-key) && r<size)
        {
            cout<<"\nElement "<<++count<<" : "<<A[r++];
            continue;
        }
        
        if(l==0)
        {
            cout<<"\nElement "<<++count<<" : "<<A[r++];
            continue;
        }
        
        if(r==0)
        {
            cout<<"\nElement "<<++count<<" : "<<A[l--];
            continue;
        }
    }
}

void KClosestPointsDriver()
{
    int A[] ={12,16,22,30,35,39,42,45,48,50,58};
    int k = 4;
    int key = 35;
    int size = sizeof(A)/sizeof(int);

    cout<<"The closests points are : ";
    KClosestPoints(A,k,key,size);
}


/* Q : Sorting 0-n^2-1 in Linear time 
  == Moded version of Radix Sort
 
 Radix vs QuickSort 
 - If we have log2 n bits for every digit - Radix > Quick
 - Constant factors hidden in Radix are greater
 - Quick sort uses cache more effectively
 - Radix uses counting sort as a subroutine which uses aux space
 */

void countSortModed(int *A,int n,int exp)
{
    int count[n];
    int output[n];
    for(int i=0;i<n;i++)
        count[i]=0;
    
    for(int i=0;i<n;i++)
        count[(A[i]/exp)%n]++;
    
    for(int i=1;i<n;i++)
        count[i]+=count[i-1];
    
    for(int i=n-1;i>=0;i--)
    {
        int index=count[(A[i]/exp)%n];
        count[(A[i]/exp)%n]--;
        
        output[index-1]=A[i];
    }
    
    for(int i=n-1;i>=0;i--)
        A[i]=output[i];

}


void sortLinear(int *A,int size)
{
    countSortModed(A,size,1);
    countSortModed(A,size,size);
    
    /* In actual Radix Sort 
       =Time Complexity : O(d*(n+b)) where d=number of digits == logb(k) where k is the max number
       = O(logb k*(b+n) ) 
       = To get a linear time - make logb k = 1 which is true for b==k
     int m = getMax(A,size);
     
     for(int exp=1;m/exp>0;exp*=10)
        countSort(A,size,exp);
    */
}


void RadixSortModedDriver()
{
    int A[] = { 13,2,5,14,20,7};
    int size = sizeof(A)/sizeof(int);
    cout<<"SIZE : "<<size;
    
    cout<<"\nBefore Sorting : ";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    
    sortLinear(A,size);
    
    cout<<"\nThe sorted array is : ";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";

}


/* Q : Finding sum of 2 numbers in an array closest to X 
    = Maintain 2 indices L & R and move both ways checking for the minDiff
 */

void FindClosestSumPair(int *A,int n,int key)
{
    int l=0;
    int r=n-1;
    int minDiff = INT16_MAX;
    int left=-1;
    int right=-1;
    
    while(r>l)
    {
        if(abs(A[l]+A[r]-key)<minDiff)
        {
            minDiff=abs(A[l]+A[r]-key);
            left=l;
            right=r;
        }
        
        if(A[l]+A[r]<key)
            l++;
        else
            r--;
    }
    
    cout<<"\nPair Closest to : "<<key<<" is : "<<A[left]<<","<<A[right];
}

void FindClosestSumPairDriver()
{
    int A[] = {2,4,6,7,8,12,25,40,32,56};
    int size = sizeof(A)/sizeof(A[0]);
    int key = 39;
    
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    
    FindClosestSumPair(A,size,key);
}

/* Q : Finding sum of 2 numbers in 2 arrays closest to X
    = Same logic as the above code. Maintain indices of the two arrays
    or
    = Merge the two arrays like in merge sort & maintain another array to keep track of the indices
 */

void FindClosestSumPair2Arrays(int *A,int *B,int n,int m,int key)
{
    int l1=0;
    int r2=m-1;
    
    int minDiff = INT16_MAX;
    int left=-1;
    int right=-1;
    
    while(l1<n && r2>=0)
    {
        if(abs(A[l1]+B[r2]-key)<minDiff)
        {
            minDiff=abs(A[l1]+B[r2]-key);
            left=l1;
            right=r2;
        }
        
        if(A[l1]+B[r2]<key)
            l1++;
        else
            r2--;
    }
    
    cout<<"\nPair Closest to : "<<key<<" is : "<<A[left]<<","<<B[right];
}


void FindClosestSumPair2ArraysDriver()
{
    int A[] = {2,4,6,7,8,12,25,40,32,56};
    int B[] = {1,2,3,4};
    
    int size1 = sizeof(A)/sizeof(A[0]);
    int size2 = sizeof(B)/sizeof(B[0]);
    
    int key = 39;
    
    cout<<"Key : "<<key<<"\n";
    
    for(int i=0;i<size1;i++)
        cout<<A[i]<<" ";
    
    cout<<"\n";
    
    for(int i=0;i<size2;i++)
        cout<<B[i]<<" ";
    
    FindClosestSumPair2Arrays(A,B,size1,size2,key);
    
}





