#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
long long int A[30000+5];
int temp;
int main()
{
    //string a;
    long long  num,i,how,nows,j,a,big,print,b,k;
    temp = -1;
    int N,M;
    string fron,bac;
    string trash;
    A[0] = 1;
    nows = 1;
    for(i = 1;i <= 30000;i++)
    {
        A[i] = A[i - 1];
    }
    for(i = 5;i <= 30000;i++)
    {
        A[i] += A[i - 5];
    }
    for(i = 10;i <= 30000;i++)
    {
        A[i] += A[i - 10];
    }
    for(i = 25;i <= 30000;i++)
    {
        A[i] += A[i - 25];
    }
    for(i = 50;i <= 30000;i++)
    {
        A[i] += A[i - 50];
    }
    while(cin >> N)
    {
        if(A[N] == 1)
            printf("There is only 1 way to produce %lld cents change.\n",N);
        else
            printf("There are %lld ways to produce %d cents change.\n",A[N],N);

    }


}

