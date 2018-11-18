#define MAX 2147483647
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int T[10];
int temp[1000];
int ans[1000];
int ah[1000];
vector<int> to[1000];
vector<int> how[1000];
int main()
{
    int N,K,i,j,k,p;
    int mint,now;
    char trash;
    while(cin >> N >> K)
    {
        for(i = 0;i < N;i++)
        {
            cin >>T[i];
        }
        for(i = 0;i <= 100;i++)
        {
            ans[i] = MAX;
            ah[i] = 0;
            to[i].clear();
            how[i].clear();
        }
        for(i = 0;i < N;i++)
        {
            for(j = 0;j <= 100;j++)
            {
                cin >> temp[j];
                trash = cin.get();
                if(trash == '\n') break;
            }
            j++;
            for(k = 0;k <j;k++)
            {
                for(p = k + 1;p < j;p++)
                {
                    to[temp[k]].push_back(temp[p]);
                    how[temp[k]].push_back(i);
                    to[temp[p]].push_back(temp[k]);
                    how[temp[p]].push_back(i);
                }
            }
        }
        now = 0;
        ans[now] = 0;
        ah[now] = -1;
        while(ans[K] >= 0)
        {
            /*
            for(int o = 0;o <= 30;o++)
            {
                if(ans[o] != MAX)
                    cout <<o << ":  " << ans[o] << " ";
            }
            cout <<endl;*/
            for(i = 0;i < to[now].size();i++)
            {
                if(abs(ans[now])+T[how[now][i]]*abs(now - to[now][i])+(ah[now] != how[now][i] && ah[now] != -1)*60 < ans[to[now][i]])
                {
                    ans[to[now][i]] = abs(ans[now])+T[how[now][i]]*abs(now - to[now][i])+(ah[now] != how[now][i] && ah[now] != -1)*60;
                    ah[to[now][i]] = how[now][i];
                }
            }
            mint = MAX;

            for(i = 0;i < 100;i++)
            {
                if(ans[i] > 0 && ans[i] < mint)
                {
                    now = i;
                    mint = ans[i];
                }
            }

            if(mint == MAX) break;
            ans[now] = 0 - ans[now];
        }
        if(ans[K] == MAX)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << abs(ans[K]) <<endl;
        }
    }
}



