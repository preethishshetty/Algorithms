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