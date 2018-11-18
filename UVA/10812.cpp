#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
int A[105][105];
int S[105][105];
using namespace std;
int main()
{
    int sum;
    int a,b;
    int N,i,k,j;
    double avg,temp;
    int ans,now,low;
    int fin;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> a >> b;
            ans = (a + b)/ 2;
            fin = (a - b)/2;
            if(ans < 0 || fin < 0)
                cout << "impossible" << endl;
            else if(ans + fin != a || ans - fin != b)
                cout << "impossible" << endl;
            else
                cout << ans << " " << fin << endl;
        }
    }

}



