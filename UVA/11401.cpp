#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
long long int A[1000000 + 10];
using namespace std;
int main()
{
    char p;
    //string a,t;
    long long int N,i;
    double a,b;
    A[3] = 0;
    A[4] = 1;
    A[5] = 3;
    long long int temp;
    for(i = 6;i <= 1000000;i++)
    {
        temp = (i - 2)/2;
        A[i] = (A[i-1] - A[i - 2]) + temp  + A[i - 1];

    }
    while(cin >> N)
    {
        if(N < 3) break;
        cout << A[N] << endl;
    }

}



