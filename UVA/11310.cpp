#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
struct Case
{
    int num,day,fund;
};
long long int A[1000+5];
bool compare(const Case &a,const Case &b)
{
    int afirst = a.day * b.fund;
    int bfirst = b.day * a.fund;
    if(afirst == bfirst)
        return a.num < b.num;
    return afirst<bfirst;
}
int main()
{
    unsigned long long int i,j,T;
    long long int N;
    long long int now;
    A[1] = 1;
    A[2] = 5;
    A[3] = 11;
    now = 3;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >>T;
            for(j = now + 1;j <= T;j++)
            {
                A[j] = A[j-3] * 2 + A[j - 2] * 4 + A[j-1];
            }
            cout << A[T] << endl;
        }


    }
}

