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

void isNegative()
{
    int x=-1;
    int y=100;
    
    cout<<"NUMBERS ARE : "<<x<<" "<<y<<"\n";
    
    if( (x^y)<0)
        cout<<"NEGATIVE !";
    else
        cout<<"POSITIVE !";
    
    //Alternate Method
    // (x^y)>>32 == 1 -> Negative
    
}


/* Q : Finding number of set bits from 1->n
    Time Complexity : O(n*logn)
*/

int countSetBits(unsigned int num)
{
    unsigned int count=0;
    while(num>0)
    {
        if((num & 1)== 1)
            count++;
        
        num=num>>1;
    }
    cout<<"\nNumber of set bits : "<<count;
    
    return count;
}

void countSetBitsDriver()
{
    int n=6;
    int sumBits = 0;
    cout<<"N : "<<n<<"\n";
    for(int i=1;i<=n;i++)
       sumBits+=countSetBits(i);
    
    cout<<"\n\nNumber of set bits total : "<<sumBits;
}


/* Q : Addition without arithmatic operator 
 
 */
void AddWithoutOperator(int x,int y)
{
    while(y!=0)
    {
        int carry = x&y;
        int sum   = x^y;
        
        x=sum;
        y=carry<<1;
    }

    cout<<"Sum is : "<<x;
}

int AddWithoutOperatorRecursive(int x,int y)
{
    if(y==0)
        return x;
    else
        return AddWithoutOperatorRecursive(x^y,(x&y)<<1);

}

void AddWithoutOperatorDriver()
{
    int x=5;
    int y=4;
    
    cout<<"The numbers are : "<<x<<" "<<y<<"\n";
    
    AddWithoutOperator(x,y);
    
    cout<<"\nUsing Recursive Function : \nSum is :"<<AddWithoutOperatorRecursive(x,y);
}

void minimumWithoutOperator(int x,int y)
{
    if(!(x/y))
        cout<<"Min is : "<<x;
    else
        cout<<"Min is : :"<<y;
}

void minimumWithoutOperator(int x,int y,int z)
{
    if(!(x/y))
        if(!(y/z))
            cout<<"Min is : "<<y;
        else
            cout<<"Min is : "<<z;
    else
        if(!(x/z))
            cout<<"Min is : "<<x;
        else
            cout<<"Min is : "<<z;
}

void minimumWithoutOperatorDriver()
{
    int x=2;
    int y=3;
    int z=1;
    cout<<"\nMinimum of : "<<x<<" "<<y<<"\n";
    minimumWithoutOperator(x,y);
    cout<<"\n\nMinimum of : "<<x<<" "<<y<<" "<<z<<"\n";
    minimumWithoutOperator(x,y,z);
}
