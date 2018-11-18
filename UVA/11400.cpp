#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int s[1000+5];
long long int d[1000+5];
struct bulb
{
    long long int V,K,C,L;
};
bulb A[1000 + 5];
bool cmp(const bulb &a,const bulb &b)
{
    return a.V < b.V;
}
int main()
{
    long long int N,i,j;
    while(cin >> N)
    {
        if(N == 0) break;
        for(i = 1;i <= N;i++)
        {
            cin >> A[i].V >> A[i].K >> A[i].C >> A[i].L;
        }
        sort(A+1,A+N+1,cmp);
        s[0] = 0;
        s[1] = A[1].L;
        for(i = 2;i <= N;i++)
        {
            s[i] = s[i - 1] + A[i].L;
            //cout << "i = " << i << " " << A[i].V << endl;
        }
        d[0] = 0;
        d[1] = A[1].L * (A[1].C) + A[1].K;
        for(i = 2;i <= N;i++)
        {
            d[i] = s[i]*A[i].C + A[i].K;
            for(j = 1;j < i;j++)
            {
                d[i] = min(d[i],d[j] + (s[i] - s[j])*(A[i].C) + A[i].K);
            }
        }
        /*
        for(i = 1;i <= N;i++)
        {
            cout << d[i] << " " << s[i] << endl;
        }
        cout << endl;*/
        cout << d[N] << endl;
    }
}

