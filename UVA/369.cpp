#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
double A[100 + 5];

int main()
{
    int SZ,P,i,j,ll;
    double t;
    int even,odd,evans;
    int temp;
    int N,M;
    string trash;
    int flag;
    string str;
    A[0] = 1;
    for(i = 1;i <= 100;i++)
    {
        A[i] = A[i - 1] * i;
    }
    while(cin >> N >> M)
    {
        if(N == 0 && M == 0) break;
        printf("%d things taken %d at a time is %.0lf exactly.\n",N,M,A[N]/(A[N - M] * A[M]));
    }
}

