#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <vector>
#define MAX 1000000
using namespace std;
int first[105][105];
int start[105][105];
int start2[105][105];
int second[105][105];
int minr[105];
vector<int> road[105];
vector<int> dist[105];
int main()
{
    int N,R,Q,i,j,k,a,b,c,t,M = 0;
    while(cin >> N >> R)
    {
        M++;
        for(i = 0;i < N;i++)
        {
            minr[i] = MAX;
        }
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < N;j++)
            {
                first[i][j] = MAX;
                start[i][j] = MAX;
                second[i][j] = MAX;
                if(i == j)
                    first[i][j] = 0;
            }
        }
        for(i = 0;i < R;i++)
        {
            cin >> a >> b >>c;
            first[a][b] = c;
            first[b][a] = c;
            start[a][b] = c;
            start[b][a] = c;
            if(minr[a] > c)
                c = minr[a];
            if(minr[b] >c)
                c = minr[b];
        }
        for(i = 0;i <N;i++)
        {
            for(j = 0;j < N;j++)
            {
                if(i == j)
                {
                    start[i][j] = minr[i] + minr[i];
                    start2[i][j] = minr[i] + minr[i];
                }
                else
                    start2[i][j] = start[i][j];
            }
        }
        for(k = 0;k < N;k++)
        {
            for(i = 0;i < N;i++)
            {
                for(j = 0;j < N;j++)
                {
                    if(first[i][k] + first[k][j] < first[i][j])
                    {
                        first[i][j] = first[i][k] + first[k][j];
                    }

                }
            }
        }
        for(k = 0;k < N;k++)
        {
            for(i = 0;i < N;i++)
            {
                for(j = 0;j < N;j++)
                {
                    if(start[i][k] + start[k][j] < second[i][j] && start[i][k] + start[k][j] > first[i][j])
                    {
                        second[i][j] = start[i][k] + start[k][j];
                    }
                    if(start[i][k] + start[k][j] < start[i][j])
                    {
                        start[i][j] = start[i][k] + start[k][j];
                    }
                }
            }
        }
        for(k = N-1;k >= 0;k--)
        {
            for(i = N-1;i >= 0;i--)
            {
                for(j = N-1;j >= 0;j--)
                {
                    if(start2[i][k] + start2[k][j] < second[i][j] && start2[i][k] + start2[k][j] > first[i][j])
                    {
                        second[i][j] = start2[i][k] + start2[k][j];
                    }
                    if(start2[i][k] + start2[k][j] < start2[i][j])
                    {
                        start2[i][j] = start2[i][k] + start2[k][j];
                    }
                }
            }
        }
        cin >> Q;
        cout << "Set #" << M << endl;
        for(i = 0;i < Q;i++)
        {
            cin >> a >> b;
            if(second[a][b] == MAX)
                cout << "?" << endl;
            else
                cout <<second[a][b] <<endl;
        }

    }
}



