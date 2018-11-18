#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
    char p;
    //string a,t;
    long long int i,j;
    long long t,a,b;
    int N,M;
    int temp;

    while(cin >> N >> M)
    {
        if(N == -1 && M == -1) break;
        if(N > M)
            swap(N,M);
        cout << min(M - N,N + 100 - M) <<endl;
    }

}



