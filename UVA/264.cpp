#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[100000];
int B[100000];
int main()
{
    int SZ,P,i,x,y,temp,k,a,b,N;
    double t;
    while(cin >> N)
    {
        temp = floor(sqrt(2 * N));
        if(((temp + 1) * temp)/2 < N)
            temp++;
        P = N - ((temp - 1) * temp)/2;
        if(temp % 2 == 1)
            P = temp - P + 1;
        //cout << temp << " " << P <<endl;
        a = P;
        b = temp + 1 - a;
        cout << "TERM " << N << " IS " <<  a << "/" << b << endl;
    }
}


