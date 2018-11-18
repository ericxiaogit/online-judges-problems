#define MAX 2147483647
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
vector<int> to[20005];
vector<int> dis[20005];
int dist[20005];
int main()
{
    int i,c,d,j,t,K;
    int n , m , S , T,fromn,ton,distance,mi,minn;
    while(cin >> K)
    {
        for(i = 0;i < K;i++)
        {
            for(j = 0;j < 20005;j++)
            {
                to[j].clear();
                dis[j].clear();
                dist[j] = MAX;
            }
            cin >> n >> m >> S >> T;
            for(j = 0;j < m;j++)
            {
                cin >> fromn >> ton >> distance;
                to[fromn].push_back(ton);
                dis[fromn].push_back(distance);
                to[ton].push_back(fromn);
                dis[ton].push_back(distance);
            }
            dist[S] = 0;
            int now = S;
            while(dist[T] > 0)
            {
                /*
                for(j = 0;j < n;j++)
                {
                    cout << dist[j] << " ";
                }*/
                dist[now] = 0- dist[now];
                for(j = 0;j < to[now].size();j++)
                {
                    dist[to[now][j]] = min(0 - dist[now] + dis[now][j],dist[to[now][j]]);
                }
                now = 30000;
                minn = MAX;
                for(j = 0;j < n;j++)
                {
                    if(dist[j] < minn && dist[j] > 0)
                    {
                        now = j;
                        minn = dist[j];
                    }
                }
                if(now == 30000) break;

            }
            /*
            for(j = 0;j < n;j++)
            {
                cout << dist[j] << " ";
            }
            cout << endl;*/
            cout << "Case #" << i+1 << ": ";
            if(dist[T] == MAX)
            {
                cout << "unreachable" << endl;
            }
            else
                cout << abs(dist[T]) << endl;

        }

    }


}

