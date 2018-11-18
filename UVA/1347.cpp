#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <cstring>
using namespace std;
#define SIZE 10000000
double x[1000];
double y[1000];
int N;
double ans[1000][1000];
double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double dp(int f,int b)
{
    if(f == N- 2)
    {
        return dist(x[N-2],y[N-2],x[N-1],y[N-1]) + dist(x[b],y[b],x[N -1],y[N-1]);
    }
    else if(ans[f][b] != -1)
    {
        return ans[f][b];
    }
    ans[f][b] = min(dp(f+1,b) + dist(x[f],y[f],x[f+1],y[f+1]),dp(f+1,f) + dist(x[b],y[b],x[f+1],y[f+1]));
    return ans[f][b];
}
int main()
{
    int i,j;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> x[i] >> y[i];
            for(j = 0;j < N;j++)
            {
                ans[i][j]  = -1;
            }
        }
        //cout << dp(0,0);
        double k = dp(0,0);
        cout << k << endl;
        printf("%.2f\n",k);
    }

}

