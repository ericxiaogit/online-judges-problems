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
    int SZ,P,i,j,ll;
    double t;
    int L,M,a,b,c,d;
    int even,odd,evans;
    int trash;
    int N;
    int ans;
    int high,low;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            high = 0;
            low = 0;
            cin >> M;
            cin >> trash;
            for(j = 1;j < M;j++)
            {
                cin >> a;
                if(a > trash)
                    high ++;
                else if(a < trash)
                    low ++;
                trash = a;
            }
            cout <<"Case " << i + 1 << ": ";
            cout << high << " " << low << endl;
        }

    }
}

