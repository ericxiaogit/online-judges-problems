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
            cin >> a;
            ans = (a*63 + 7492) * 5 - 498;
            if(ans < 0)
                ans = 0 - ans;
            cout << ((ans / 10) % 10) << endl;
        }
    }

}



