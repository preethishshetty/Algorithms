//
//  DynamicProgramming.h
//  Algorithms
//
//  Created by Preethish Shetty on 10/8/15.
//  Copyright © 2015 Preethish Shetty. All rights reserved.
//

#include<iostream>
using namespace std;


/*Subset Sum Problem :

*/


bool isSubSetSum(int set[],int n,int sum)
{
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;
    
    if(set[n-1]>sum)
        return isSubSetSum(set,n-1,sum);
    else
        return isSubSetSum(set,n-1,sum)||isSubSetSum(set,n-1,sum-set[n-1]);

}



void isSubSetSumDriver()
{
    int set[]={3,1,4,5,6,8,2,13};
    int sum = 18;
    
    cout<<"IS SUBSET SUM : "<<isSubSetSum(set,8,sum);


}