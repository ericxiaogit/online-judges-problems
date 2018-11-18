#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int times[10000];
int length[50];
int songs[10000];
int main()
{
    int N,P,t,i,j,k;
    while(cin >> P)
    {
        for(i = 0;i < P;i++)
        {
            cin >> N >> t;
            for(j = 0;j < N;j++)
            {
                cin >> length[j];
            }
            for(j = 0;j < 10000;j++)
            {
                songs[j] = 0;
                times[j] = 0;
            }
            for(j = 0;j < N;j++)
            {
                for(k = t-1;k >= length[j];k--)
                {
                    if(songs[k] == songs[k-length[j]] + 1)
                    {
                        times[k] = max(times[k],times[k-length[j]] + length[j]);
                    }
                    else if(songs[k] < (songs[k-length[j]] + 1))
                    {
                        times[k] = times[k-length[j]] + length[j];
                        songs[k] = songs[k-length[j]] + 1;
                    }
                }
            }
            cout << "Case " << i+1 << ": ";
            cout << songs[t - 1] + 1 << " " << times[t-1] + 678 << endl;
         }
    }
}


