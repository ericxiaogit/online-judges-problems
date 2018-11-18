#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
struct Re
{
    int x;
    int y;
    int dir;
    int length;
};
Re father[10][10][4];
Re que[10000000];
int ansx[10000];
int ansy[10000];
int ans;
int visited[10][10][4];//0 E,1 S,2 W,3 N
int maps[10][10][4][4];
bool maze[10][10];//have or not
int use[26];//ESWN
int another[26];//RLF
using namespace std;
void DFS(int a,int b,int c)
{
    //cout << a << " " << b <<" " <<c << endl;
    //system("pause");
    ansx[ans] = a;
    ansy[ans] = b;
    ans ++;
    if(father[a][b][c].x == -1) return;
    DFS(father[a][b][c].x,father[a][b][c].y,father[a][b][c].dir);
}
int main()
{
    int i,j,startx,starty,endx,endy,k,p;
    char temp;
    int t;
    int xx,yy;
    int startdir;
    string trash;//t = trash[0]
    string name;
    int que_start,que_end;
    int no;//
    int nx,ny,ndir;
    another['R' - 'A'] = 1;
    another['L' - 'A'] = -1;
    another['F' - 'A'] = 0;
    use['E' - 'A'] = 0;
    use['S' - 'A'] = 1;
    use['W' - 'A'] = 2;
    use['N' - 'A'] = 3;
    while(cin >> name)
    {
        //turn to zero
        if(name == "END") break;
        for(i = 0;i < 10;i++)
        {
            for(j = 0;j <10;j++)
            {
                maze[i][j] = false;
                for(k = 0;k < 4;k++)
                {
                    father[i][j][k].x = -1;
                    father[i][j][k].y = -1;
                    father[i][j][k].dir = -1;
                    father[i][j][k].length= -1;
                    for(p = 0;p < 4;p++)
                    {
                        visited[i][j][k] = 0;
                        maps[i][j][k][p] = 0;
                    }
                }
            }
        }
        if(name == "end") break;
        cin >> startx >> starty >> temp >> endx >> endy;
        //maze[startx][starty] = true;
        maze[endx][endy] = true;
        que_start = 0;
        que_end = 0;
        startdir = use[temp - 'A'];
        father[startx][starty][startdir].x = -1;
        father[startx][starty][startdir].y = -1;
        father[startx][starty][startdir].dir = -1;
        while(cin >> xx)
        {
            if(xx == 0) break;
            cin >> yy;
            maze[xx][yy] = true;
            while(cin >> trash)
            {
                if(trash == "*") break;
                t = use[trash[0] - 'A'];
                for(i = 1;i < trash.length();i++)
                {
                    no = (t + 4 +another[trash[i] - 'A']) % 4;
                    maps[xx][yy][t][no] = 1;
                }
            }
        }
        que[0].x = startx;
        que[0].y = starty;
        que[0].dir = startdir;
        que[0].length = 0;
        que_end++;
        while(que_start < que_end)
        {
            nx = que[que_start].x;
            ny = que[que_start].y;
            //cout << que[que_start].x << " " << que[que_start].y << " " << que[que_start].dir << " " << que[que_start].length << endl;
            //system("pause");
            if(que[que_start].dir == 0)
                ny++;
            else if(que[que_start].dir == 1)
                nx++;
            else if(que[que_start].dir == 2)
                ny--;
            else if(que[que_start].dir == 3)
                nx--;
            if(nx == endx && ny == endy)
            {
                //cout << "hello" << endl;

                break;
            }
            if(nx <= 0 || ny <= 0 || nx > 9 || ny > 9 || maze[nx][ny] == false)
            {
                que_start++;
                continue;
            }
            if(visited[nx][ny][que[que_start].dir] == 0)
            {
                for(i = 0;i < 4;i++)
                {
                    if(maps[nx][ny][que[que_start].dir][i] == 1)
                    {
                        if(father[nx][ny][i].x != -1) continue;
                        que[que_end].x = nx;
                        que[que_end].y = ny;
                        que[que_end].dir = i;
                        que[que_end].length = que[que_start].length +1;
                        if(father[nx][ny][i].x != -1)
                        {
                            cout << "hello" << endl;
                            cout << "x = " << nx << " y = " << ny << " dir = " << i << endl;
                            cout << father[nx][ny][i].x << " " << father[nx][ny][i].y << " " << father[nx][ny][i].dir <<endl;
                            system("pause");
                        }
                        father[nx][ny][i] = que[que_start];
                        que_end++;
                    }
                }
                visited[nx][ny][que[que_start].dir] = 1;
            }
            que_start++;


        }
        cout << name <<endl;
        cout << "  ";
        if(que_start < que_end)
        {
            ans = 0 ;
            DFS(que[que_start].x,que[que_start].y,que[que_start].dir);
            //cout << "(" << startx << "," << starty << ") ";
            for(i = ans - 1;i >= 0;i--)
            {
                if((ans - i) % 10 == 0)
                {
                    cout << "(" << ansx[i] << "," << ansy[i] << ")";
                    cout <<endl;
                    cout << "  ";
                }
                else
                 cout << "(" << ansx[i] << "," << ansy[i] << ") ";
            }
            cout << "(" << endx << "," << endy << ")";
            cout <<endl;
        }
        //cout << que[que_start].length;
        else
            cout << "No Solution Possible" << endl;
    }
}


