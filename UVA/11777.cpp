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
    int SZ,P,i,x,y,temp,k,N;
    int a,b,c,d,f,g,h;
    double e;
    double ans;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> a >> b >> c >> d >> h >> f >> g;
            e = (h + f + g - min(h,min(f,g)))/2;
            ans = a + b + c + d + e;
            //cout << ans << endl;
            cout << "Case " << i+1 << ": ";
            if(ans >= 90)
                cout << "A" << endl;
            else if(ans >= 80)
                cout << "B" << endl;
            else if(ans >= 70)
                cout << "C" << endl;
            else if(ans >= 60)
                cout << "D" << endl;
            else
                cout << "F" <<endl;
        }
    }
}


