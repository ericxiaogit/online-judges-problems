#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#define MAX 2147483647
using namespace std;
struct dot
{
    double x,y;
};
double d(dot a,dot b)
{
    return sqrt((a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) ;
}
dot A[500];
double dist[500];
int main()
{
    double N;
    double mind,tt;
    int i,j = 0,now,K;
    while(cin >> N)
    {
        j++;
        if(N == 0) break;
        for(i = 0;i < N;i++)
        {
            cin >> A[i].x >> A[i].y;
            dist[i] = MAX;
        }
        now = 0;
        dist[0] = 0;
        while(dist[1] >= 0)
        {
            /*
            for(K = 0;K < N;K++)
            {
                cout << dist[K] << " ";
            }
            cout << endl;*/
            for(i = 0;i < N;i++)
            {
                if(i == now || dist[i]<0) continue;
                if(max(abs(dist[now]),d(A[now],A[i])) < dist[i])
                {
                    dist[i] = max(abs(dist[now]),d(A[now],A[i]));
                }
            }
            dist[now] = 0 - dist[now];
            mind = MAX;
            for(i = 1;i < N;i++)
            {
                if(dist[i] < mind && dist[i] > 0)
                {
                    now = i;
                    mind = dist[i];
                }

            }
            if(mind == MAX) break;
        }
        /*
        for(K = 0;K < N;K++)
        {
            cout << dist[K] << " ";
        }*/
        //cout <<endl;
        //cout << abs(dist[1]) <<endl;
        tt = abs(dist[1]);
        //cout << tt <<endl;
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",j,tt);

    }
}



