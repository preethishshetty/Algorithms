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

