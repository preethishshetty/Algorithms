//
//  main.cpp
//  Algorithms
//  Created by Preethish Shetty on 9/9/15.
//  Copyright (c) 2015 Preethish Shetty. All rights reserved.
//

#include <iostream>
#include "AlgoQuestions.h"
#include "AlgoQuestions2.h"
#include "DynamicProgramming.h"
#include "LinkedList.h"
#include "Graphs.h"
#
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

//Floating point compatible ( for bucket sort )
void InsertionSort(float *A,int n)
{
    int i=0,j=0;
    float key=0;
    
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


/* Heap Sort
   Time Complexity :
    = Heapify : O(logn)
    = BuildHeap : O(n)
    = Total : O(nlogn)
 
    -In place alogrithm
*/

struct MaxHeap
{
    int size;
    int *array;
};

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//Performs Heapify. Finds if any child is greater and if so swaps and heapifies the swapped node
void maxHeapify(struct MaxHeap *maxHeap,int index)
{
    int maxVal=index;
    int left=index*2+1;
    int right=index*2+2;
    
    if(left<maxHeap->size && maxHeap->array[left] > maxHeap->array[maxVal])
        maxVal=left;
    
    if(right<maxHeap->size && maxHeap->array[right] > maxHeap->array[maxVal])
        maxVal=right;
    
    if(maxVal!=index)
    {
        swap(&maxHeap->array[maxVal],&maxHeap->array[index]);
        maxHeapify(maxHeap,maxVal);
    }
    
}

//Builds maxHeap from input. Performs heapify from last parent upwards
struct MaxHeap* buildHeap(int *array,int size)
{
    struct MaxHeap *maxHeap = new struct MaxHeap[sizeof(struct MaxHeap)];
    maxHeap->size=size;
    maxHeap->array=array;
    
    //Make the input array into a Max Heap (start from last parent node)
    for(int i=(maxHeap->size-2)/2;i>=0;i--)
        maxHeapify(maxHeap,i);
    
    return maxHeap;
}

//Builds Heap and swaps out largest element with the last element and heapifies again
void HeapSort(int *array,int size)
{
    struct MaxHeap *maxHeap = buildHeap(array,size);
    
    while(maxHeap->size>1)
    {
        swap(&maxHeap->array[0],&maxHeap->array[maxHeap->size-1]);
        maxHeap->size--;
        
        maxHeapify(maxHeap,0);
    }
}


/* Quick Sort :
    Time Complexity :
    -Best Case : (Always picks middle elemenet  : O(nlogn)  << 2T(n/2)+O(n) >>
    -Worst Case : (Already sorted, picks greatest/smallest) : O(n^2) 
    -Average Case : O(nlogn) 
 
 Use : 
 - Faster in practice than Merge Sort
 - Merge is used for larger data sets and external sorting
 
*/

int partition(int *array,int left,int right)
{
    //First element is selected as pivot
    int pivot=array[left];
    int i=left;
    int j=right;
    
    while(i<j)
    {
        while(array[i]<=pivot && i<=right)
            i++;
    
        while(array[j]>pivot && j>0)
            j--;
        
        if(i>=j)
            break;
        
        if(i<j)
        {  swap(&array[i],&array[j]);
            i++; j--;
        }
    }
    swap(&array[j],&array[left]);
    return j;
}

/* Code from Coreman : 
 int partition(int *array,int left, int right)
 {
    int pivot=array[last];
    int i=left-1;
 
    for(int j=left;j<=right-1;j++)
    {
        if(array[j]<=pivot)
        { i++;
          swap(&array[i],&array[last]);
        }
    }
 
    swap(&array[i+1],&array[last];
    return (i+1);
 }
*/

void quickSort(int *array,int left,int right)
{
    if(left<right)
    {
        int p = partition(array,left,right);
        quickSort(array,left,p-1);
        quickSort(array,p+1,right);
    }

}


/* Bucket Sort
    Time Complexity :
    -O(n) - Insert into the buckets
    -O(n) - Insertion sort ( uniformly distributed )
*/

void BucketSort(float *A,int n)
{
    float B[n][n];
    int i=0,j=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            B[i][j]=0;
    
    //Inserting element to list
    for(i=0;i<n;i++)
    {
        int index=n*A[i];
        j=0;
        while(B[index][j]!=0)
            j++;
        B[index][j]=A[i];
    }
    
    //Printing List
    for(i=0;i<n;i++)
    {  cout<<"\n i="<<i<<" : ";
       for(j=0;j<n;j++)
           cout<<B[i][j]<<" ";
    }
    
    //Sorting non empty lists
    for(i=0;i<n;i++)
    {
        j=0;
        while(B[i][j]!=0)
            j++;
        
        if(j==0)
            continue;
        
        InsertionSort(B[i],j);
    }
    
    //Printing List after Insertion Sort
    cout<<"\n\nAfter Sort";
    for(i=0;i<n;i++)
    {  cout<<"\n i="<<i<<" : ";
        for(j=0;j<n;j++)
            cout<<B[i][j]<<" ";
    }
    
    //Concatenating
    for(int x=0,i=0;i<n;i++)
    {
        j=0;
        while(B[i][j]!=0)
        {
            A[x++]=B[i][j];
            j++;
        }
    }
    
    cout<<"\n\nFinal Result : ";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    
}


/* Counting Sort :
 Time Complexity : O(n+k) - n-> number of elements, k->range of the numbers
 Aux Space : O(n+k)
 
 Notes :
 -Efficient when the range of the data is not significantly larger than the number of inputs
 -NOT a comparison based sorting
 -Linked List will be better implementation of the Algorithm
 */

void CountingSort(int *A,int size)
{
    cout<<"\nBefore Sort :";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    
    int count[size];
    int output[size];
    for(int j=0;j<size;j++)
        count[j]=0;
    
    for(int i=0;i<size;i++)
        count[A[i]]=++count[A[i]];
    
    for(int i=1;i<size;i++)
        count[i]=count[i-1]+count[i];
    
    for(int i=size;i>=0;i--)
    {
        int index=count[A[i]];
        count[A[i]]--;
        
        output[index-1]=A[i];
    }
    
    cout<<"\n\nFinal Result :";
    for(int i=0;i<size;i++)
        cout<<output[i]<<" ";
    
}


/* Shell Sort (geeksForGeeks)
 Time Complexity : O(n^2)
 */

void ShellSort(int *A,int n)
{
    int i=0,j=0;
    for(int gap=n/2;gap>0;gap/=2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted

        for(i=gap;i<n;i++)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i

            int t=A[i];
            
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found

            for(j=i;j>=gap && A[j-gap]>t;j-=gap)
                A[j]=A[j-gap];
            
            A[j]=t;
        }
    }
}

//=======Mods to SORT ALGORITHMS=======

/* Counting Inversions :
 - Logic is that for every element j from Mid+1->Right if the element
   is lesser than an element i from Left->Mid then all elements after
   element i are greater than element j ( mid - i + 1 )
*/
int countInvMerge(int A[],int left,int mid,int right)
{
    int B[10];
    int count=0;
    
    for(int i=left;i<=right;i++)
        B[i]=A[i];
    
    //Indices for A
    int i=left;
    int j=mid+1;
    //Index for B
    int k=left;
    
    while(i<=mid && j<=right)
    {
        if(B[i]<B[j])
        {
            A[k++]=B[i++];
        }
        else
        {
            A[k++]=B[j++];
            count = count + mid-i+1;
        }
    }
    
    while(i<=mid)
        A[k++]=B[i++];
    while(j<=right)
        A[k++]=B[j++];
    
    return count;
}

int countInvMergeSort(int A[],int left,int right)
{   int x=0,y=0,z=0;
    
    if(left<right)
    {
        int mid=(left+right)/2;
        x=countInvMergeSort(A,left,mid);
        y=countInvMergeSort(A,mid+1,right);
        z=countInvMerge(A,left,mid,right);
    }
    
    return x+y+z;
}




//========MAIN FUNCTION========
int main(int argc, const char * argv[]) {
    //Initializations
    int A[]={5,12,3,6,12,61,1,45,4,10};      //Count == 10
    int i=0;
    
    //Algorithms
    /*
    cout<<"Before Sort -> :";
    for(i=0;i<10;i++)
        cout<<A[i]<<" ";
    */
    
    
    //cout<<"Bubble Sort : ";
    //BubbleSort(A,10);
    
    //cout<<"\nInsertion Sort : ";
    //InsertionSort(A,10);
    
    //cout<<"\nSelecttion Sort : ";
    //SelectionSort(A,10);
    
    //cout<<"\nMerge Sort : ";
    //MergeSort(A,0,9);
    
    //cout<<"\nCount Inversions : ";
    //cout<<countInvMergeSort(A,0,9);
    
    //cout<<"\nHeap Sort : ";
    //HeapSort(A,10);
    
    //cout<<"\nQuick Sort : ";
    //quickSort(A,0,9);
    
    //cout<<"\nShell Sort : ";
    //ShellSort(A,10);
    
    /*
    cout<<"\nAfter Sort -> :";
    for(i=0;i<10;i++)
      cout<<A[i]<<" ";
    */
    
    /* == Algorithms with specifics in input values */
    
    //float C[10]={0.12,0.72,0.19,0.14,0.62,0.71,0.69,0.34,0.32,0.42};
    //cout<<"\nBucket Sort : ";
    //BucketSort(C,10);
    
    //cout<<"Counting Sort";
    //int D[10]={1,4,1,2,5,3,2,4,8,6};
    //CountingSort(D,10);
    
    
    //findMinDriver();
    
    //findPeakDriver();
    
    //findFixedPointDriver();
    
    //minSubArrayDriver();
    
    //powDriver();
    
    //MedianSortedArrayDriver();

    //cout<<"Median : "<<median(A,10);
    
    //BinarySearchModedDriver();
    
    //KClosestPointsDriver();
    
    //RadixSortModedDriver();
    
    //FindClosestSumPairDriver();
    
    //FindClosestSumPair2ArraysDriver();
    
    //SubArrayZeroSumDriver();
   
    //allPermuationDriver();
    
    //findTheLoneWolfDriver();
    
    //findOddManOutDriver();
    
    //isNegative();
    
    //countSetBitsDriver();
    
    //AddWithoutOperatorDriver();
    
    //minimumWithoutOperatorDriver();
    
    //PointerReferenceDriver();
    
    //thisPointerTestDriver();
    
    //LinkedListTestConsole();
    
    //fibonacchiDriver();
    
    //GraphTestConsole();
    
    //isSubSetSumDriver();
    
    //CurrencyProbDriver();
    
    //UglyNumberDriver();
    
    //LISDriver();
    
    //LCSDriver();
    
    //EditDriver();

    //CoinChangeDriver();
    
    //LPSDriver();
    
    //rodCutDriver();
    
    //MergeMplusNDriver();
    
    //MaxContSumDriver();
    
    //MinSquareDriver();
    
    //minCoinDriver();
    
    //maxLenPalindromeSubstringDriver();
    
    //maxLenPalindromeSubsequnceDriver();
    
    //anagramInStringDriver();
    
    //KMPDriver();
    
    nStairProblemDriver();
    
    
    cout<<"\n\n-EndOfProgram-\n";
    
    return 0;
}
