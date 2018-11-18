#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
long long int GCD(long long int p,long long int q)
{
    if(q == 0) return p;
    return GCD(q,p%q);
}
using namespace std;
int main()
{
    char p;
    //string a,t;
    long long int high,low,mid;
    long long int a,b,temp,i,ans,divide;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        ans = 1;
        divide = 1;
        if(b > a - b)
            b = a - b;
        for(i = 1;i <= b;i++)
        {
            ans *= (a - i + 1);
            divide *= (b - i + 1);
            temp = GCD(ans,divide);
            ans /= temp;
            divide /= temp;
        }
        cout << ans/divide << endl;
    }

}



