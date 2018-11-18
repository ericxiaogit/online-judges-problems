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
    long long int N,B,H,W,ans,temp,price,i,j;
    while(cin >> N >> B >> H >> W)
    {
        ans = 0;
        for(i = 0;i < H;i++)
        {
            cin >> price;
            for(j = 0;j < W;j++)
            {
                cin >> temp;
                if(temp >= N)
                {
                    if(ans == 0 || N * price < ans)
                        ans = N*price;
                }
            }
        }
        if(ans <= B && ans > 0)
            cout << ans << endl;
        else
            cout << "stay home" << endl;

    }

}


