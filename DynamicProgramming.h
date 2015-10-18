//
//  DynamicProgramming.h
//  Algorithms
//
//  Created by Preethish Shetty on 10/8/15.
//  Copyright © 2015 Preethish Shetty. All rights reserved.
//

#include<iostream>
#include<string>
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

int min(int x,int y,int z)
{
    if(x<=y)
        if(x<=z)
            return x;
        else
            return z;
    else
        if(y<=z)
            return y;
        else
            return z;
}

int uglyNumb(int N)
{
    int ugly[N];
    for(int i=0;i<N;i++)
        ugly[i]=0;
    
    ugly[0]=1;
    int i2=0,i3=0,i5=0;
    
    int i=1;
    
    while(i<=N)
    {
        int index = min(ugly[i2]*2,ugly[i3]*3,ugly[i5]*5);
        
        if(index == ugly[i2]*2)
            i2++;
        if(index == ugly[i3]*3)
                i3++;
        if(index == ugly[i5]*5)
                i5++;
        
        ugly[i]=index;
        i++;
    }
    
    return ugly[i-1];
}




void UglyNumberDriver()
{
    for( int i=0;i<=10;i++)
        cout<<"\nUgly Num is : "<<uglyNumb(i);
}


int LIS(int *A,int N)
{
    int LIS[N];
    for(int i=0;i<N;i++)
        LIS[i]=1;
    
    for(int i=1;i<N;i++)
        for(int j=0;j<i;j++)
            if(A[i]>A[j] && LIS[i]<LIS[j]+1)
                LIS[i]=LIS[j]+1;
    
    int max=0;
    for(int i=0;i<N;i++)
        if(max<LIS[i])
            max=LIS[i];


    return max;
}


void LISDriver()
{
    int A[]={10,12,2,4,5,6,11,13,1,19,25,23,26,30};
    cout<<"\nLongest Increasing Subsequence Length: "<<LIS(A,sizeof(A)/sizeof(A[0]));

}

int LCS(char *str1,char *str2,int m,int n)
{
    int LCS[m+1][n+1];
    
    
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                LCS[i][j]=0;
                continue;
            }
            
            if(str1[i-1]==str2[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
            }
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    
    
    for(int i=0;i<=m;i++)
    {
        cout<<"\n";
        for(int j=0;j<=n;j++)
            cout<<LCS[i][j]<<"\t";
    }
    
    return LCS[m][n];
}


void LCSDriver()
{
    //char str1[]="ABEXKQE";
    //char str2[]="ACEYYKEWE";
    
    char str1[]="ABCD";
    char str2[]="EFGABCD";
    
    cout<<"\nLength of Longest Common Subsequence : "<<LCS(str1,str2,(int)strlen(str1),(int)strlen(str2));
}
