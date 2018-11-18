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
    double i,ans;
    double high,low,mid,last;
    while(cin >> p >> q >> r >> s >> t >> u)
    {
        high = 1.0001;
        low = 0;
        if(f(0) < -eps || f(1) > eps)
        {
            cout <<  "No solution" << endl;
            continue;
        }
        for(int i = 0;i < 100;i++)
        {
            //cout << "low = " << low/10000.0000 <<endl;
            //cout << "high = " << high/10000.0000 <<endl;
            mid = (high + low) / 2;
            //cout << "mid = " << mid/10000.0000 << endl;
            //printf("%.4lf\n",f(mid/10000.0000));
            if(f(mid) < 0)
            {

                    high = mid;
            }
            else
            {

                    low = mid;
            }


        }
        ans = mid;
        /*
        if(f(ans + 0.00005) * f(ans) > 0)
            ans += 0.0001;*/
        printf("%.4lf\n",ans);
        /*
        for(i = 0.0001;i <= 1;i += 0.0001)
        {
            if(f(i) * last < 0)
            {
                ans = i - 0.0001;
                break;
            }
            last = f(i);
        }
        if(f(ans + 0.00005) * f(ans) > 0)
            ans += 0.0001;
        if(ans != -1)
            printf("%.4lf\n",ans);
        else
            cout << "No solution" <<endl;
        */
    }

}

