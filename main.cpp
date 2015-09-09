//
//  main.cpp
//  Algorithms
//
//  Created by Preethish Shetty on 9/9/15.
//  Copyright (c) 2015 Preethish Shetty. All rights reserved.
//

#include <iostream>
using namespace std;


void BubbleSort(int A[],int n)
{
    int i=0,j=0,temp=0;
    
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }

}




int main(int argc, const char * argv[]) {
    // insert code here...
    cout<< "Hello Moto!\n";
    
    int A[]={5,12,3,6,2,61,1};
    int i=0;
    int N=0;
    
    cout<<"Enter the number of numbers : ";
    cin>>N;
    
    cout<<"Bubble Sort : ";
    cout<<"Before Sort -> :";
    for(i=0;i<7;i++)
        cout<<A[i]<<" ";
    
    BubbleSort(A,7);
    
    cout<<"\nAfter Sort -> :";
    for(i=0;i<7;i++)
        cout<<A[i]<<" ";
    
    
    return 0;
}
