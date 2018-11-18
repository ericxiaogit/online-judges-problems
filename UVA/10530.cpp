#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int SZ,P,i,x,y,temp,high,low;
    double t;
    string L,M;
    char trash;
    high = 10;
    low = 1;
    while(1)
    {
        cin >> P;
        if(P== 0) break;
        cin >>L;
        cin >>M;
        if(L == "too" && M == "high")
        {
            if(P-1 < high)
                high = P - 1;
        }
        else if(L == "too" && M == "low")
        {
            if(P + 1 > low)
                low = P + 1;
        }
        else
        {
            if(P >= low && P <= high)
                cout << "Stan may be honest" << endl;
            else
                cout << "Stan is dishonest" << endl;
            high = 10;
            low = 1;
        }



    }
}

