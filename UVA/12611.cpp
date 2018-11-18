#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
int A[15];

int main()
{
    //string a;
    int i,j,k;
    int x,y;
    int start_x,start_y;
    int T;
    long long int N,K,X;
    int a,b,c,d,e,f;
    int trash = 0;
    while(cin >> K)
    {
        for(i = 0;i < K;i++)
        {
            cin >> a;
            cout << "Case " << i+1 << ":" << endl;
            cout << (-45) * a/20 << " " << 1.5*a << endl;
            cout << (55) * a/20 << " " << 1.5*a << endl;
            cout << (55) * a/20 << " " << (-1.5)*a << endl;
            cout << (-45) * a/20 << " " << (-1.5)*a << endl;
        }
    }


}

