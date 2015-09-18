//
//  AlgoQuestions2.h
//  Algorithms
//
//  Created by Preethish Shetty on 9/17/15.
//  Copyright (c) 2015 Preethish Shetty. All rights reserved.
//

#include<iostream>
using namespace std;

/* Q : All permutations of a string. 
   = Time Complexity : O(n*n!)
*/
void swap(char *x,char *y)
{
    char temp=*x;
    *x=*y;
    *y=temp;
}


void allPermutation(char *A,int left,int right)
{
    if(left==right)
    {
        cout<<A<<"\n";
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(A+i,A+left);
            allPermutation(A,left+1,right);
            swap(A+i,A+left);
        }
    }
}

void allPermuationDriver()
{
    char input[]="ABCD";
    unsigned long size=strlen(input);
    cout<<"Input String : "<<input<<"\n";
    cout<<"All Permutations : \n";
    allPermutation(input,0,(int)size-1);
}


/* Q : Array contains all numbers in multiple of 3s and 1 element with count 1. Find the element
    = Time Complexity : O(n)
    = Space Complexity : O(1)
 
    = Find the sum of bits and %3
    = OR that with the result to get the result
*/

void findTheLoneWolf(int *A,int n)
{
    int result=0;
    int sum=0;
    int x=0;
    
    
    for(int i=0;i<32;i++)
    {
        sum=0;
        x=1>>i;
        
        for(int j=0;j<n;j++)
        {
            if(A[j] & x)
                sum++;
        
        }
        
        if(sum%3)
            result=result | x;
    }

    cout<<"The Lone Wolf is  :"<<result;

}

void findTheLoneWolfDriver()
{
    int A[]={5,5,5,1,3,3,3};
    int size = sizeof(A)/sizeof(A[0]);
    
    findTheLoneWolf(A,size);
}


/* Q : Find the odd occuring element in an array
    Time Complexity : O(n)
    Aux Space : O(1)
 
    =XOR even number of times == 0
    =XOR odd number of times  == n
*/

void findOddManOut(int *A,int n)
{
    int sum=0;
    
    for(int i=0;i<n;i++)
        sum=sum^A[i];
    
    cout<<"\nThe Odd Man is : "<<sum;

}

void findOddManOutDriver()
{
    int A[]={1,1,3,4,4,99,3,2,2,5,6,5,6};
    int size=sizeof(A)/sizeof(A[0]);
    
    
    findOddManOut(A,size);
}
