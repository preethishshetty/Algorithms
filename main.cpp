//
//  main.cpp
//  Algorithms
//
//  Created by Preethish Shetty on 9/9/15.
//  Copyright (c) 2015 Preethish Shetty. All rights reserved.
//

#include <iostream>
using namespace std;

/*Bubble Sort
 - Time Complexity : O(n^2)
 - Time Complexity ( optimized ) - Best Case : O(n)
 - Space Complexity : Aux O(1)
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


int main(int argc, const char * argv[]) {
    //Initializations
    int A[]={5,12,3,6,2,61,1};      //Count == 7
    int i=0;
    
    //Algorithms
    /*Bubble Sort*/
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
