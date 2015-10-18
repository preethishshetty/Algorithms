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



//Pointer and Reference Questions

//1) Function returns reference
// -- Since the variable is static - a refernce to it is made. The value 30 is stored into it.
int& test()
{
    static int x=10;
    return x;
}

//2) Swapping strings
// -- char* &str1 == Reference of type char* meaning refer to the passed variable
void swapStrings(char* &str1,char* &str2)
{
    char *temp=str1;
    str1=str2;
    str2=temp;
}

void PointerReferenceDriver()
{
    test()=30;
    cout<<"Value : "<<test();
    
    char *str1=(char*)"ABC";
    char *str2=(char*)"DEF";
    
    swapStrings(str1,str2);
    
    cout<<"\nStr1 : "<<str1;
    cout<<"\nStr2 : "<<str2;
    
    
    //Reference to NULL (fails)
    /*
    int *ptr=NULL; or int *ptr;
    int &ref=*ptr;
    cout<<"REF : "<<ref;
    */
}

class Test
{
private:
    int x;
    int y;
public:
    Test (int x = 0, int y = 0) { this->x = x; this->y = y; }
    Test setX(int a) { x = a; return *this; }
    Test setY(int b) { y = b; return *this; }
    //void change(Test *t) { *this = t; }   //Object is not assignable
    void destroy()  { delete this; }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

void thisPointerTestDriver()
{
    Test obj1;
    obj1.setX(10).setY(20);
    //obj1.destroy();
    obj1.print();
}


void fiboNormal(int N)
{
    int first=0;
    int second=1;
    
    cout<<"\nFibo Series : ";
    cout<<first<<" "<<second<<" ";
    
    for(int i=2;i<10;i++)
    {
        cout<<second+first<<" ";
        int t=second;
        second=second+first;
        first=t;
    }
    
}

int fiboRecursive(int N)
{
    if(N==0)
        return 0;
    else
        if(N==1)
            return 1;
        else
            return fiboRecursive(N-1)+fiboRecursive(N-2);
}

int fiboMemo(int N, int *dict)
{
    if(N<=0)
    {
        return 0;
    }
    else if(N==1)
        return 1;
    else
    {
        int f=dict[N];
        if(f==0)
        {   f=fiboMemo(N-1,dict)+fiboMemo(N-2,dict);
            dict[N]=f;
        }
        return f;
    }
    
    
}


void fibonacchiDriver()
{
    fiboNormal(10);
    
    cout<<"\nFibo Number : "<<fiboRecursive(6);
    
    int dictionary[10];
    for(int i=0;i<10;i++)
        dictionary[i]=0;
    
    cout<<"\nFibo Number Memoization : "<<fiboMemo(6,dictionary);
}


/* Finding Max Profit in scheduling jobs */

struct Job
 {
     int deadline;
     int profit;
     char id;
 };

void MaxProfitSequence(Job *job,int N)
{
    //sort(job);
    int result[N];
    int slot[N];
    for(int x=0;x<N;x++)
        slot[x]=-1;
    
    for(int i=0;i<N;i++)
    {
        for(int j=min(N,job[i].deadline);j>=0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=0;
                result[j]=i;
                break;
            }
        }
    }

    for(int k=0;k<N;k++)
    {
        cout<<"Time : "<<k<<" :  - JOB ID : "<<result[k];
    }
}

/* Currency Problem */

void CurrencyProblem(int Val)
{
    int list[] = {1,2,5,10,20,50,100,500,1000};
    int maxIndex=8;
    
    while(Val>0)
    {
        for(int i=maxIndex;i>=0;i--)
            if(list[i]<=Val)
            {
                maxIndex=i;
                break;
            }
        
        cout<<"\nx1 : "<<list[maxIndex];
        Val=Val-list[maxIndex];
    }

}


void CurrencyProbDriver()
{
    cout<<"For 125 : "<<"\n";
    CurrencyProblem(125);
    cout<<"\n\nFor 123 : "<<"\n";
    CurrencyProblem(123);
    cout<<"\n\nFor 93 : "<<"\n";
    CurrencyProblem(93);


}


/* Important Note on Pointers and reading it :
 
 The trick is to read the declaration backwards (right-to-left):
 
 const int a = 1; // read as "a is an integer which is constant"
 int const a = 1; // read as "a is a constant integer"
 
 Both are the same thing. Therefore:
 
 a = 2; // Can't do because a is constant
 The reading backwards trick especially comes in handy when you're dealing with more complex declarations such as:
 
 const char *s;      // read as "s is a pointer to a char that is constant"
 char c;
 char *const t = &c; // read as "t is a constant pointer to a char"
 
 *s = 'A'; // Can't do because the char is constant
 s++;      // Can do because the pointer isn't constant
 *t = 'A'; // Can do because the char isn't constant
 t++;      // Can't do because the pointer is constant

*/


