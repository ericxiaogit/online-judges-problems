#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int value[1005];
int weight[1005];
int people[100000];
int ans[40];
long long int recure(long long int B,long long int P,long long int M)
{
    //cout << P <<endl;
    //system("pause");
    if(P == 0)
    {
        return 1;
    }
    if(P == 1)
    {
        return B % M;
    }
    long long int temp = recure(B,P/3,M);
    if(P % 3 == 0)
    {
        //long long int temp = recure(B,P/2,M);
        return (temp * temp * temp) % M;
    }
    else if(P % 3 == 1)
    {
        return (temp * ((temp * B)% M) *temp) % M;
    }
    else
    {
        return (temp * ((temp * B)% M) *((temp * B)% M)) % M;
    }
}
int main()
{
    long long int i,j,T,k,big;
    long long int N,G;
    long long int now,temp;
    long long int a,b,c;
    now = 3;
    temp = 0;
    while(cin >> a >> b >> c)
    {
        cout << recure(a,b,c) << endl;

    }
}

