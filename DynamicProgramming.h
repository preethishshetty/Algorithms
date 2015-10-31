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


int LIS(int *A,int N,int &LSum)
{
    int LIS[N];
    int LISSum[N];
    
    for(int i=0;i<N;i++)
    {   LIS[i]=1;
        LISSum[i]=A[i];
    }
    
    for(int i=1;i<N;i++)
        for(int j=0;j<i;j++)
        {   if(A[i]>A[j] && LIS[i]<LIS[j]+1)
                LIS[i]=LIS[j]+1;
            
            if(A[i]>A[j] && LISSum[i]<LISSum[j]+A[i])
                LISSum[i]=LISSum[j]+A[i];
        }
    
    
    int max=0;
    for(int i=0;i<N;i++)
        if(max<LISSum[i])
            max=LISSum[i];
    LSum=max;
    
    max=0;
    for(int i=0;i<N;i++)
        if(max<LIS[i])
            max=LIS[i];
    
    return max;
}


void LISDriver()
{
    int A[]={10,12,2,4,5,6,11,13,1,19,25,23,26,30};
    int LISSum=0;
    cout<<"\nLongest Increasing Subsequence Length: "<<LIS(A,sizeof(A)/sizeof(A[0]),LISSum);
    
    cout<<"\nLongest Increasing Subsequence Sum: "<<LISSum;
    
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


int EditProblem(char *str1,char *str2,int m,int n)
{
    int DP[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            {
                if(i==0)
                    DP[i][j]=j;
                else
                    if(j==0)
                        DP[i][j]=i;
                else
                    if(str1[i-1]==str2[j-1])
                        DP[i][j]=DP[i-1][j-1];
                else
                    DP[i][j]=1+ min(min(DP[i][j-1],DP[i-1][j]),DP[i-1][j-1]);
                
            }
    
    for(int i=0;i<=m;i++)
    {
        cout<<"\n";
        for(int j=0;j<=n;j++)
            cout<<DP[i][j]<<"\t";
    }


    return DP[m][n];
}

void EditDriver()
{
    char str1[]="ABE";
    char str2[]="ACE";
    
    cout<<"\nNumber of Edits required : "<<EditProblem(str1,str2,(int)strlen(str1),(int)strlen(str2));
}


int count(int *S,int m,int n)
{
    int i, j, x, y;
    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    int table[m][n+1];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[i][0] = 1;
    
    // Fill rest of the table enteries in bottom up manner
    for (i = 0; i <m; i++)
    {
        for (j = 1; j <=n; j++)
        {
            if(j<S[i])
                x=0;
            else
                x=table[i][j-S[i]];
                           
            if(i>0)
                y=table[i-1][j];
            else
                y=0;
                           
            table[i][j] = x + y;
        }
    }
    
    for(int i=0;i<m;i++)
    {cout<<"\n";

        for(int j=0;j<=n;j++)
            cout<<table[i][j]<<"\t";
    }

    return table[m-1][n];
}

void CoinChangeDriver()
{
    int A[]={1,2,3};
    cout<<"Number of ways : "<<count(A,3,4);
}


/* Longest Palindromic Subsequence */
int lpsDP(char* str, int  n)
{
    int L[n][n];
    for(int i=0;i<n;i++)
        L[i][i]=1;
    
    for(int c1=2;c1<=n;c1++)
    {
        for(int i=0;i<=n-c1;i++)
        {
            int j=i+c1-1;
            if(str[i]==str[j] && c1==2)
                L[i][j]=2;
            else if (str[i]==str[j])
                L[i][j]=L[i+1][j-1]+2;
            else
                L[i][j]=max(L[i][j-1],L[i+1][j]);
        
        }
    }
    
    
    for(int i=0;i<n;i++)
    {cout<<"\n";
        
        for(int j=0;j<n;j++)
            cout<<L[i][j]<<"\t";
    }

    
    return L[0][n-1];
}

void LPSDriver()
{
    char seq[] = "ABAD"; //GEEKSFORGEEKS -5 BBABCBCAB -7 XHAX -3
    int n = (int)strlen(seq);
    int res = lpsDP(seq,n);
    
    cout<<"\n\nThe length of the LPS is (Memoization) "<<res;
   
}

int rodCut(int *price,int n)
{
    int val[n+1];
    val[0]=0;
    
    for(int len=1;len<=n;len++)
    {
        int maxVal=INT_MIN;
        for(int j=0;j<len;j++)
            maxVal=max(maxVal,price[j]+val[len-j-1]);
        
        val[len]=maxVal;
    }
    
    return val[n];
}

void rodCutDriver()
{
    int arr[]={1,5,8,9,10,17,17,20};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    int res=rodCut(arr,size);
    cout<<"Max Val : "<<res;

}


/* Kadane's Algorithm : Maximum Contiguous Sum */

int maxContSum(int *A,int n)
{
    
    int sum=0,maxSumSoFar=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum<0)
            sum=0;
        
        if(maxSumSoFar<sum)
            maxSumSoFar=sum;
    }
    
    return maxSumSoFar;

}

void MaxContSumDriver()
{
    int A[]={-2,-3,4,-1,-2,1,5,-3};
    int size=sizeof(A)/sizeof(A[0]);
    
    int res=maxContSum(A,size);
    
    cout<<"\nMax Contiguous Sum : "<<res;

}


int minSquare(int n)
{
    int DP[n+1];
    DP[0]=0;
    DP[1]=1;
    DP[2]=2;
    DP[3]=3;
    
    for(int i=4;i<=n;i++)
    {
        DP[i]=i;
        
        for(int x=1;x<=i;x++)
        {
            int t=x*x;
            if(t>n)
                break;
            
            DP[i]=min(DP[i],1+DP[i-t]);
            
        }
    
    }

    return DP[n];
}


void MinSquareDriver()
{
    cout<<"Min number of squares : "<<minSquare(6);

}

int minCoinsRecursive(int *A,int m,int V)
{
    if(V==0)
        return 0;
    
    int res=INT_MAX;
    
    for(int i=0;i<m;i++)
    {
        if(A[i]<=V){
            res=min(res,1+minCoinsRecursive(A,m,V-A[i]));
        }
    }

    return res;
}

int minCoinsIterative(int *A,int m,int V)
{
    if(V==0)
        return 0;
    
    int dp[V+1];
    dp[0]=0;
    
    for(int i=1;i<=V;i++)
        dp[i]=INT_MAX;
    
    for(int i=1;i<=V;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[j]<=i)
            {
                dp[i]=min(dp[i],1+dp[i-A[j]]);
                
            }
        
        }
    
    }
    
    return dp[V];
}

void minCoinDriver()
{
    int A[]={9,6,5,1};
    int m=sizeof(A)/sizeof(A[0]);
    
    int V=11;
    
    cout<<"Minimum Coins : "<<minCoinsRecursive(A,m,V);
    
    cout<<"\n\nMinimum Coins : "<<minCoinsIterative(A,m,V);
    
}


int maxLenPalindromeSubstring(char *str,int n)
{
    bool dp[n][n];
    int maxLen=1;
    
    for(int i=0;i<n;i++)
        dp[i][i]=true;
    
    for(int c=2;c<=n;c++)
    {
        for(int i=0;i<n-c+1;i++)
        {
            int j=i+c-1;
            
            if(str[i]==str[j] && c==2)
            {
                maxLen=2;
                dp[i][j]=true;
                continue;
            }
            
            if(str[i]==str[j] && dp[i+1][j-1])  // Next character with lower length (traceback)
            {
                dp[i][j]=true;
                if(maxLen<c)
                    maxLen=c;
                
                continue;
            }
        }
    }
    
    
    return maxLen;
}


void maxLenPalindromeSubstringDriver()
{
    char *str="abcbad";
    int size=(int)strlen(str);
    
    cout<<"\nMax Len of Substring : "<<maxLenPalindromeSubstring(str,size);

}


int maxLenPalindromeSubsequence(char *str,int n)
{
    int dp[n][n];
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    
    for(int c=2;c<=n;c++)
    {
        for(int i=0;i<n-c+1;i++)
        {
            int j=i+c-1;
            
            if(str[i]==str[j] && c==2)
                dp[i][j]=2;
            else
                if(str[i]==str[j])
                    dp[i][j]=2+dp[i+1][j-1];
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            
        }
    }
    
    return dp[0][n-1];

}



void maxLenPalindromeSubsequnceDriver()
{
    char str[]="dxxdabcbadzzd";
    int size=(int)strlen(str);
    
    cout<<"\nMax Len of Palindrome Subsequence : "<<maxLenPalindromeSubsequence(str,size);
}

int * arrayCopy(int const *A,int len)
{
    int *t = (int*)malloc(len*sizeof(int));
    memcpy(t,A,len*sizeof(int));
    return t;
}


void anagramInString(char *str1,char *str2)
{
    int m=(int)strlen(str1);
    int n=(int)strlen(str2);
    
    int mainletterCount[256]={0};
    for(int i=0;i<m;i++)
        mainletterCount[str1[i]]+=1;
    
    for(int i=0;i<n-m+1;i++)
    {
        int *letterCount=arrayCopy(mainletterCount,256);
        
        if(letterCount[str2[i]]>0)
        {   int j=0;
            
            for(;j<m;j++)
            {
                letterCount[str2[i+j]]-=1;
                if(letterCount[str2[i+j]]<0)
                    break;
            }
            
            if(j==m)
                cout<<"\nAnagram matches !";
        }
        
        delete [] letterCount;
    }
}

int compareArray(int *A,int *B)
{
    for(int i=0;i<256;i++)
        if(A[i]!=B[i])
            return 0;
    
    return 1;
}

void anagramInStringOptimized(char *str1,char *str2)
{
    int n=(int)strlen(str1);
    int m=(int)strlen(str2);
    
    int aPattern[256]={0};
    int aWindow[256]={0};
    
    for(int i=0;i<m;i++)
    {
        aPattern[str2[i]]++;
        aWindow[str1[i]]++;
    }
    
    for(int i=m;i<n;i++)
    {
        if(compareArray(aPattern,aWindow))
            cout<<"\nFound Anagram at : "<<i-m;
        
        aWindow[str1[i]]++;
        aWindow[str1[i-m]]--;
        
    }
    
    if(compareArray(aPattern,aWindow))
        cout<<"\nFound Anagram at : "<<n-m;

}


void anagramInStringDriver()
{
    char str1[]="abc";
    char str2[]="dacbecaeabc";
    
    anagramInString(str1,str2);
    
    cout<<"\nAnagram in String Optimized : ";
    anagramInStringOptimized(str2, str1);
    
}


void computeLPSArray(char *pat,int M,int *lps)
{
    int len=0;
    int i;
    
    lps[0]=0;
    i=1;
    
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }

}

void KMP(char *txt,char *pat)
{
    int N=(int)strlen(txt);
    int M=(int)strlen(pat);
    int lps[M];
    
    computeLPSArray(pat,M,lps);

    cout<<"\nLPS Array : ";
    for(int i=0;i<M;i++)
        cout<<lps[i]<<" ";
    
    int i=0;int j=0;
    
    while(i<N)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        
        if(j==M)
        {
            cout<<"\nFOUND at "<<i-j<<"!!!";
            j=lps[j-1];
            
        }
        
        if(txt[i]!=pat[j] && i<N)
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }

}

void KMPDriver()
{
    char str1[]="AABAACAABAA";
    char str2[]="AABA";
    
    KMP(str1,str2);
    
}



void nStairProblemDriver()
{
    int n=6;
    int m=3;
    
    int res[n];
    res[0]=0;
    res[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        res[i]=0;
        for(int j=1;j<=i && j<=m;j++)
        {
            res[i]+=res[i-j];
        }
    
    }
    
    cout<<"\nNumber of ways to get to step : "<<n<<" using : "<<m<<" possible jumps "<<res[n-1];

}



