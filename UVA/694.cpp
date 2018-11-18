#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int A[1000+5][1000+5];
long long p ,q ,r ,s ,t ,u;
const double eps = 1e-14;
double f(double x)
{
    return(p * (exp(0 - x))+ q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}
int main()
{
    int i,ans;
    int high,low,mid,last;
    i = 0;
    while(cin >> p >> q)
    {
        i++;
        last = p;
        if(p < 0 && q < 0) break;
        ans = 0;
        while(1)
        {
            //cout << "p = " << p <<endl;
            if(p == 1) break;
            if(p > q) break;
            ans ++;
            if(p % 2 == 0)
                p = p/2;
            else
            {
                p = p *3 + 1;
            }

        }
        ans = ans + (p == 1);
        printf("Case %d: A = %d, limit = %lld, number of terms = %d\n",i,last,q,ans);
    }

}

