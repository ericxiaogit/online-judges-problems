#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[1005];
int main()
{
    //string a;
    int num,N,i,how,temp,nows,j,a,big,print,ans,x,y,b;
    while(cin >> N)
    {
        if(N == 0)
            break;
        cin >> x >> y;
        for(i = 0;i < N;i++)
        {
            cin >> a >> b;
            if(a == x || b == y)
                cout << "divisa" << endl;
            else if(a > x  && b > y)
                cout << "NE" << endl;
            else if(a < x  && b > y)
                cout << "NO" << endl;
            else if(a < x  && b < y)
                cout << "SO" << endl;
            else
                cout << "SE" << endl;
        }
    }
}

