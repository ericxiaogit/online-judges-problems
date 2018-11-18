#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int letters[26]= {1,2,3,5,6,19,22,34,35,37,66,78,90,102,105,161,197,218,291,320,421,2222,2443,2444,2511,2623};
int E[100000];


int main()
{
    int sum,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int W , N,M;
    int day,month,year,qy;
    int ans;
    trash = 0;
    int zero;
    int flag;
    int *p;
    string a;
    E[0] = 1;
    for(i = 1;i < 100000;i++)
    {
        E[i] =  i * E[i - 1];
        if(E[i] > 100000) break;
    }
    while(cin >> N)
    {

        p = lower_bound(E,E+i+1,N);
        ans = 0;
        while(N > 0)
        {
            ans += N / *p;
            N = N % *p;
            p--;
        }
        cout << ans << endl;
    }
}

