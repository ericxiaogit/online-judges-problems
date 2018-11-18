#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
char maps[105][105];
int visited[105][105];
long long int A[1000+5][1000+5];
int N,M;
void FILL(int x,int y)
{
    visited[x][y] = 1;
    if(y + 1 < N && maps[x][y + 1] == '@' && visited[x][y + 1] == 0)
    {
        FILL(x,y+1);
    }
    if(y - 1 >= 0 && maps[x][y - 1] == '@'&& visited[x][y - 1] == 0)
    {
        FILL(x,y-1);
    }
    if(x + 1 < M &&  maps[x +1][y] == '@'&& visited[x +1][y] == 0)
    {
        FILL(x +1,y);
    }
    if(x - 1 >= 0 &&  maps[x - 1][y] == '@'&& visited[x - 1][y] == 0)
    {
        FILL(x - 1,y);
    }
    if(y + 1 < N && x + 1 < M && maps[x + 1][y + 1] == '@'&& visited[x +1][y + 1] == 0)
    {
        FILL(x + 1,y+1);
    }
    if(y + 1 < N && x - 1 >= 0 && maps[x - 1][y + 1] == '@'&& visited[x - 1][y + 1] == 0)
    {
        FILL(x - 1,y+1);
    }
    if(y - 1 >= 0 && x - 1 >= 0 && maps[x - 1][y - 1] == '@'&& visited[x - 1][y - 1] == 0)
    {
        FILL(x - 1,y - 1);
    }
    if(y - 1 >= 0 && x + 1 < M && maps[x +1][y - 1] == '@'&& visited[x +1][y - 1] == 0)
    {
        FILL(x +1,y - 1);
    }
    return;
}
int main()
{
    unsigned long long int i,j,T,k;
    long long int a,b;
    long long int now,temp,ans;
    string x,y;
    now = 3;
    temp = 0;
    while(cin >> M >> N)
    {
        if(N == 0 && M == 0)
            break;
        ans = 0;
        for(i = 0;i < M;i++)
        {
            for(j = 0;j < N;j++)
            {
                cin >> maps[i][j];
                visited[i][j] = 0;
            }
        }
        for(i = 0;i < M;i++)
        {
            for(j = 0;j < N;j++)
            {
                if(maps[i][j] == '@' && visited[i][j] == 0)
                {
                    FILL(i,j);
                    ans ++;
                }


            }
        }
        cout << ans << endl;
    }





}

