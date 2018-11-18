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
    int SZ,P,i,j,x,y,temp,k,a,b,N,trash,T;
    double t;
    int want;
    while(cin >>T)
    {
        for(i = 0;i < T;i++)
        {
            cin >> N;
            want = 1;
            for(j = 0;j < N;j++)
            {
                cin >> trash;
                if(trash == want)
                {
                    want ++;
                }
            }
            cout << "Case " << i + 1 << ": ";
            cout << N - want + 1<< endl;
        }
    }
}


