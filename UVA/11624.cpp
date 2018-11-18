#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
struct Place
{
    int x;
    int y;
    int what;//fire = 1 Jason = 0;
    int step;
    //string path;
};
Place que[10000000];
char maps[1005][1005];
int visited[1005][1005];

int main()
{
    double t;
    int even,odd,evans,i,j,k;
    int a,b;
    int trash;
    int R,N,angle;
    int head,tail;
    int startx,starty;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            head = 0;
            tail = 1;


            cin >> a >> b;
            for(j = 0;j < a;j++)
            {
                for(k = 0;k < b;k++)
                {
                    visited[j][k] = 0;
                    cin >> maps[j][k];
                    if(maps[j][k] == 'J')
                    {
                        que[0].x = j;
                        que[0].y = k;
                        que[0].what = 0;
                        que[0].step = 0;

                        visited[j][k] = 1;
                    }
                    else if(maps[j][k] == 'F')
                    {
                        que[tail].x = j;
                        que[tail].y = k;
                        que[tail].what = 1;
                        tail++;
                    }

                }
            }
            while(head < tail)
            {


                //cout << "head = " << head << endl;
                //cout << "tail = " << tail << endl;
                //if(que[head].what == 0)
                //cout << que[head].x << " " << que[head].y << " " << que[head].what << " " << que[head].step <<endl;


                //cout << maps[que[head].x ][que[head].y] << endl;
                //cout << visited[que[head].x ][que[head].y] <<endl;
                if(que[head].what == 0)
                {
                    //cout << "hello" << endl;
                    if(maps[que[head].x][que[head].y] == 'F')
                    {
                        head++;
                        //cout << "two" << endl;
                        continue;
                    }
                    if(que[head].x == 0 || que[head].y == 0 || que[head].x == a-1 || que[head].y == b-1)
                    {
                        //cout << "one" << endl;
                        break;
                    }
                    //cout << maps[que[head].x ][que[head].y] << endl;
                    //cout << visited[que[head].x ][que[head].y] <<endl;
                    if(maps[que[head].x +1][que[head].y] == '.' && visited[que[head].x +1][que[head].y] == 0)
                    {
                        //cout << "three" << endl;
                        que[tail].x = que[head].x +1;
                        que[tail].y = que[head].y;
                        que[tail].what = 0;
                        que[tail].step = que[head].step + 1;
                        visited[que[head].x +1][que[head].y] = 1;

                        tail++;

                    }
                    if(maps[que[head].x - 1][que[head].y] == '.' && visited[que[head].x -1][que[head].y] == 0)
                    {
                        //cout << "four" << endl;
                        que[tail].x = que[head].x - 1;
                        que[tail].y = que[head].y;
                        que[tail].what = 0;
                        que[tail].step = que[head].step + 1;
                        visited[que[head].x -1][que[head].y] = 1;

                        tail++;
                    }
                    if(maps[que[head].x][que[head].y +1] == '.' && visited[que[head].x][que[head].y +1] == 0)
                    {
                        //cout << "five" << endl;
                        que[tail].x = que[head].x;
                        que[tail].y = que[head].y + 1;
                        que[tail].what = 0;
                        que[tail].step = que[head].step + 1;
                        visited[que[head].x][que[head].y + 1] = 1;

                        tail++;
                    }
                    if(maps[que[head].x][que[head].y - 1] == '.' && visited[que[head].x][que[head].y - 1] == 0)
                    {
                        //cout << "six" << endl;
                        que[tail].x = que[head].x;
                        que[tail].y = que[head].y - 1;
                        que[tail].what = 0;
                        que[tail].step = que[head].step + 1;
                        visited[que[head].x][que[head].y - 1] = 1;

                        tail++;
                    }
                    head++;
                }
                else
                {
                    if(que[head].x +1 < a && maps[que[head].x +1][que[head].y] == '.')
                    {
                        maps[que[head].x +1][que[head].y] = 'F';
                        que[tail].x = que[head].x +1;
                        que[tail].y = que[head].y;
                        que[tail].what = 1;
                        tail++;
                    }
                    if(que[head].x - 1 >= 0 && maps[que[head].x - 1][que[head].y] == '.')
                    {
                        maps[que[head].x - 1][que[head].y] = 'F';
                        que[tail].x = que[head].x - 1;
                        que[tail].y = que[head].y;
                        que[tail].what = 1;
                        tail++;
                    }
                    if(que[head].y +1 < b && maps[que[head].x][que[head].y + 1] == '.')
                    {
                        maps[que[head].x][que[head].y +1] = 'F';
                        que[tail].x = que[head].x;
                        que[tail].y = que[head].y + 1;
                        que[tail].what = 1;
                        tail++;
                    }
                    if(que[head].y - 1 >= 0 && maps[que[head].x][que[head].y - 1] == '.')
                    {
                        maps[que[head].x][que[head].y - 1] = 'F';
                        que[tail].x = que[head].x;
                        que[tail].y = que[head].y - 1;
                        que[tail].what = 1;
                        tail++;
                    }
                    head++;
                }
            }
            if(head == tail)
                cout << "IMPOSSIBLE" <<endl;
            else
                cout << que[head].step + 1 <<endl;

        }
    }
}

