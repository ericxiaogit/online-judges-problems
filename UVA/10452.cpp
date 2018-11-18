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
char maps[10][10];
char vol[7] = {'I','E','H','O','V','A','#'};
string ans[100];
int main()
{
    int SZ,P,i,j,startx,starty,temp,k,a,b,N,M,trash,T,x,y;
    double t;
    int want;
    int last;
    int now;
    while(cin >>T)
    {
        for(k = 0;k < T;k++)
        {
            cin >> N >> M;
            for(i = 0;i < N;i++)
            {
                for(j = 0;j < M;j++)
                {
                    cin >> maps[i][j];
                    if(maps[i][j] == '@')
                    {
                        startx = i;
                        starty = j;
                    }
                }
            }
            x = startx;
            y = starty;
            now = 0;
            for(i = 0;i <7;i++)
            {
                if(maps[x][y] == '#') break;
                if(x + 1 < N && maps[x+1][y] ==  vol[now])
                {
                    x ++;
                    now++;
                    ans[now - 1] = "back";
                    continue;

                }
                if(x - 1 >= 0 && maps[x-1][y] ==  vol[now])
                {
                    x --;
                    now++;
                    ans[now - 1] = "forth";
                    continue;

                }
                if(y + 1 < M && maps[x][y+1] ==  vol[now])
                {
                    y ++;
                    now++;
                    ans[now - 1] = "right";
                    continue;

                }
                if(y - 1 >= 0 && maps[x][y - 1] ==  vol[now])
                {
                    y --;
                    now++;
                    ans[now - 1] = "left";
                    continue;

                }
            }
            //cout << now << endl;
            for(i = 0;i < 7;i++)
            {
                cout << ans[i];
                if(i != 6)
                    cout <<" ";
            }
            cout << endl;

        }
    }
}


